// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_KEYPOINTDETECTION_SMARTCAMERA_H_
#define FLATBUFFERS_GENERATED_KEYPOINTDETECTION_SMARTCAMERA_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 21,
             "Non-compatible flatbuffers version included");

namespace SmartCamera {

struct BoundingBox2d;
struct BoundingBox2dBuilder;

struct Keypoint2d;
struct Keypoint2dBuilder;

struct Person;
struct PersonBuilder;

struct KeypointDetectionData;
struct KeypointDetectionDataBuilder;

struct KeypointDetectionTop;
struct KeypointDetectionTopBuilder;

struct BoundingBox2d FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef BoundingBox2dBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_X = 4,
    VT_Y = 6,
    VT_W = 8,
    VT_H = 10,
    VT_CONF = 12
  };
  int32_t x() const {
    return GetField<int32_t>(VT_X, 0);
  }
  int32_t y() const {
    return GetField<int32_t>(VT_Y, 0);
  }
  int32_t w() const {
    return GetField<int32_t>(VT_W, 0);
  }
  int32_t h() const {
    return GetField<int32_t>(VT_H, 0);
  }
  float conf() const {
    return GetField<float>(VT_CONF, 0.0f);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_X, 4) &&
           VerifyField<int32_t>(verifier, VT_Y, 4) &&
           VerifyField<int32_t>(verifier, VT_W, 4) &&
           VerifyField<int32_t>(verifier, VT_H, 4) &&
           VerifyField<float>(verifier, VT_CONF, 4) &&
           verifier.EndTable();
  }
};

struct BoundingBox2dBuilder {
  typedef BoundingBox2d Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_x(int32_t x) {
    fbb_.AddElement<int32_t>(BoundingBox2d::VT_X, x, 0);
  }
  void add_y(int32_t y) {
    fbb_.AddElement<int32_t>(BoundingBox2d::VT_Y, y, 0);
  }
  void add_w(int32_t w) {
    fbb_.AddElement<int32_t>(BoundingBox2d::VT_W, w, 0);
  }
  void add_h(int32_t h) {
    fbb_.AddElement<int32_t>(BoundingBox2d::VT_H, h, 0);
  }
  void add_conf(float conf) {
    fbb_.AddElement<float>(BoundingBox2d::VT_CONF, conf, 0.0f);
  }
  explicit BoundingBox2dBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<BoundingBox2d> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<BoundingBox2d>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<BoundingBox2d> CreateBoundingBox2d(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int32_t x = 0,
    int32_t y = 0,
    int32_t w = 0,
    int32_t h = 0,
    float conf = 0.0f) {
  BoundingBox2dBuilder builder_(_fbb);
  builder_.add_conf(conf);
  builder_.add_h(h);
  builder_.add_w(w);
  builder_.add_y(y);
  builder_.add_x(x);
  return builder_.Finish();
}

struct Keypoint2d FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef Keypoint2dBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_X = 4,
    VT_Y = 6,
    VT_CONF = 8
  };
  int32_t x() const {
    return GetField<int32_t>(VT_X, 0);
  }
  int32_t y() const {
    return GetField<int32_t>(VT_Y, 0);
  }
  float conf() const {
    return GetField<float>(VT_CONF, 0.0f);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_X, 4) &&
           VerifyField<int32_t>(verifier, VT_Y, 4) &&
           VerifyField<float>(verifier, VT_CONF, 4) &&
           verifier.EndTable();
  }
};

struct Keypoint2dBuilder {
  typedef Keypoint2d Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_x(int32_t x) {
    fbb_.AddElement<int32_t>(Keypoint2d::VT_X, x, 0);
  }
  void add_y(int32_t y) {
    fbb_.AddElement<int32_t>(Keypoint2d::VT_Y, y, 0);
  }
  void add_conf(float conf) {
    fbb_.AddElement<float>(Keypoint2d::VT_CONF, conf, 0.0f);
  }
  explicit Keypoint2dBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Keypoint2d> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Keypoint2d>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Keypoint2d> CreateKeypoint2d(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int32_t x = 0,
    int32_t y = 0,
    float conf = 0.0f) {
  Keypoint2dBuilder builder_(_fbb);
  builder_.add_conf(conf);
  builder_.add_y(y);
  builder_.add_x(x);
  return builder_.Finish();
}

struct Person FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PersonBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_BOUNDING_BOX = 4,
    VT_KEYPOINTS = 6
  };
  const SmartCamera::BoundingBox2d *bounding_box() const {
    return GetPointer<const SmartCamera::BoundingBox2d *>(VT_BOUNDING_BOX);
  }
  const ::flatbuffers::Vector<::flatbuffers::Offset<SmartCamera::Keypoint2d>> *keypoints() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<SmartCamera::Keypoint2d>> *>(VT_KEYPOINTS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_BOUNDING_BOX) &&
           verifier.VerifyTable(bounding_box()) &&
           VerifyOffset(verifier, VT_KEYPOINTS) &&
           verifier.VerifyVector(keypoints()) &&
           verifier.VerifyVectorOfTables(keypoints()) &&
           verifier.EndTable();
  }
};

struct PersonBuilder {
  typedef Person Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_bounding_box(::flatbuffers::Offset<SmartCamera::BoundingBox2d> bounding_box) {
    fbb_.AddOffset(Person::VT_BOUNDING_BOX, bounding_box);
  }
  void add_keypoints(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<SmartCamera::Keypoint2d>>> keypoints) {
    fbb_.AddOffset(Person::VT_KEYPOINTS, keypoints);
  }
  explicit PersonBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Person> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Person>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Person> CreatePerson(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<SmartCamera::BoundingBox2d> bounding_box = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<SmartCamera::Keypoint2d>>> keypoints = 0) {
  PersonBuilder builder_(_fbb);
  builder_.add_keypoints(keypoints);
  builder_.add_bounding_box(bounding_box);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Person> CreatePersonDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<SmartCamera::BoundingBox2d> bounding_box = 0,
    const std::vector<::flatbuffers::Offset<SmartCamera::Keypoint2d>> *keypoints = nullptr) {
  auto keypoints__ = keypoints ? _fbb.CreateVector<::flatbuffers::Offset<SmartCamera::Keypoint2d>>(*keypoints) : 0;
  return SmartCamera::CreatePerson(
      _fbb,
      bounding_box,
      keypoints__);
}

struct KeypointDetectionData FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef KeypointDetectionDataBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PERSONS = 4
  };
  const ::flatbuffers::Vector<::flatbuffers::Offset<SmartCamera::Person>> *persons() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<SmartCamera::Person>> *>(VT_PERSONS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_PERSONS) &&
           verifier.VerifyVector(persons()) &&
           verifier.VerifyVectorOfTables(persons()) &&
           verifier.EndTable();
  }
};

struct KeypointDetectionDataBuilder {
  typedef KeypointDetectionData Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_persons(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<SmartCamera::Person>>> persons) {
    fbb_.AddOffset(KeypointDetectionData::VT_PERSONS, persons);
  }
  explicit KeypointDetectionDataBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<KeypointDetectionData> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<KeypointDetectionData>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<KeypointDetectionData> CreateKeypointDetectionData(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<SmartCamera::Person>>> persons = 0) {
  KeypointDetectionDataBuilder builder_(_fbb);
  builder_.add_persons(persons);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<KeypointDetectionData> CreateKeypointDetectionDataDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<::flatbuffers::Offset<SmartCamera::Person>> *persons = nullptr) {
  auto persons__ = persons ? _fbb.CreateVector<::flatbuffers::Offset<SmartCamera::Person>>(*persons) : 0;
  return SmartCamera::CreateKeypointDetectionData(
      _fbb,
      persons__);
}

struct KeypointDetectionTop FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef KeypointDetectionTopBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PERCEPTION = 4
  };
  const SmartCamera::KeypointDetectionData *perception() const {
    return GetPointer<const SmartCamera::KeypointDetectionData *>(VT_PERCEPTION);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_PERCEPTION) &&
           verifier.VerifyTable(perception()) &&
           verifier.EndTable();
  }
};

struct KeypointDetectionTopBuilder {
  typedef KeypointDetectionTop Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_perception(::flatbuffers::Offset<SmartCamera::KeypointDetectionData> perception) {
    fbb_.AddOffset(KeypointDetectionTop::VT_PERCEPTION, perception);
  }
  explicit KeypointDetectionTopBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<KeypointDetectionTop> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<KeypointDetectionTop>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<KeypointDetectionTop> CreateKeypointDetectionTop(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<SmartCamera::KeypointDetectionData> perception = 0) {
  KeypointDetectionTopBuilder builder_(_fbb);
  builder_.add_perception(perception);
  return builder_.Finish();
}

inline const SmartCamera::KeypointDetectionTop *GetKeypointDetectionTop(const void *buf) {
  return ::flatbuffers::GetRoot<SmartCamera::KeypointDetectionTop>(buf);
}

inline const SmartCamera::KeypointDetectionTop *GetSizePrefixedKeypointDetectionTop(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<SmartCamera::KeypointDetectionTop>(buf);
}

inline bool VerifyKeypointDetectionTopBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<SmartCamera::KeypointDetectionTop>(nullptr);
}

inline bool VerifySizePrefixedKeypointDetectionTopBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<SmartCamera::KeypointDetectionTop>(nullptr);
}

inline void FinishKeypointDetectionTopBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<SmartCamera::KeypointDetectionTop> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedKeypointDetectionTopBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<SmartCamera::KeypointDetectionTop> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace SmartCamera

#endif  // FLATBUFFERS_GENERATED_KEYPOINTDETECTION_SMARTCAMERA_H_
