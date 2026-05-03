// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from beluga_messages:srv/BelugaATCommand.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__FUNCTIONS_H_
#define BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "beluga_messages/msg/rosidl_generator_c__visibility_control.h"

#include "beluga_messages/srv/detail/beluga_at_command__struct.h"

/// Initialize srv/BelugaATCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * beluga_messages__srv__BelugaATCommand_Request
 * )) before or use
 * beluga_messages__srv__BelugaATCommand_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__srv__BelugaATCommand_Request__init(beluga_messages__srv__BelugaATCommand_Request * msg);

/// Finalize srv/BelugaATCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__srv__BelugaATCommand_Request__fini(beluga_messages__srv__BelugaATCommand_Request * msg);

/// Create srv/BelugaATCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * beluga_messages__srv__BelugaATCommand_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
beluga_messages__srv__BelugaATCommand_Request *
beluga_messages__srv__BelugaATCommand_Request__create();

/// Destroy srv/BelugaATCommand message.
/**
 * It calls
 * beluga_messages__srv__BelugaATCommand_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__srv__BelugaATCommand_Request__destroy(beluga_messages__srv__BelugaATCommand_Request * msg);

/// Check for srv/BelugaATCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__srv__BelugaATCommand_Request__are_equal(const beluga_messages__srv__BelugaATCommand_Request * lhs, const beluga_messages__srv__BelugaATCommand_Request * rhs);

/// Copy a srv/BelugaATCommand message.
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
beluga_messages__srv__BelugaATCommand_Request__copy(
  const beluga_messages__srv__BelugaATCommand_Request * input,
  beluga_messages__srv__BelugaATCommand_Request * output);

/// Initialize array of srv/BelugaATCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * beluga_messages__srv__BelugaATCommand_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__srv__BelugaATCommand_Request__Sequence__init(beluga_messages__srv__BelugaATCommand_Request__Sequence * array, size_t size);

/// Finalize array of srv/BelugaATCommand messages.
/**
 * It calls
 * beluga_messages__srv__BelugaATCommand_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__srv__BelugaATCommand_Request__Sequence__fini(beluga_messages__srv__BelugaATCommand_Request__Sequence * array);

/// Create array of srv/BelugaATCommand messages.
/**
 * It allocates the memory for the array and calls
 * beluga_messages__srv__BelugaATCommand_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
beluga_messages__srv__BelugaATCommand_Request__Sequence *
beluga_messages__srv__BelugaATCommand_Request__Sequence__create(size_t size);

/// Destroy array of srv/BelugaATCommand messages.
/**
 * It calls
 * beluga_messages__srv__BelugaATCommand_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__srv__BelugaATCommand_Request__Sequence__destroy(beluga_messages__srv__BelugaATCommand_Request__Sequence * array);

/// Check for srv/BelugaATCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__srv__BelugaATCommand_Request__Sequence__are_equal(const beluga_messages__srv__BelugaATCommand_Request__Sequence * lhs, const beluga_messages__srv__BelugaATCommand_Request__Sequence * rhs);

/// Copy an array of srv/BelugaATCommand messages.
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
beluga_messages__srv__BelugaATCommand_Request__Sequence__copy(
  const beluga_messages__srv__BelugaATCommand_Request__Sequence * input,
  beluga_messages__srv__BelugaATCommand_Request__Sequence * output);

/// Initialize srv/BelugaATCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * beluga_messages__srv__BelugaATCommand_Response
 * )) before or use
 * beluga_messages__srv__BelugaATCommand_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__srv__BelugaATCommand_Response__init(beluga_messages__srv__BelugaATCommand_Response * msg);

/// Finalize srv/BelugaATCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__srv__BelugaATCommand_Response__fini(beluga_messages__srv__BelugaATCommand_Response * msg);

/// Create srv/BelugaATCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * beluga_messages__srv__BelugaATCommand_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
beluga_messages__srv__BelugaATCommand_Response *
beluga_messages__srv__BelugaATCommand_Response__create();

/// Destroy srv/BelugaATCommand message.
/**
 * It calls
 * beluga_messages__srv__BelugaATCommand_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__srv__BelugaATCommand_Response__destroy(beluga_messages__srv__BelugaATCommand_Response * msg);

/// Check for srv/BelugaATCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__srv__BelugaATCommand_Response__are_equal(const beluga_messages__srv__BelugaATCommand_Response * lhs, const beluga_messages__srv__BelugaATCommand_Response * rhs);

/// Copy a srv/BelugaATCommand message.
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
beluga_messages__srv__BelugaATCommand_Response__copy(
  const beluga_messages__srv__BelugaATCommand_Response * input,
  beluga_messages__srv__BelugaATCommand_Response * output);

/// Initialize array of srv/BelugaATCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * beluga_messages__srv__BelugaATCommand_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__srv__BelugaATCommand_Response__Sequence__init(beluga_messages__srv__BelugaATCommand_Response__Sequence * array, size_t size);

/// Finalize array of srv/BelugaATCommand messages.
/**
 * It calls
 * beluga_messages__srv__BelugaATCommand_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__srv__BelugaATCommand_Response__Sequence__fini(beluga_messages__srv__BelugaATCommand_Response__Sequence * array);

/// Create array of srv/BelugaATCommand messages.
/**
 * It allocates the memory for the array and calls
 * beluga_messages__srv__BelugaATCommand_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
beluga_messages__srv__BelugaATCommand_Response__Sequence *
beluga_messages__srv__BelugaATCommand_Response__Sequence__create(size_t size);

/// Destroy array of srv/BelugaATCommand messages.
/**
 * It calls
 * beluga_messages__srv__BelugaATCommand_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
void
beluga_messages__srv__BelugaATCommand_Response__Sequence__destroy(beluga_messages__srv__BelugaATCommand_Response__Sequence * array);

/// Check for srv/BelugaATCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_beluga_messages
bool
beluga_messages__srv__BelugaATCommand_Response__Sequence__are_equal(const beluga_messages__srv__BelugaATCommand_Response__Sequence * lhs, const beluga_messages__srv__BelugaATCommand_Response__Sequence * rhs);

/// Copy an array of srv/BelugaATCommand messages.
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
beluga_messages__srv__BelugaATCommand_Response__Sequence__copy(
  const beluga_messages__srv__BelugaATCommand_Response__Sequence * input,
  beluga_messages__srv__BelugaATCommand_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__FUNCTIONS_H_
