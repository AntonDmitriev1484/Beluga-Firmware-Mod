// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from beluga_messages:msg/BelugaNeighbors.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "beluga_messages/msg/detail/beluga_neighbors__struct.hpp"
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

void BelugaNeighbors_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) beluga_messages::msg::BelugaNeighbors(_init);
}

void BelugaNeighbors_fini_function(void * message_memory)
{
  auto typed_message = static_cast<beluga_messages::msg::BelugaNeighbors *>(message_memory);
  typed_message->~BelugaNeighbors();
}

size_t size_function__BelugaNeighbors__neighbors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<beluga_messages::msg::BelugaNeighbor> *>(untyped_member);
  return member->size();
}

const void * get_const_function__BelugaNeighbors__neighbors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<beluga_messages::msg::BelugaNeighbor> *>(untyped_member);
  return &member[index];
}

void * get_function__BelugaNeighbors__neighbors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<beluga_messages::msg::BelugaNeighbor> *>(untyped_member);
  return &member[index];
}

void fetch_function__BelugaNeighbors__neighbors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const beluga_messages::msg::BelugaNeighbor *>(
    get_const_function__BelugaNeighbors__neighbors(untyped_member, index));
  auto & value = *reinterpret_cast<beluga_messages::msg::BelugaNeighbor *>(untyped_value);
  value = item;
}

void assign_function__BelugaNeighbors__neighbors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<beluga_messages::msg::BelugaNeighbor *>(
    get_function__BelugaNeighbors__neighbors(untyped_member, index));
  const auto & value = *reinterpret_cast<const beluga_messages::msg::BelugaNeighbor *>(untyped_value);
  item = value;
}

void resize_function__BelugaNeighbors__neighbors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<beluga_messages::msg::BelugaNeighbor> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BelugaNeighbors_message_member_array[1] = {
  {
    "neighbors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<beluga_messages::msg::BelugaNeighbor>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(beluga_messages::msg::BelugaNeighbors, neighbors),  // bytes offset in struct
    nullptr,  // default value
    size_function__BelugaNeighbors__neighbors,  // size() function pointer
    get_const_function__BelugaNeighbors__neighbors,  // get_const(index) function pointer
    get_function__BelugaNeighbors__neighbors,  // get(index) function pointer
    fetch_function__BelugaNeighbors__neighbors,  // fetch(index, &value) function pointer
    assign_function__BelugaNeighbors__neighbors,  // assign(index, value) function pointer
    resize_function__BelugaNeighbors__neighbors  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BelugaNeighbors_message_members = {
  "beluga_messages::msg",  // message namespace
  "BelugaNeighbors",  // message name
  1,  // number of fields
  sizeof(beluga_messages::msg::BelugaNeighbors),
  BelugaNeighbors_message_member_array,  // message members
  BelugaNeighbors_init_function,  // function to initialize message memory (memory has to be allocated)
  BelugaNeighbors_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BelugaNeighbors_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BelugaNeighbors_message_members,
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
get_message_type_support_handle<beluga_messages::msg::BelugaNeighbors>()
{
  return &::beluga_messages::msg::rosidl_typesupport_introspection_cpp::BelugaNeighbors_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, beluga_messages, msg, BelugaNeighbors)() {
  return &::beluga_messages::msg::rosidl_typesupport_introspection_cpp::BelugaNeighbors_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
