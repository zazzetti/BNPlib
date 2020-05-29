// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: output.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_output_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_output_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_output_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_output_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_output_2eproto;
class Par_Col;
class Par_ColDefaultTypeInternal;
extern Par_ColDefaultTypeInternal _Par_Col_default_instance_;
class Param;
class ParamDefaultTypeInternal;
extern ParamDefaultTypeInternal _Param_default_instance_;
class State;
class StateDefaultTypeInternal;
extern StateDefaultTypeInternal _State_default_instance_;
class UniqueValues;
class UniqueValuesDefaultTypeInternal;
extern UniqueValuesDefaultTypeInternal _UniqueValues_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Par_Col* Arena::CreateMaybeMessage<::Par_Col>(Arena*);
template<> ::Param* Arena::CreateMaybeMessage<::Param>(Arena*);
template<> ::State* Arena::CreateMaybeMessage<::State>(Arena*);
template<> ::UniqueValues* Arena::CreateMaybeMessage<::UniqueValues>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Par_Col :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Par_Col) */ {
 public:
  Par_Col();
  virtual ~Par_Col();

  Par_Col(const Par_Col& from);
  Par_Col(Par_Col&& from) noexcept
    : Par_Col() {
    *this = ::std::move(from);
  }

  inline Par_Col& operator=(const Par_Col& from) {
    CopyFrom(from);
    return *this;
  }
  inline Par_Col& operator=(Par_Col&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Par_Col& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Par_Col* internal_default_instance() {
    return reinterpret_cast<const Par_Col*>(
               &_Par_Col_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Par_Col& a, Par_Col& b) {
    a.Swap(&b);
  }
  inline void Swap(Par_Col* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Par_Col* New() const final {
    return CreateMaybeMessage<Par_Col>(nullptr);
  }

  Par_Col* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Par_Col>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Par_Col& from);
  void MergeFrom(const Par_Col& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Par_Col* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Par_Col";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_output_2eproto);
    return ::descriptor_table_output_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kElemsFieldNumber = 1,
  };
  // repeated double elems = 1;
  int elems_size() const;
  private:
  int _internal_elems_size() const;
  public:
  void clear_elems();
  private:
  double _internal_elems(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      _internal_elems() const;
  void _internal_add_elems(double value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      _internal_mutable_elems();
  public:
  double elems(int index) const;
  void set_elems(int index, double value);
  void add_elems(double value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      elems() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      mutable_elems();

  // @@protoc_insertion_point(class_scope:Par_Col)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double > elems_;
  mutable std::atomic<int> _elems_cached_byte_size_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_output_2eproto;
};
// -------------------------------------------------------------------

class Param :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Param) */ {
 public:
  Param();
  virtual ~Param();

  Param(const Param& from);
  Param(Param&& from) noexcept
    : Param() {
    *this = ::std::move(from);
  }

  inline Param& operator=(const Param& from) {
    CopyFrom(from);
    return *this;
  }
  inline Param& operator=(Param&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Param& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Param* internal_default_instance() {
    return reinterpret_cast<const Param*>(
               &_Param_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Param& a, Param& b) {
    a.Swap(&b);
  }
  inline void Swap(Param* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Param* New() const final {
    return CreateMaybeMessage<Param>(nullptr);
  }

  Param* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Param>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Param& from);
  void MergeFrom(const Param& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Param* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Param";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_output_2eproto);
    return ::descriptor_table_output_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kParColsFieldNumber = 1,
  };
  // repeated .Par_Col par_cols = 1;
  int par_cols_size() const;
  private:
  int _internal_par_cols_size() const;
  public:
  void clear_par_cols();
  ::Par_Col* mutable_par_cols(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Par_Col >*
      mutable_par_cols();
  private:
  const ::Par_Col& _internal_par_cols(int index) const;
  ::Par_Col* _internal_add_par_cols();
  public:
  const ::Par_Col& par_cols(int index) const;
  ::Par_Col* add_par_cols();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Par_Col >&
      par_cols() const;

  // @@protoc_insertion_point(class_scope:Param)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Par_Col > par_cols_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_output_2eproto;
};
// -------------------------------------------------------------------

class UniqueValues :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:UniqueValues) */ {
 public:
  UniqueValues();
  virtual ~UniqueValues();

  UniqueValues(const UniqueValues& from);
  UniqueValues(UniqueValues&& from) noexcept
    : UniqueValues() {
    *this = ::std::move(from);
  }

  inline UniqueValues& operator=(const UniqueValues& from) {
    CopyFrom(from);
    return *this;
  }
  inline UniqueValues& operator=(UniqueValues&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const UniqueValues& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const UniqueValues* internal_default_instance() {
    return reinterpret_cast<const UniqueValues*>(
               &_UniqueValues_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(UniqueValues& a, UniqueValues& b) {
    a.Swap(&b);
  }
  inline void Swap(UniqueValues* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline UniqueValues* New() const final {
    return CreateMaybeMessage<UniqueValues>(nullptr);
  }

  UniqueValues* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<UniqueValues>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const UniqueValues& from);
  void MergeFrom(const UniqueValues& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(UniqueValues* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "UniqueValues";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_output_2eproto);
    return ::descriptor_table_output_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kParamsFieldNumber = 1,
  };
  // repeated .Param params = 1;
  int params_size() const;
  private:
  int _internal_params_size() const;
  public:
  void clear_params();
  ::Param* mutable_params(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Param >*
      mutable_params();
  private:
  const ::Param& _internal_params(int index) const;
  ::Param* _internal_add_params();
  public:
  const ::Param& params(int index) const;
  ::Param* add_params();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Param >&
      params() const;

  // @@protoc_insertion_point(class_scope:UniqueValues)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Param > params_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_output_2eproto;
};
// -------------------------------------------------------------------

class State :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:State) */ {
 public:
  State();
  virtual ~State();

  State(const State& from);
  State(State&& from) noexcept
    : State() {
    *this = ::std::move(from);
  }

  inline State& operator=(const State& from) {
    CopyFrom(from);
    return *this;
  }
  inline State& operator=(State&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const State& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const State* internal_default_instance() {
    return reinterpret_cast<const State*>(
               &_State_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(State& a, State& b) {
    a.Swap(&b);
  }
  inline void Swap(State* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline State* New() const final {
    return CreateMaybeMessage<State>(nullptr);
  }

  State* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<State>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const State& from);
  void MergeFrom(const State& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(State* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "State";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_output_2eproto);
    return ::descriptor_table_output_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAllocationsFieldNumber = 1,
    kUniquevaluesFieldNumber = 2,
  };
  // repeated int32 allocations = 1;
  int allocations_size() const;
  private:
  int _internal_allocations_size() const;
  public:
  void clear_allocations();
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_allocations(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      _internal_allocations() const;
  void _internal_add_allocations(::PROTOBUF_NAMESPACE_ID::int32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      _internal_mutable_allocations();
  public:
  ::PROTOBUF_NAMESPACE_ID::int32 allocations(int index) const;
  void set_allocations(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_allocations(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      allocations() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_allocations();

  // repeated .UniqueValues uniquevalues = 2;
  int uniquevalues_size() const;
  private:
  int _internal_uniquevalues_size() const;
  public:
  void clear_uniquevalues();
  ::UniqueValues* mutable_uniquevalues(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::UniqueValues >*
      mutable_uniquevalues();
  private:
  const ::UniqueValues& _internal_uniquevalues(int index) const;
  ::UniqueValues* _internal_add_uniquevalues();
  public:
  const ::UniqueValues& uniquevalues(int index) const;
  ::UniqueValues* add_uniquevalues();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::UniqueValues >&
      uniquevalues() const;

  // @@protoc_insertion_point(class_scope:State)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > allocations_;
  mutable std::atomic<int> _allocations_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::UniqueValues > uniquevalues_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_output_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Par_Col

// repeated double elems = 1;
inline int Par_Col::_internal_elems_size() const {
  return elems_.size();
}
inline int Par_Col::elems_size() const {
  return _internal_elems_size();
}
inline void Par_Col::clear_elems() {
  elems_.Clear();
}
inline double Par_Col::_internal_elems(int index) const {
  return elems_.Get(index);
}
inline double Par_Col::elems(int index) const {
  // @@protoc_insertion_point(field_get:Par_Col.elems)
  return _internal_elems(index);
}
inline void Par_Col::set_elems(int index, double value) {
  elems_.Set(index, value);
  // @@protoc_insertion_point(field_set:Par_Col.elems)
}
inline void Par_Col::_internal_add_elems(double value) {
  elems_.Add(value);
}
inline void Par_Col::add_elems(double value) {
  _internal_add_elems(value);
  // @@protoc_insertion_point(field_add:Par_Col.elems)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
Par_Col::_internal_elems() const {
  return elems_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
Par_Col::elems() const {
  // @@protoc_insertion_point(field_list:Par_Col.elems)
  return _internal_elems();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
Par_Col::_internal_mutable_elems() {
  return &elems_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
Par_Col::mutable_elems() {
  // @@protoc_insertion_point(field_mutable_list:Par_Col.elems)
  return _internal_mutable_elems();
}

// -------------------------------------------------------------------

// Param

// repeated .Par_Col par_cols = 1;
inline int Param::_internal_par_cols_size() const {
  return par_cols_.size();
}
inline int Param::par_cols_size() const {
  return _internal_par_cols_size();
}
inline void Param::clear_par_cols() {
  par_cols_.Clear();
}
inline ::Par_Col* Param::mutable_par_cols(int index) {
  // @@protoc_insertion_point(field_mutable:Param.par_cols)
  return par_cols_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Par_Col >*
Param::mutable_par_cols() {
  // @@protoc_insertion_point(field_mutable_list:Param.par_cols)
  return &par_cols_;
}
inline const ::Par_Col& Param::_internal_par_cols(int index) const {
  return par_cols_.Get(index);
}
inline const ::Par_Col& Param::par_cols(int index) const {
  // @@protoc_insertion_point(field_get:Param.par_cols)
  return _internal_par_cols(index);
}
inline ::Par_Col* Param::_internal_add_par_cols() {
  return par_cols_.Add();
}
inline ::Par_Col* Param::add_par_cols() {
  // @@protoc_insertion_point(field_add:Param.par_cols)
  return _internal_add_par_cols();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Par_Col >&
Param::par_cols() const {
  // @@protoc_insertion_point(field_list:Param.par_cols)
  return par_cols_;
}

// -------------------------------------------------------------------

// UniqueValues

// repeated .Param params = 1;
inline int UniqueValues::_internal_params_size() const {
  return params_.size();
}
inline int UniqueValues::params_size() const {
  return _internal_params_size();
}
inline void UniqueValues::clear_params() {
  params_.Clear();
}
inline ::Param* UniqueValues::mutable_params(int index) {
  // @@protoc_insertion_point(field_mutable:UniqueValues.params)
  return params_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Param >*
UniqueValues::mutable_params() {
  // @@protoc_insertion_point(field_mutable_list:UniqueValues.params)
  return &params_;
}
inline const ::Param& UniqueValues::_internal_params(int index) const {
  return params_.Get(index);
}
inline const ::Param& UniqueValues::params(int index) const {
  // @@protoc_insertion_point(field_get:UniqueValues.params)
  return _internal_params(index);
}
inline ::Param* UniqueValues::_internal_add_params() {
  return params_.Add();
}
inline ::Param* UniqueValues::add_params() {
  // @@protoc_insertion_point(field_add:UniqueValues.params)
  return _internal_add_params();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Param >&
UniqueValues::params() const {
  // @@protoc_insertion_point(field_list:UniqueValues.params)
  return params_;
}

// -------------------------------------------------------------------

// State

// repeated int32 allocations = 1;
inline int State::_internal_allocations_size() const {
  return allocations_.size();
}
inline int State::allocations_size() const {
  return _internal_allocations_size();
}
inline void State::clear_allocations() {
  allocations_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 State::_internal_allocations(int index) const {
  return allocations_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::int32 State::allocations(int index) const {
  // @@protoc_insertion_point(field_get:State.allocations)
  return _internal_allocations(index);
}
inline void State::set_allocations(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  allocations_.Set(index, value);
  // @@protoc_insertion_point(field_set:State.allocations)
}
inline void State::_internal_add_allocations(::PROTOBUF_NAMESPACE_ID::int32 value) {
  allocations_.Add(value);
}
inline void State::add_allocations(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_add_allocations(value);
  // @@protoc_insertion_point(field_add:State.allocations)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
State::_internal_allocations() const {
  return allocations_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
State::allocations() const {
  // @@protoc_insertion_point(field_list:State.allocations)
  return _internal_allocations();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
State::_internal_mutable_allocations() {
  return &allocations_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
State::mutable_allocations() {
  // @@protoc_insertion_point(field_mutable_list:State.allocations)
  return _internal_mutable_allocations();
}

// repeated .UniqueValues uniquevalues = 2;
inline int State::_internal_uniquevalues_size() const {
  return uniquevalues_.size();
}
inline int State::uniquevalues_size() const {
  return _internal_uniquevalues_size();
}
inline void State::clear_uniquevalues() {
  uniquevalues_.Clear();
}
inline ::UniqueValues* State::mutable_uniquevalues(int index) {
  // @@protoc_insertion_point(field_mutable:State.uniquevalues)
  return uniquevalues_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::UniqueValues >*
State::mutable_uniquevalues() {
  // @@protoc_insertion_point(field_mutable_list:State.uniquevalues)
  return &uniquevalues_;
}
inline const ::UniqueValues& State::_internal_uniquevalues(int index) const {
  return uniquevalues_.Get(index);
}
inline const ::UniqueValues& State::uniquevalues(int index) const {
  // @@protoc_insertion_point(field_get:State.uniquevalues)
  return _internal_uniquevalues(index);
}
inline ::UniqueValues* State::_internal_add_uniquevalues() {
  return uniquevalues_.Add();
}
inline ::UniqueValues* State::add_uniquevalues() {
  // @@protoc_insertion_point(field_add:State.uniquevalues)
  return _internal_add_uniquevalues();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::UniqueValues >&
State::uniquevalues() const {
  // @@protoc_insertion_point(field_list:State.uniquevalues)
  return uniquevalues_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_output_2eproto