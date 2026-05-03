// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from beluga_messages:msg/BelugaRanges.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "beluga_messages/msg/detail/beluga_ranges__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace beluga_messages
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BelugaRanges_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) beluga_messages::msg::BelugaRanges(_init);
}

void BelugaRanges_fini_function(void * message_memory)
{
  auto typed_message = static_cast<beluga_messages::msg::BelugaRanges *>(message_memory);
  typed_message->~BelugaRanges();
}

size_t size_function__BelugaRanges__ranges(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<beluga_messages::msg::BelugaRange> *>(untyped_member);
  return member->size();
}

const void * get_const_function__BelugaRanges__ranges(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<beluga_messages::msg::BelugaRange> *>(untyped_member);
  return &member[index];
}

void * get_function__BelugaRanges__ranges(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<beluga_messages::msg::BelugaRange> *>(untyped_member);
  return &member[index];
}

void fetch_function__BelugaRanges__ranges(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const beluga_messages::msg::BelugaRange *>(
    get_const_function__BelugaRanges__ranges(untyped_member, index));
  auto & value = *reinterpret_cast<beluga_messages::msg::BelugaRange *>(untyped_value);
  value = item;
}

void assign_function__BelugaRanges__ranges(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<beluga_messages::msg::BelugaRange *>(
    get_function__BelugaRanges__ranges(untyped_member, index));
  const auto & value = *reinterpret_cast<const beluga_messages::msg::BelugaRange *>(untyped_value);
  item = value;
}

void resize_function__BelugaRanges__ranges(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<beluga_messages::msg::BelugaRange> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BelugaRanges_message_member_array[1] = {
  {
    "ranges",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<beluga_messages::msg::BelugaRange>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(beluga_messages::msg::BelugaRanges, ranges),  // bytes offset in struct
    nullptr,  // default value
    size_function__BelugaRanges__ranges,  // size() function pointer
    get_const_function__BelugaRanges__ranges,  // get_const(index) function pointer
    get_function__BelugaRanges__ranges,  // get(index) function pointer
    fetch_function__BelugaRanges__ranges,  // fetch(index, &value) function pointer
    assign_function__BelugaRanges__ranges,  // assign(index, value) function pointer
    resize_function__BelugaRanges__ranges  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BelugaRanges_message_members = {
  "beluga_messages::msg",  // message namespace
  "BelugaRanges",  // message name
  1,  // number of fields
  sizeof(beluga_messages::msg::BelugaRanges),
  BelugaRanges_message_member_array,  // message members
  BelugaRanges_init_function,  // function to initialize message memory (memory has to be allocated)
  BelugaRanges_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BelugaRanges_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BelugaRanges_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace beluga_messages


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<beluga_messages::msg::BelugaRanges>()
{
  return &::beluga_messages::msg::rosidl_typesupport_introspection_cpp::BelugaRanges_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, beluga_messages, msg, BelugaRanges)() {
  return &::beluga_messages::msg::rosidl_typesupport_introspection_cpp::BelugaRanges_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
