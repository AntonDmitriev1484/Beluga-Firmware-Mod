// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from beluga_messages:msg/BelugaNeighbor.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBOR__STRUCT_H_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBOR__STRUCT_H_

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

/// Struct defined in msg/BelugaNeighbor in the package beluga_messages.
typedef struct beluga_messages__msg__BelugaNeighbor
{
  uint16_t id;
  float distance;
  int8_t rssi;
  uint32_t exchange;
  builtin_interfaces__msg__Time timestamp;
} beluga_messages__msg__BelugaNeighbor;

// Struct for a sequence of beluga_messages__msg__BelugaNeighbor.
typedef struct beluga_messages__msg__BelugaNeighbor__Sequence
{
  beluga_messages__msg__BelugaNeighbor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} beluga_messages__msg__BelugaNeighbor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBOR__STRUCT_H_
