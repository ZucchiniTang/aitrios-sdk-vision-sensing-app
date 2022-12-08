/****************************************************************************
 * Copyright 2022 Sony Semiconductor Solutions Corp. All rights reserved.
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


// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CLASSIFICATION_SMARTCAMERA_H_
#define FLATBUFFERS_GENERATED_CLASSIFICATION_SMARTCAMERA_H_

#include "flatbuffers/flatbuffers.h"

namespace SmartCamera {

struct GeneralClassification;

struct ClassificationData;

struct ClassificationTop;

struct GeneralClassification FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CLASS_ID = 4,
    VT_SCORE = 6
  };
  uint32_t class_id() const {
    return GetField<uint32_t>(VT_CLASS_ID, 0);
  }
  float score() const {
    return GetField<float>(VT_SCORE, 0.0f);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_CLASS_ID) &&
           VerifyField<float>(verifier, VT_SCORE) &&
           verifier.EndTable();
  }
};

struct GeneralClassificationBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_class_id(uint32_t class_id) {
    fbb_.AddElement<uint32_t>(GeneralClassification::VT_CLASS_ID, class_id, 0);
  }
  void add_score(float score) {
    fbb_.AddElement<float>(GeneralClassification::VT_SCORE, score, 0.0f);
  }
  explicit GeneralClassificationBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GeneralClassificationBuilder &operator=(const GeneralClassificationBuilder &);
  flatbuffers::Offset<GeneralClassification> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GeneralClassification>(end);
    return o;
  }
};

inline flatbuffers::Offset<GeneralClassification> CreateGeneralClassification(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t class_id = 0,
    float score = 0.0f) {
  GeneralClassificationBuilder builder_(_fbb);
  builder_.add_score(score);
  builder_.add_class_id(class_id);
  return builder_.Finish();
}

struct ClassificationData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CLASSIFICATION_LIST = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<GeneralClassification>> *classification_list() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<GeneralClassification>> *>(VT_CLASSIFICATION_LIST);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CLASSIFICATION_LIST) &&
           verifier.VerifyVector(classification_list()) &&
           verifier.VerifyVectorOfTables(classification_list()) &&
           verifier.EndTable();
  }
};

struct ClassificationDataBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_classification_list(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<GeneralClassification>>> classification_list) {
    fbb_.AddOffset(ClassificationData::VT_CLASSIFICATION_LIST, classification_list);
  }
  explicit ClassificationDataBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ClassificationDataBuilder &operator=(const ClassificationDataBuilder &);
  flatbuffers::Offset<ClassificationData> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ClassificationData>(end);
    return o;
  }
};

inline flatbuffers::Offset<ClassificationData> CreateClassificationData(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<GeneralClassification>>> classification_list = 0) {
  ClassificationDataBuilder builder_(_fbb);
  builder_.add_classification_list(classification_list);
  return builder_.Finish();
}

inline flatbuffers::Offset<ClassificationData> CreateClassificationDataDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<GeneralClassification>> *classification_list = nullptr) {
  auto classification_list__ = classification_list ? _fbb.CreateVector<flatbuffers::Offset<GeneralClassification>>(*classification_list) : 0;
  return SmartCamera::CreateClassificationData(
      _fbb,
      classification_list__);
}

struct ClassificationTop FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PERCEPTION = 4
  };
  const ClassificationData *perception() const {
    return GetPointer<const ClassificationData *>(VT_PERCEPTION);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_PERCEPTION) &&
           verifier.VerifyTable(perception()) &&
           verifier.EndTable();
  }
};

struct ClassificationTopBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_perception(flatbuffers::Offset<ClassificationData> perception) {
    fbb_.AddOffset(ClassificationTop::VT_PERCEPTION, perception);
  }
  explicit ClassificationTopBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ClassificationTopBuilder &operator=(const ClassificationTopBuilder &);
  flatbuffers::Offset<ClassificationTop> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ClassificationTop>(end);
    return o;
  }
};

inline flatbuffers::Offset<ClassificationTop> CreateClassificationTop(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<ClassificationData> perception = 0) {
  ClassificationTopBuilder builder_(_fbb);
  builder_.add_perception(perception);
  return builder_.Finish();
}

inline const SmartCamera::ClassificationTop *GetClassificationTop(const void *buf) {
  return flatbuffers::GetRoot<SmartCamera::ClassificationTop>(buf);
}

inline const SmartCamera::ClassificationTop *GetSizePrefixedClassificationTop(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<SmartCamera::ClassificationTop>(buf);
}

inline bool VerifyClassificationTopBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<SmartCamera::ClassificationTop>(nullptr);
}

inline bool VerifySizePrefixedClassificationTopBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<SmartCamera::ClassificationTop>(nullptr);
}

inline void FinishClassificationTopBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<SmartCamera::ClassificationTop> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedClassificationTopBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<SmartCamera::ClassificationTop> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace SmartCamera

#endif  // FLATBUFFERS_GENERATED_CLASSIFICATION_SMARTCAMERA_H_
