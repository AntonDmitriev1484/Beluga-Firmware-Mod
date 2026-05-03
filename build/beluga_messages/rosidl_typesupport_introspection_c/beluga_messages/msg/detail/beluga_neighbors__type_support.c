// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from beluga_messages:msg/BelugaNeighbors.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "beluga_messages/msg/detail/beluga_neighbors__rosidl_typesupport_introspection_c.h"
#include "beluga_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "beluga_messages/msg/detail/beluga_neighbors__functions.h"
#include "beluga_messages/msg/detail/beluga_neighbors__struct.h"


// Include directives for member types
// Member `neighbors`
#include "beluga_messages/msg/beluga_neighbor.h"
// Member `neighbors`
#include "beluga_messages/msg/detail/beluga_neighbor__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  beluga_messages__msg__BelugaNeighbors__init(message_memory);
}

void beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_fini_function(void * message_memory)
{
  beluga_messages__msg__BelugaNeighbors__fini(message_memory);
}

size_t beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__size_function__BelugaNeighbors__neighbors(
  const void * untyped_member)
{
  const beluga_messages__msg__BelugaNeighbor__Sequence * member =
    (const beluga_messages__msg__BelugaNeighbor__Sequence *)(untyped_member);
  return member->size;
}

const void * beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__get_const_function__BelugaNeighbors__neighbors(
  const void * untyped_member, size_t index)
{
  const beluga_messages__msg__BelugaNeighbor__Sequence * member =
    (const beluga_messages__msg__BelugaNeighbor__Sequence *)(untyped_member);
  return &member->data[index];
}

void * beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__get_function__BelugaNeighbors__neighbors(
  void * untyped_member, size_t index)
{
  beluga_messages__msg__BelugaNeighbor__Sequence * member =
    (beluga_messages__msg__BelugaNeighbor__Sequence *)(untyped_member);
  return &member->data[index];
}

void beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__fetch_function__BelugaNeighbors__neighbors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const beluga_messages__msg__BelugaNeighbor * item =
    ((const beluga_messages__msg__BelugaNeighbor *)
    beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__get_const_function__BelugaNeighbors__neighbors(untyped_member, index));
  beluga_messages__msg__BelugaNeighbor * value =
    (beluga_messages__msg__BelugaNeighbor *)(untyped_value);
  *value = *item;
}

void beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__assign_function__BelugaNeighbors__neighbors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  beluga_messages__msg__BelugaNeighbor * item =
    ((beluga_messages__msg__BelugaNeighbor *)
    beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__get_function__BelugaNeighbors__neighbors(untyped_member, index));
  const beluga_messages__msg__BelugaNeighbor * value =
    (const beluga_messages__msg__BelugaNeighbor *)(untyped_value);
  *item = *value;
}

bool beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__resize_function__BelugaNeighbors__neighbors(
  void * untyped_member, size_t size)
{
  beluga_messages__msg__BelugaNeighbor__Sequence * member =
    (beluga_messages__msg__BelugaNeighbor__Sequence *)(untyped_member);
  beluga_messages__msg__BelugaNeighbor__Sequence__fini(member);
  return beluga_messages__msg__BelugaNeighbor__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_message_member_array[1] = {
  {
    "neighbors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(beluga_messages__msg__BelugaNeighbors, neighbors),  // bytes offset in struct
    NULL,  // default value
    beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__size_function__BelugaNeighbors__neighbors,  // size() function pointer
    beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__get_const_function__BelugaNeighbors__neighbors,  // get_const(index) function pointer
    beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__get_function__BelugaNeighbors__neighbors,  // get(index) function pointer
    beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__fetch_function__BelugaNeighbors__neighbors,  // fetch(index, &value) function pointer
    beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__assign_function__BelugaNeighbors__neighbors,  // assign(index, value) function pointer
    beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__resize_function__BelugaNeighbors__neighbors  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_message_members = {
  "beluga_messages__msg",  // message namespace
  "BelugaNeighbors",  // message name
  1,  // number of fields
  sizeof(beluga_messages__msg__BelugaNeighbors),
  beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_message_member_array,  // message members
  beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_init_function,  // function to initialize message memory (memory has to be allocated)
  beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_message_type_support_handle = {
  0,
  &beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_beluga_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beluga_messages, msg, BelugaNeighbors)() {
  beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beluga_messages, msg, BelugaNeighbor)();
  if (!beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_message_type_support_handle.typesupport_identifier) {
    beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &beluga_messages__msg__BelugaNeighbors__rosidl_typesupport_introspection_c__BelugaNeighbors_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
