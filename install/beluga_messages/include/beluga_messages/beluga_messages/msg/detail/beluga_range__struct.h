// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from beluga_messages:msg/BelugaRange.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__STRUCT_H_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__STRUCT_H_

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

/// Struct defined in msg/BelugaRange in the package beluga_messages.
typedef struct beluga_messages__msg__BelugaRange
{
  uint16_t id;
  float range;
  uint32_t exchange;
  builtin_interfaces__msg__Time timestamp;
  uint16_t maxnoise;
  uint16_t firstpathamp1;
  uint16_t firstpathamp2;
  uint16_t firstpathamp3;
  uint16_t stdnoise;
  uint16_t maxgrowthcir;
  uint16_t rxpreamcount;
  uint16_t firstpath;
} beluga_messages__msg__BelugaRange;

// Struct for a sequence of beluga_messages__msg__BelugaRange.
typedef struct beluga_messages__msg__BelugaRange__Sequence
{
  beluga_messages__msg__BelugaRange * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} beluga_messages__msg__BelugaRange__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__STRUCT_H_
