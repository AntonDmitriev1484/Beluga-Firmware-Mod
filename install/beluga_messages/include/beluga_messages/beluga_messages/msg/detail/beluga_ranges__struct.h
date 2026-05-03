// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from beluga_messages:msg/BelugaRanges.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGES__STRUCT_H_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ranges'
#include "beluga_messages/msg/detail/beluga_range__struct.h"

/// Struct defined in msg/BelugaRanges in the package beluga_messages.
typedef struct beluga_messages__msg__BelugaRanges
{
  beluga_messages__msg__BelugaRange__Sequence ranges;
} beluga_messages__msg__BelugaRanges;

// Struct for a sequence of beluga_messages__msg__BelugaRanges.
typedef struct beluga_messages__msg__BelugaRanges__Sequence
{
  beluga_messages__msg__BelugaRanges * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} beluga_messages__msg__BelugaRanges__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGES__STRUCT_H_
