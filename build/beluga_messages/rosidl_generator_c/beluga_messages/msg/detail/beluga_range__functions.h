// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from beluga_messages:msg/BelugaRange.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__FUNCTIONS_H_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "beluga_messages/msg/rosidl_generator_c__visibility_control.h"

#include "beluga_messages/msg/detail/beluga_range__struct.h"

/// Initialize msg/BelugaRange message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * beluga_messages__msg__BelugaRange
 * )) before or use
 * beluga_messages__msg__BelugaRange__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__msg__BelugaRange__init(beluga_messages__msg__BelugaRange * msg);

/// Finalize msg/BelugaRange message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__msg__BelugaRange__fini(beluga_messages__msg__BelugaRange * msg);

/// Create msg/BelugaRange message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * beluga_messages__msg__BelugaRange__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
beluga_messages__msg__BelugaRange *
beluga_messages__msg__BelugaRange__create();

/// Destroy msg/BelugaRange message.
/**
 * It calls
 * beluga_messages__msg__BelugaRange__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__msg__BelugaRange__destroy(beluga_messages__msg__BelugaRange * msg);

/// Check for msg/BelugaRange message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__msg__BelugaRange__are_equal(const beluga_messages__msg__BelugaRange * lhs, const beluga_messages__msg__BelugaRange * rhs);

/// Copy a msg/BelugaRange message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__msg__BelugaRange__copy(
  const beluga_messages__msg__BelugaRange * input,
  beluga_messages__msg__BelugaRange * output);

/// Initialize array of msg/BelugaRange messages.
/**
 * It allocates the memory for the number of elements and calls
 * beluga_messages__msg__BelugaRange__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__msg__BelugaRange__Sequence__init(beluga_messages__msg__BelugaRange__Sequence * array, size_t size);

/// Finalize array of msg/BelugaRange messages.
/**
 * It calls
 * beluga_messages__msg__BelugaRange__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__msg__BelugaRange__Sequence__fini(beluga_messages__msg__BelugaRange__Sequence * array);

/// Create array of msg/BelugaRange messages.
/**
 * It allocates the memory for the array and calls
 * beluga_messages__msg__BelugaRange__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
beluga_messages__msg__BelugaRange__Sequence *
beluga_messages__msg__BelugaRange__Sequence__create(size_t size);

/// Destroy array of msg/BelugaRange messages.
/**
 * It calls
 * beluga_messages__msg__BelugaRange__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__msg__BelugaRange__Sequence__destroy(beluga_messages__msg__BelugaRange__Sequence * array);

/// Check for msg/BelugaRange message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__msg__BelugaRange__Sequence__are_equal(const beluga_messages__msg__BelugaRange__Sequence * lhs, const beluga_messages__msg__BelugaRange__Sequence * rhs);

/// Copy an array of msg/BelugaRange messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__msg__BelugaRange__Sequence__copy(
  const beluga_messages__msg__BelugaRange__Sequence * input,
  beluga_messages__msg__BelugaRange__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__FUNCTIONS_H_
