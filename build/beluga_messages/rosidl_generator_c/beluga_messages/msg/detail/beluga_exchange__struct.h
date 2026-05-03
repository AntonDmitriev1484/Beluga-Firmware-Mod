// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from beluga_messages:msg/BelugaExchange.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_EXCHANGE__STRUCT_H_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_EXCHANGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/BelugaExchange in the package beluga_messages.
typedef struct beluga_messages__msg__BelugaExchange
{
  uint16_t id;
  uint32_t exchange;
  builtin_interfaces__msg__Time timestamp;
} beluga_messages__msg__BelugaExchange;

// Struct for a sequence of beluga_messages__msg__BelugaExchange.
typedef struct beluga_messages__msg__BelugaExchange__Sequence
{
  beluga_messages__msg__BelugaExchange * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} beluga_messages__msg__BelugaExchange__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_EXCHANGE__STRUCT_H_
