/****************************************************************************
 * Copyright 2023 Sony Semiconductor Solutions Corp. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <vector>

#include "vision_app_public.h"
#include "analyzer_keypointdetection.h"
#include "keypointdetection_generated.h"

extern pthread_mutex_t g_libc_mutex;

/* -------------------------------------------------------- */
/* define                                                   */
/* -------------------------------------------------------- */
#define PPL_DNN_OUTPUT_TENSOR_SIZE(dnnOutputDetections)  ((dnnOutputDetections * 4) + dnnOutputDetections + (dnnOutputDetections * 3 * 17) )    // bbox(dnnOutputDetections*4) + scores(dnnOutputDetections)+ keypoint(dnnOutputDetections*3)*17

/* -------------------------------------------------------- */
/* macro define                                             */
/* -------------------------------------------------------- */
#define PPL_ERR_PRINTF(fmt, ...) pthread_mutex_lock(&g_libc_mutex);fprintf(stderr, "E [VisionAPP] ");fprintf(stderr, fmt, ##__VA_ARGS__);fprintf(stderr, "\n");pthread_mutex_unlock(&g_libc_mutex);
#define PPL_WARN_PRINTF(fmt, ...) pthread_mutex_lock(&g_libc_mutex);fprintf(stderr, "W [VisionAPP] ");fprintf(stderr, fmt, ##__VA_ARGS__);fprintf(stderr, "\n");pthread_mutex_unlock(&g_libc_mutex);
#define PPL_INFO_PRINTF(fmt, ...) pthread_mutex_lock(&g_libc_mutex);fprintf(stdout, "I [VisionAPP] ");fprintf(stdout, fmt, ##__VA_ARGS__);fprintf(stdout, "\n");pthread_mutex_unlock(&g_libc_mutex);
#define PPL_DBG_PRINTF(fmt, ...) pthread_mutex_lock(&g_libc_mutex);printf( "D [VisionAPP] "); printf( fmt, ##__VA_ARGS__); printf( "\n");pthread_mutex_unlock(&g_libc_mutex);
#define PPL_VER_PRINTF(fmt, ...) pthread_mutex_lock(&g_libc_mutex);printf( "V [VisionAPP] "); printf( fmt, ##__VA_ARGS__); printf( "\n");pthread_mutex_unlock(&g_libc_mutex);

/* -------------------------------------------------------- */
/* structure                                                */
/* -------------------------------------------------------- */
typedef struct tagBbox {
    float x;
    float y;
    float w;
    float h;
    float conf;
} Bbox;

typedef struct tagKeypoint {
    float x;      
    float y;      
    float conf;   
} Keypoint;

typedef struct tagKeypointDetectionOutputTensor {
    uint8_t numOfPersons;
    std::vector<Bbox> bboxes;
    std::vector<std::vector<Keypoint>> keypoints;
} KeypointDetectionOutputTensor;

typedef struct tagPPL_Bbox {
    uint16_t    m_x;
    uint16_t    m_y;
    uint16_t    m_w;
    uint16_t    m_h;
    float m_conf;
} PPL_Bbox;

typedef struct tagPPL_Keypoint {
    uint16_t m_x;      
    uint16_t m_y;      
    float m_conf;   
} PPL_Keypoint;

typedef struct tagKeypointDetectionData {
    uint8_t numOfPersons;
    std::vector<PPL_Bbox> v_bbox;
    std::vector<std::vector<PPL_Keypoint>> v_keypoint;
} KeypointDetectionData;

/* -------------------------------------------------------- */
/* static                                                   */
/* -------------------------------------------------------- */
static int createKeypointDetectionData(float *data_body, uint32_t detect_num, KeypointDetectionOutputTensor *objectdetection_output);
static void analyzeKeypointDetectionSsdOutput(KeypointDetectionOutputTensor out_tensor, KeypointDetectionData *output_objectdetection_data, PPL_SsdParam ssd_param);
static void createSSDOutputFlatbuffer(flatbuffers::FlatBufferBuilder *builder, const KeypointDetectionData *ssdData);
static EPPL_RESULT_CODE PPL_ObjectDetectionSsdParamInit(JSON_Value *root_value, PPL_SsdParam *p_ssd_param);

/* -------------------------------------------------------- */
/* public function                                          */
/* -------------------------------------------------------- */
/**
 * @brief PPL_KeypointDetectionSsdAnalyze
 */
EPPL_RESULT_CODE PPL_KeypointDetectionSsdAnalyze(float *p_data, uint32_t in_size, void **pp_out_buf,  uint32_t *p_out_size, PPL_SsdParam ssd_param) {

    uint8_t *p_out_param = NULL;
    KeypointDetectionOutputTensor objectdetection_output;
    KeypointDetectionData output_objectdetection_data;

    PPL_DBG_PRINTF("PPL_KeypointDetectionSsdAnalyze");

    if (p_data == NULL) {
        PPL_ERR_PRINTF("PPL:Invalid param : pdata=NULL");
        return E_PPL_INVALID_PARAM;
    }

    if (in_size != (uint32_t)(PPL_DNN_OUTPUT_TENSOR_SIZE(ssd_param.dnnOutputDetections))) {
        PPL_ERR_PRINTF("PPL:Unexpected value for : in_size %d",in_size);
        PPL_ERR_PRINTF("PPL:Expected value for : in_size %d",(uint32_t)(PPL_DNN_OUTPUT_TENSOR_SIZE(ssd_param.dnnOutputDetections)));
        return E_PPL_INVALID_PARAM;
    }

    /* call interface process */
    int ret = createKeypointDetectionData(p_data, ssd_param.dnnOutputDetections, &objectdetection_output);
    if (ret != 0) {
        PPL_ERR_PRINTF("PPL: Error in createObjectDetectionData");
        return E_PPL_OTHER;
    }

    /* call analyze process */
    analyzeKeypointDetectionSsdOutput(objectdetection_output, &output_objectdetection_data, ssd_param);

    /* Serialize Data to FLatbuffers */ 
    pthread_mutex_lock(&g_libc_mutex);
    flatbuffers::FlatBufferBuilder* builder = new flatbuffers::FlatBufferBuilder();
    pthread_mutex_unlock(&g_libc_mutex);

    createSSDOutputFlatbuffer(builder,&output_objectdetection_data);

    pthread_mutex_lock(&g_libc_mutex);
    uint8_t* buf_ptr = builder->GetBufferPointer();
    pthread_mutex_unlock(&g_libc_mutex);

    if (buf_ptr == NULL) {
        PPL_ERR_PRINTF("Error could not create Flatbuffer");

        pthread_mutex_lock(&g_libc_mutex);
        builder->Clear();
        pthread_mutex_unlock(&g_libc_mutex);

        pthread_mutex_lock(&g_libc_mutex);
        delete(builder);
        pthread_mutex_unlock(&g_libc_mutex);

        return E_PPL_OTHER;
    }

    pthread_mutex_lock(&g_libc_mutex);
    uint32_t buf_size = builder->GetSize();
    pthread_mutex_unlock(&g_libc_mutex);

    pthread_mutex_lock(&g_libc_mutex);
    p_out_param = (uint8_t *)SessMalloc(buf_size);
    pthread_mutex_unlock(&g_libc_mutex);

    if (p_out_param == NULL) {
        PPL_ERR_PRINTF("malloc failed for creating flatbuffer, malloc size=%d", buf_size);
        pthread_mutex_lock(&g_libc_mutex);
        builder->Clear();
        pthread_mutex_unlock(&g_libc_mutex);

        pthread_mutex_lock(&g_libc_mutex);
        delete(builder);
        pthread_mutex_unlock(&g_libc_mutex);

        return E_PPL_E_MEMORY_ERROR;
    }
    PPL_DBG_PRINTF("p_out_param = %p", p_out_param);

    /* Copy Data */
    pthread_mutex_lock(&g_libc_mutex);
    memcpy(p_out_param, buf_ptr, buf_size);
    pthread_mutex_unlock(&g_libc_mutex);

    *pp_out_buf = p_out_param;
    *p_out_size = buf_size;

    //Clean up
    pthread_mutex_lock(&g_libc_mutex);
    builder->Clear();
    pthread_mutex_unlock(&g_libc_mutex);

    pthread_mutex_lock(&g_libc_mutex);
    delete(builder);
    pthread_mutex_unlock(&g_libc_mutex);

    return E_PPL_OK;
}

/**
 * json_parse: get json data from json_object and update in local struct
 * 
 * @param param Pointer to json string containing PPL specific parameters
 * @return Success or failure EPPL_RESULT_CODE
 */
EPPL_RESULT_CODE json_parse(JSON_Value *root_value, PPL_SsdParam *p_ssd_param) {
    PPL_DBG_PRINTF("PPL_Initialize: <json_parse>");
    return PPL_ObjectDetectionSsdParamInit(root_value, p_ssd_param);
}

/* -------------------------------------------------------- */
/* private function                                         */
/* -------------------------------------------------------- */
static EPPL_RESULT_CODE PPL_ObjectDetectionSsdParamInit(JSON_Value *root_value, PPL_SsdParam *p_ssd_param) {
    int ret;

    pthread_mutex_lock(&g_libc_mutex);
    ret = json_object_has_value(json_object(root_value),"dnn_output_detections");
    pthread_mutex_unlock(&g_libc_mutex);

    if (ret) {
        pthread_mutex_lock(&g_libc_mutex);
        uint16_t dnn_output_detections = json_object_get_number(json_object(root_value), "dnn_output_detections");
        pthread_mutex_unlock(&g_libc_mutex);

        PPL_DBG_PRINTF("PPL_ObjectDetectionParamInit dnn_output_detections: %d", dnn_output_detections);
        p_ssd_param->dnnOutputDetections = dnn_output_detections;
    } else {
        PPL_ERR_PRINTF("PPL_ObjectDetectionParamInit: json file does not have parameter \"dnn_output_detections\"");
        return E_PPL_INVALID_PARAM;
    }

    pthread_mutex_lock(&g_libc_mutex);
    ret = json_object_has_value(json_object(root_value),"max_detections");
    pthread_mutex_unlock(&g_libc_mutex);

    if (ret) {
        pthread_mutex_lock(&g_libc_mutex);
        uint16_t maxDetections = (int)json_object_get_number(json_object(root_value), "max_detections");
        pthread_mutex_unlock(&g_libc_mutex);

        PPL_DBG_PRINTF("PPL_ObjectDetectionParamInit max_detections: %d", maxDetections);
        if (maxDetections > p_ssd_param->dnnOutputDetections) {
            PPL_WARN_PRINTF("max_detections > max number of classes, set to max number of classes");
            p_ssd_param->maxDetections = p_ssd_param->dnnOutputDetections;
        } else {
            p_ssd_param->maxDetections = maxDetections;
        }
    } else {
        PPL_ERR_PRINTF("PPL_ObjectDetectionParamInit json file does not have max_detections");
        return E_PPL_INVALID_PARAM;
    }

    pthread_mutex_lock(&g_libc_mutex);
    json_object_has_value(json_object(root_value),"threshold");
    pthread_mutex_unlock(&g_libc_mutex);

    if (ret) {
        pthread_mutex_lock(&g_libc_mutex);
        float threshold = json_object_get_number(json_object(root_value), "threshold");
        pthread_mutex_unlock(&g_libc_mutex);

        PPL_DBG_PRINTF("PPL_ObjectDetectionParamInit threshold: %lf", threshold);
        if (threshold < 0.0 || threshold > 1.0) {
            PPL_WARN_PRINTF("threshold value out of range, set to default threshold");
            p_ssd_param->threshold = PPL_DEFAULT_THRESHOLD;
        } else {
            p_ssd_param->threshold = threshold;
        }
    } else {
        PPL_ERR_PRINTF("PPL_ObjectDetectionParamInit: json file does not have threshold");
        return E_PPL_INVALID_PARAM;
    }
    
    pthread_mutex_lock(&g_libc_mutex);
    ret = json_object_has_value(json_object(root_value),"input_width");
    pthread_mutex_unlock(&g_libc_mutex);

    if (ret) {
        pthread_mutex_lock(&g_libc_mutex);
        uint16_t input_width = json_object_get_number(json_object(root_value), "input_width");
        pthread_mutex_unlock(&g_libc_mutex);

        PPL_DBG_PRINTF("PPL_ObjectDetectionParamInit input_width: %d", input_width);
        p_ssd_param->inputWidth = input_width;
    } else {
        PPL_ERR_PRINTF("PPL_ObjectDetectionParamInit: json file does not have input_width");
        return E_PPL_INVALID_PARAM;
    }

    pthread_mutex_lock(&g_libc_mutex);
    ret = json_object_has_value(json_object(root_value),"input_height");
    pthread_mutex_unlock(&g_libc_mutex);

    if (ret) {
        pthread_mutex_lock(&g_libc_mutex);
        uint16_t input_height = json_object_get_number(json_object(root_value), "input_height");
        pthread_mutex_unlock(&g_libc_mutex);

        PPL_DBG_PRINTF("PPL_ObjectDetectionParamInit input_height: %d", input_height);
        p_ssd_param->inputHeight = input_height;
    } else {
        PPL_ERR_PRINTF("PPL_ObjectDetectionParamInit: json file does not have \"input_height\"");
        return E_PPL_INVALID_PARAM;
    }

    return E_PPL_OK;
}

/**
 * @brief createKeypointDetectionData
 */
static int createKeypointDetectionData(float *data_body, uint32_t detect_num, KeypointDetectionOutputTensor *objectdetection_output) {

    float* out_data = data_body;
    uint32_t count = 0;
    std::vector<Bbox> v_bbox;
    std::vector<std::vector<Keypoint>> v_keypoint;

    /* Extract number of Detections */
    uint8_t totalDetections = (uint8_t)detect_num;

    static const int KEYPOINT_COUNT  = 17;
    static const int FLOATS_PER_KP   = 3;   // (x, y, conf)
    static const int FLOATS_PER_BBOX = 5;   // (x, y, w, h, conf)

    int floatsPerDetection = FLOATS_PER_BBOX + KEYPOINT_COUNT * FLOATS_PER_KP;

    if ((count + (totalDetections * floatsPerDetection)) > PPL_DNN_OUTPUT_TENSOR_SIZE(detect_num)) {
        PPL_ERR_PRINTF("Invalid count index %d\n", count);
        return -1;
    }

    // Extract bounding box coordinates - keypoint
    for (uint8_t i = 0; i < totalDetections; i++) {
        // Calculate the base index for this detection
        int base = count + i * floatsPerDetection;
        
        // 1) BBox
        Bbox bbox;
        bbox.x = out_data[base + 0];     // bbox.x
        bbox.y = out_data[base + 1]; // bbox.y
        bbox.w     = out_data[base + 2]; // bbox.w
        bbox.h     = out_data[base + 3]; // bbox.h
        bbox.conf  = out_data[base + 4]; // bbox.conf
        pthread_mutex_lock(&g_libc_mutex);
        v_bbox.push_back(bbox);
        pthread_mutex_unlock(&g_libc_mutex);

        // 2) Keypoints
        std::vector<Keypoint> kps;
        kps.reserve(KEYPOINT_COUNT);
        int kpStart = base + FLOATS_PER_BBOX; // after the 5 bbox floats
        for (int kp_idx = 0; kp_idx < KEYPOINT_COUNT; kp_idx++)
        {
            int offset = kpStart + kp_idx * FLOATS_PER_KP;
            Keypoint kp;
            kp.x    = out_data[offset + 0];
            kp.y    = out_data[offset + 1];
            kp.conf = out_data[offset + 2];
            kps.push_back(kp);
        }
        pthread_mutex_lock(&g_libc_mutex);
        v_keypoint.push_back(kps);
        pthread_mutex_unlock(&g_libc_mutex);
    }
    count += (totalDetections * floatsPerDetection);

    pthread_mutex_lock(&g_libc_mutex);
    objectdetection_output->bboxes = v_bbox;
    pthread_mutex_unlock(&g_libc_mutex);

    pthread_mutex_lock(&g_libc_mutex);
    objectdetection_output->keypoints = v_keypoint;
    pthread_mutex_unlock(&g_libc_mutex);

    pthread_mutex_lock(&g_libc_mutex);
    objectdetection_output->numOfPersons = totalDetections;
    pthread_mutex_unlock(&g_libc_mutex);

    return 0;
}

/**
 * @brief analyzeKeypointDetectionSsdOutput
 */
static void analyzeKeypointDetectionSsdOutput(KeypointDetectionOutputTensor out_tensor, KeypointDetectionData *output_objectdetection_data, PPL_SsdParam ssd_param) {

    uint8_t num_of_detections;
    uint8_t detections_above_threshold = 0;
    std::vector<PPL_Bbox> v_bbox;
    std::vector<std::vector<PPL_Keypoint>> v_keypoint;
    KeypointDetectionData objectdetection_data;


    /* Extract number of detections */
    num_of_detections = (uint8_t)out_tensor.numOfPersons;

    for (uint8_t i = 0; i < num_of_detections; i++) {

        /* Extract scores */
        float score;

        pthread_mutex_lock(&g_libc_mutex);
        score = out_tensor.bboxes[i].conf;
        pthread_mutex_unlock(&g_libc_mutex);

        /* Filter Detections */
        if (score < ssd_param.threshold) {
            continue;
        } else {
            /* Extract bounding box co-ordinates and score */
            PPL_Bbox bbox;
            // x
            pthread_mutex_lock(&g_libc_mutex);
            bbox.m_x = static_cast<uint16_t>(round(out_tensor.bboxes[i].x * (ssd_param.inputWidth - 1)));
            pthread_mutex_unlock(&g_libc_mutex);
            // y
            pthread_mutex_lock(&g_libc_mutex);
            bbox.m_y = static_cast<uint16_t>(round(out_tensor.bboxes[i].y * (ssd_param.inputHeight - 1)));
            pthread_mutex_unlock(&g_libc_mutex);
            // w
            pthread_mutex_lock(&g_libc_mutex);
            bbox.m_w = static_cast<uint16_t>(round(out_tensor.bboxes[i].w * (ssd_param.inputWidth - 1)));
            pthread_mutex_unlock(&g_libc_mutex);
            // h
            pthread_mutex_lock(&g_libc_mutex);
            bbox.m_h = static_cast<uint16_t>(round(out_tensor.bboxes[i].h * (ssd_param.inputHeight - 1)));
            pthread_mutex_unlock(&g_libc_mutex);
            // conf
            pthread_mutex_lock(&g_libc_mutex);
            bbox.m_conf = out_tensor.bboxes[i].conf;
            pthread_mutex_unlock(&g_libc_mutex);

            // Push the new bbox to the vector
            pthread_mutex_lock(&g_libc_mutex);
            v_bbox.push_back(bbox);
            pthread_mutex_unlock(&g_libc_mutex);
            detections_above_threshold++;
            
            /* Extract keypoint co-ordinates */
            static const int NUM_KEYPOINTS = 17;
            std::vector<PPL_Keypoint> ppl_keypoints;

            for (int kp_idx = 0; kp_idx < NUM_KEYPOINTS; kp_idx++) {
                PPL_Keypoint kp;
                // x
                pthread_mutex_lock(&g_libc_mutex);
                kp.m_x = static_cast<uint16_t>(
                    round(out_tensor.keypoints[i][kp_idx].x * (ssd_param.inputWidth - 1))
                );
                pthread_mutex_unlock(&g_libc_mutex);
                // y
                pthread_mutex_lock(&g_libc_mutex);
                kp.m_y = static_cast<uint16_t>(
                    round(out_tensor.keypoints[i][kp_idx].y * (ssd_param.inputHeight - 1))
                );
                pthread_mutex_unlock(&g_libc_mutex);
                // conf
                pthread_mutex_lock(&g_libc_mutex);
                kp.m_conf = out_tensor.keypoints[i][kp_idx].conf;
                pthread_mutex_unlock(&g_libc_mutex);

                // Push the new keypoint to the vector
                pthread_mutex_lock(&g_libc_mutex);
                ppl_keypoints.push_back(kp);
                pthread_mutex_unlock(&g_libc_mutex);
            }

            pthread_mutex_lock(&g_libc_mutex);
            v_keypoint.push_back(ppl_keypoints);
            pthread_mutex_unlock(&g_libc_mutex);
        }
    }

    objectdetection_data.numOfPersons = detections_above_threshold;

    pthread_mutex_lock(&g_libc_mutex);
    objectdetection_data.v_bbox = v_bbox;
    pthread_mutex_unlock(&g_libc_mutex);

    pthread_mutex_lock(&g_libc_mutex);
    objectdetection_data.v_keypoint = v_keypoint;
    pthread_mutex_unlock(&g_libc_mutex);


    //objectdetection_data = getActualDetections(objectdetection_data);
    if (objectdetection_data.numOfPersons > ssd_param.maxDetections) {
        objectdetection_data.numOfPersons = ssd_param.maxDetections;

        pthread_mutex_lock(&g_libc_mutex);
        objectdetection_data.v_bbox.resize(ssd_param.maxDetections);
        pthread_mutex_unlock(&g_libc_mutex);

        pthread_mutex_lock(&g_libc_mutex);
        objectdetection_data.v_keypoint.resize(ssd_param.maxDetections);
        pthread_mutex_unlock(&g_libc_mutex);
    }

    output_objectdetection_data->numOfPersons = objectdetection_data.numOfPersons;

    pthread_mutex_lock(&g_libc_mutex);
    output_objectdetection_data->v_bbox = objectdetection_data.v_bbox;
    pthread_mutex_unlock(&g_libc_mutex);

    pthread_mutex_lock(&g_libc_mutex);
    output_objectdetection_data->v_keypoint = objectdetection_data.v_keypoint;
    pthread_mutex_unlock(&g_libc_mutex);

    PPL_DBG_PRINTF("number of Person = %d", objectdetection_data.numOfPersons);
    num_of_detections = objectdetection_data.numOfPersons;
    for (int i = 0; i < num_of_detections; i++) {
        pthread_mutex_lock(&g_libc_mutex);
        uint16_t x = objectdetection_data.v_bbox[i].m_x;
        pthread_mutex_unlock(&g_libc_mutex);

        pthread_mutex_lock(&g_libc_mutex);
        uint16_t y = objectdetection_data.v_bbox[i].m_y;
        pthread_mutex_unlock(&g_libc_mutex);

        pthread_mutex_lock(&g_libc_mutex);
        uint16_t w = objectdetection_data.v_bbox[i].m_w;
        pthread_mutex_unlock(&g_libc_mutex);

        pthread_mutex_lock(&g_libc_mutex);
        uint16_t h = objectdetection_data.v_bbox[i].m_h;
        pthread_mutex_unlock(&g_libc_mutex);

        pthread_mutex_lock(&g_libc_mutex);
        float conf = objectdetection_data.v_bbox[i].m_conf;
        pthread_mutex_unlock(&g_libc_mutex);

        PPL_DBG_PRINTF("v_bbox[%d] :[x,y,w,h,conf] = [%d,%d,%d,%d,%f]", i, x, y, w, h, conf);
    }

    for (int i = 0; i < num_of_detections; i++) {
        pthread_mutex_lock(&g_libc_mutex);
        int keypointCount = objectdetection_data.v_keypoint[i].size();
        pthread_mutex_unlock(&g_libc_mutex);
    
        for (int kp_idx = 0; kp_idx < keypointCount; kp_idx++) {
            pthread_mutex_lock(&g_libc_mutex);
            uint16_t x   = objectdetection_data.v_keypoint[i][kp_idx].m_x;
            uint16_t y   = objectdetection_data.v_keypoint[i][kp_idx].m_y;
            float    conf = objectdetection_data.v_keypoint[i][kp_idx].m_conf;
            pthread_mutex_unlock(&g_libc_mutex);
    
            // Print: Keypoints[i][kp_idx] -> (x, y, conf)
            PPL_DBG_PRINTF("keypoint[%d][%d]: [x,y,conf] = [%d, %d, %f]\n", 
                           i, kp_idx, x, y, conf);
        }
    }

    for (int i = 0; i < num_of_detections; i++) {
        pthread_mutex_lock(&g_libc_mutex);
        float score = objectdetection_data.v_bbox[i].m_conf;
        pthread_mutex_unlock(&g_libc_mutex);

        PPL_DBG_PRINTF("scores[%d] = %f", i, score);
    }
    return;
}

/* Function to serialize keypoint detection output tensor data into Flatbuffers.
*/
static void createSSDOutputFlatbuffer(flatbuffers::FlatBufferBuilder* builder, const KeypointDetectionData* kpdData) {
    std::vector<flatbuffers::Offset<SmartCamera::Person>> person_vector;

    PPL_DBG_PRINTF("createFlatbuffer");
    uint8_t numOfPersons = kpdData->numOfPersons;
    
    for (uint8_t i = 0; i < numOfPersons; i++) {
        PPL_DBG_PRINTF("Person %d: bbox(x=%d, y=%d, w=%d, h=%d, conf=%f)", i, 
            kpdData->v_bbox[i].m_x, 
            kpdData->v_bbox[i].m_y, 
            kpdData->v_bbox[i].m_w, 
            kpdData->v_bbox[i].m_h, 
            kpdData->v_bbox[i].m_conf);

        pthread_mutex_lock(&g_libc_mutex);
        auto bbox_data = SmartCamera::CreateBoundingBox2d(*builder, 
            kpdData->v_bbox[i].m_x,
            kpdData->v_bbox[i].m_y,
            kpdData->v_bbox[i].m_w,
            kpdData->v_bbox[i].m_h,
            kpdData->v_bbox[i].m_conf);
        pthread_mutex_unlock(&g_libc_mutex);

        std::vector<flatbuffers::Offset<SmartCamera::Keypoint2d>> keypoints_vector;
        
        for (uint8_t j = 0; j < 17; j++) {
            pthread_mutex_lock(&g_libc_mutex);
            auto keypoint = SmartCamera::CreateKeypoint2d(*builder, 
                kpdData->v_keypoint[i][j].m_x,
                kpdData->v_keypoint[i][j].m_y,
                kpdData->v_keypoint[i][j].m_conf);
            pthread_mutex_unlock(&g_libc_mutex);
            
            keypoints_vector.push_back(keypoint);
        }
        
        pthread_mutex_lock(&g_libc_mutex);
        auto keypoints_fb = builder->CreateVector(keypoints_vector);
        pthread_mutex_unlock(&g_libc_mutex);

        pthread_mutex_lock(&g_libc_mutex);
        auto person_data = SmartCamera::CreatePerson(*builder, bbox_data, keypoints_fb);
        pthread_mutex_unlock(&g_libc_mutex);
        
        pthread_mutex_lock(&g_libc_mutex);
        person_vector.push_back(person_data);
        pthread_mutex_unlock(&g_libc_mutex);
    }

    pthread_mutex_lock(&g_libc_mutex);
    auto persons_fb = builder->CreateVector(person_vector);
    pthread_mutex_unlock(&g_libc_mutex);

    pthread_mutex_lock(&g_libc_mutex);
    auto kd_data = SmartCamera::CreateKeypointDetectionData(*builder, persons_fb);
    pthread_mutex_unlock(&g_libc_mutex);

    pthread_mutex_lock(&g_libc_mutex);
    auto out_data = SmartCamera::CreateKeypointDetectionTop(*builder, kd_data);
    pthread_mutex_unlock(&g_libc_mutex);

    pthread_mutex_lock(&g_libc_mutex);
    builder->Finish(out_data);
    pthread_mutex_unlock(&g_libc_mutex);

    return;
}