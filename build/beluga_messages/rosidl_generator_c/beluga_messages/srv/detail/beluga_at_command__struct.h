// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from beluga_messages:srv/BelugaATCommand.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__STRUCT_H_
#define BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'AT_COMMAND_STARTUWB'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_STARTUWB = 0
};

/// Constant 'AT_COMMAND_STOPUWB'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_STOPUWB = 1
};

/// Constant 'AT_COMMAND_STARTBLE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_STARTBLE = 2
};

/// Constant 'AT_COMMAND_STOPBLE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_STOPBLE = 3
};

/// Constant 'AT_COMMAND_ID'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_ID = 4
};

/// Constant 'AT_COMMAND_BOOTMODE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_BOOTMODE = 5
};

/// Constant 'AT_COMMAND_RATE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_RATE = 6
};

/// Constant 'AT_COMMAND_CHANNEL'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_CHANNEL = 7
};

/// Constant 'AT_COMMAND_RESET'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_RESET = 8
};

/// Constant 'AT_COMMAND_TIMEOUT'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_TIMEOUT = 9
};

/// Constant 'AT_COMMAND_TXPOWER'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_TXPOWER = 10
};

/// Constant 'AT_COMMAND_STREAMMODE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_STREAMMODE = 11
};

/// Constant 'AT_COMMAND_TWRMODE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_TWRMODE = 12
};

/// Constant 'AT_COMMAND_LEDMODE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_LEDMODE = 13
};

/// Constant 'AT_COMMAND_REBOOT'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_REBOOT = 14
};

/// Constant 'AT_COMMAND_PWRAMP'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_PWRAMP = 15
};

/// Constant 'AT_COMMAND_ANTENNA'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_ANTENNA = 16
};

/// Constant 'AT_COMMAND_TIME'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_TIME = 17
};

/// Constant 'AT_COMMAND_DEEPSLEEP'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_DEEPSLEEP = 18
};

/// Constant 'AT_COMMAND_DATARATE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_DATARATE = 19
};

/// Constant 'AT_COMMAND_PREAMBLE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_PREAMBLE = 20
};

/// Constant 'AT_COMMAND_PULSERATE'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_PULSERATE = 21
};

/// Constant 'AT_COMMAND_PHR'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_PHR = 22
};

/// Constant 'AT_COMMAND_PAC'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_PAC = 23
};

/// Constant 'AT_COMMAND_SFD'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_SFD = 24
};

/// Constant 'AT_COMMAND_PANID'.
enum
{
  beluga_messages__srv__BelugaATCommand_Request__AT_COMMAND_PANID = 25
};

// Include directives for member types
// Member 'arg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BelugaATCommand in the package beluga_messages.
typedef struct beluga_messages__srv__BelugaATCommand_Request
{
  rosidl_runtime_c__String arg;
  uint8_t at_command;
} beluga_messages__srv__BelugaATCommand_Request;

// Struct for a sequence of beluga_messages__srv__BelugaATCommand_Request.
typedef struct beluga_messages__srv__BelugaATCommand_Request__Sequence
{
  beluga_messages__srv__BelugaATCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} beluga_messages__srv__BelugaATCommand_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BelugaATCommand in the package beluga_messages.
typedef struct beluga_messages__srv__BelugaATCommand_Response
{
  rosidl_runtime_c__String response;
} beluga_messages__srv__BelugaATCommand_Response;

// Struct for a sequence of beluga_messages__srv__BelugaATCommand_Response.
typedef struct beluga_messages__srv__BelugaATCommand_Response__Sequence
{
  beluga_messages__srv__BelugaATCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} beluga_messages__srv__BelugaATCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__STRUCT_H_
