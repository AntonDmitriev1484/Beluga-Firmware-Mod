// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from beluga_messages:srv/BelugaATCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "beluga_messages/srv/detail/beluga_at_command__rosidl_typesupport_introspection_c.h"
#include "beluga_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "beluga_messages/srv/detail/beluga_at_command__functions.h"
#include "beluga_messages/srv/detail/beluga_at_command__struct.h"


// Include directives for member types
// Member `arg`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  beluga_messages__srv__BelugaATCommand_Request__init(message_memory);
}

void beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_fini_function(void * message_memory)
{
  beluga_messages__srv__BelugaATCommand_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_message_member_array[2] = {
  {
    "arg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(beluga_messages__srv__BelugaATCommand_Request, arg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "at_command",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(beluga_messages__srv__BelugaATCommand_Request, at_command),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_message_members = {
  "beluga_messages__srv",  // message namespace
  "BelugaATCommand_Request",  // message name
  2,  // number of fields
  sizeof(beluga_messages__srv__BelugaATCommand_Request),
  beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_message_member_array,  // message members
  beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_message_type_support_handle = {
  0,
  &beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_beluga_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beluga_messages, srv, BelugaATCommand_Request)() {
  if (!beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_message_type_support_handle.typesupport_identifier) {
    beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &beluga_messages__srv__BelugaATCommand_Request__rosidl_typesupport_introspection_c__BelugaATCommand_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "beluga_messages/srv/detail/beluga_at_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "beluga_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "beluga_messages/srv/detail/beluga_at_command__functions.h"
// already included above
// #include "beluga_messages/srv/detail/beluga_at_command__struct.h"


// Include directives for member types
// Member `response`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  beluga_messages__srv__BelugaATCommand_Response__init(message_memory);
}

void beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_fini_function(void * message_memory)
{
  beluga_messages__srv__BelugaATCommand_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_message_member_array[1] = {
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(beluga_messages__srv__BelugaATCommand_Response, response),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_message_members = {
  "beluga_messages__srv",  // message namespace
  "BelugaATCommand_Response",  // message name
  1,  // number of fields
  sizeof(beluga_messages__srv__BelugaATCommand_Response),
  beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_message_member_array,  // message members
  beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_message_type_support_handle = {
  0,
  &beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_beluga_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beluga_messages, srv, BelugaATCommand_Response)() {
  if (!beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_message_type_support_handle.typesupport_identifier) {
    beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &beluga_messages__srv__BelugaATCommand_Response__rosidl_typesupport_introspection_c__BelugaATCommand_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "beluga_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "beluga_messages/srv/detail/beluga_at_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers beluga_messages__srv__detail__beluga_at_command__rosidl_typesupport_introspection_c__BelugaATCommand_service_members = {
  "beluga_messages__srv",  // service namespace
  "BelugaATCommand",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // beluga_messages__srv__detail__beluga_at_command__rosidl_typesupport_introspection_c__BelugaATCommand_Request_message_type_support_handle,
  NULL  // response message
  // beluga_messages__srv__detail__beluga_at_command__rosidl_typesupport_introspection_c__BelugaATCommand_Response_message_type_support_handle
};

static rosidl_service_type_support_t beluga_messages__srv__detail__beluga_at_command__rosidl_typesupport_introspection_c__BelugaATCommand_service_type_support_handle = {
  0,
  &beluga_messages__srv__detail__beluga_at_command__rosidl_typesupport_introspection_c__BelugaATCommand_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beluga_messages, srv, BelugaATCommand_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beluga_messages, srv, BelugaATCommand_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_beluga_messages
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beluga_messages, srv, BelugaATCommand)() {
  if (!beluga_messages__srv__detail__beluga_at_command__rosidl_typesupport_introspection_c__BelugaATCommand_service_type_support_handle.typesupport_identifier) {
    beluga_messages__srv__detail__beluga_at_command__rosidl_typesupport_introspection_c__BelugaATCommand_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)beluga_messages__srv__detail__beluga_at_command__rosidl_typesupport_introspection_c__BelugaATCommand_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beluga_messages, srv, BelugaATCommand_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beluga_messages, srv, BelugaATCommand_Response)()->data;
  }

  return &beluga_messages__srv__detail__beluga_at_command__rosidl_typesupport_introspection_c__BelugaATCommand_service_type_support_handle;
}
