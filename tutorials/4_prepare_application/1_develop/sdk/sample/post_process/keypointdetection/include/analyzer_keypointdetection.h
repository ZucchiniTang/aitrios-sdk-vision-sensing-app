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

#include "parson.h"

/* -------------------------------------------------------- */
/* define                                                   */
/* -------------------------------------------------------- */
#define PPL_ID_VERSION "00.01.01.00"            // Format: "AA.XX.YY.ZZ" where AA: ID, XX.YY.ZZ: Version
#define PPL_SSD_INPUT_TENSOR_WIDTH       (320)  // Derived from Custom Vision Object Detection Model on AITRIOS Console
#define PPL_SSD_INPUT_TENSOR_HEIGHT      (320)  // Derived from Custom Vision Object Detection Model on AITRIOS Console
#define PPL_DNN_OUTPUT_DETECTIONS        (2)   // Derived from Custom Vision Object Detection Model on AITRIOS Console
#define PPL_DEFAULT_THRESHOLD            (0.3)  // Default value
#define PPL_DNN_OUTPUT_TENSOR_SIZE(dnnOutputDetections)  ((dnnOutputDetections * 4) + dnnOutputDetections + (dnnOutputDetections * 3 * 17) )    // bbox(dnnOutputDetections*4) + scores(dnnOutputDetections)+ keypoint(dnnOutputDetections*3)*17

/* enum */
typedef enum {
    E_PPL_OK,
    E_PPL_INVALID_PARAM,
    E_PPL_E_MEMORY_ERROR,
    E_PPL_INVALID_STATE,
    E_PPL_OTHER
} EPPL_RESULT_CODE;

typedef struct tagPPL_SsdParam{
    uint16_t dnnOutputDetections;
    uint16_t maxDetections;
    float threshold;
    uint16_t inputWidth;
    uint16_t inputHeight;
} PPL_SsdParam;

EPPL_RESULT_CODE PPL_KeypointDetectionSsdAnalyze(float *p_data, uint32_t in_size, void **pp_out_buf, uint32_t *p_out_size, PPL_SsdParam ssd_param);
EPPL_RESULT_CODE json_parse(JSON_Value *root_value, PPL_SsdParam *p_ssd_param);
