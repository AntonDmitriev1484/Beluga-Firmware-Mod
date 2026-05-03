// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from beluga_messages:srv/BelugaATCommand.idl
// generated code does not contain a copyright notice
#include "beluga_messages/srv/detail/beluga_at_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `arg`
#include "rosidl_runtime_c/string_functions.h"

bool
beluga_messages__srv__BelugaATCommand_Request__init(beluga_messages__srv__BelugaATCommand_Request * msg)
{
  if (!msg) {
    return false;
  }
  // arg
  if (!rosidl_runtime_c__String__init(&msg->arg)) {
    beluga_messages__srv__BelugaATCommand_Request__fini(msg);
    return false;
  }
  // at_command
  return true;
}

void
beluga_messages__srv__BelugaATCommand_Request__fini(beluga_messages__srv__BelugaATCommand_Request * msg)
{
  if (!msg) {
    return;
  }
  // arg
  rosidl_runtime_c__String__fini(&msg->arg);
  // at_command
}

bool
beluga_messages__srv__BelugaATCommand_Request__are_equal(const beluga_messages__srv__BelugaATCommand_Request * lhs, const beluga_messages__srv__BelugaATCommand_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // arg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->arg), &(rhs->arg)))
  {
    return false;
  }
  // at_command
  if (lhs->at_command != rhs->at_command) {
    return false;
  }
  return true;
}

bool
beluga_messages__srv__BelugaATCommand_Request__copy(
  const beluga_messages__srv__BelugaATCommand_Request * input,
  beluga_messages__srv__BelugaATCommand_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // arg
  if (!rosidl_runtime_c__String__copy(
      &(input->arg), &(output->arg)))
  {
    return false;
  }
  // at_command
  output->at_command = input->at_command;
  return true;
}

beluga_messages__srv__BelugaATCommand_Request *
beluga_messages__srv__BelugaATCommand_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__srv__BelugaATCommand_Request * msg = (beluga_messages__srv__BelugaATCommand_Request *)allocator.allocate(sizeof(beluga_messages__srv__BelugaATCommand_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(beluga_messages__srv__BelugaATCommand_Request));
  bool success = beluga_messages__srv__BelugaATCommand_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
beluga_messages__srv__BelugaATCommand_Request__destroy(beluga_messages__srv__BelugaATCommand_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    beluga_messages__srv__BelugaATCommand_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
beluga_messages__srv__BelugaATCommand_Request__Sequence__init(beluga_messages__srv__BelugaATCommand_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__srv__BelugaATCommand_Request * data = NULL;

  if (size) {
    data = (beluga_messages__srv__BelugaATCommand_Request *)allocator.zero_allocate(size, sizeof(beluga_messages__srv__BelugaATCommand_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = beluga_messages__srv__BelugaATCommand_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        beluga_messages__srv__BelugaATCommand_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
beluga_messages__srv__BelugaATCommand_Request__Sequence__fini(beluga_messages__srv__BelugaATCommand_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      beluga_messages__srv__BelugaATCommand_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

beluga_messages__srv__BelugaATCommand_Request__Sequence *
beluga_messages__srv__BelugaATCommand_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__srv__BelugaATCommand_Request__Sequence * array = (beluga_messages__srv__BelugaATCommand_Request__Sequence *)allocator.allocate(sizeof(beluga_messages__srv__BelugaATCommand_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = beluga_messages__srv__BelugaATCommand_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
beluga_messages__srv__BelugaATCommand_Request__Sequence__destroy(beluga_messages__srv__BelugaATCommand_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    beluga_messages__srv__BelugaATCommand_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
beluga_messages__srv__BelugaATCommand_Request__Sequence__are_equal(const beluga_messages__srv__BelugaATCommand_Request__Sequence * lhs, const beluga_messages__srv__BelugaATCommand_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!beluga_messages__srv__BelugaATCommand_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
beluga_messages__srv__BelugaATCommand_Request__Sequence__copy(
  const beluga_messages__srv__BelugaATCommand_Request__Sequence * input,
  beluga_messages__srv__BelugaATCommand_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(beluga_messages__srv__BelugaATCommand_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    beluga_messages__srv__BelugaATCommand_Request * data =
      (beluga_messages__srv__BelugaATCommand_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!beluga_messages__srv__BelugaATCommand_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          beluga_messages__srv__BelugaATCommand_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!beluga_messages__srv__BelugaATCommand_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
beluga_messages__srv__BelugaATCommand_Response__init(beluga_messages__srv__BelugaATCommand_Response * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    beluga_messages__srv__BelugaATCommand_Response__fini(msg);
    return false;
  }
  return true;
}

void
beluga_messages__srv__BelugaATCommand_Response__fini(beluga_messages__srv__BelugaATCommand_Response * msg)
{
  if (!msg) {
    return;
  }
  // response
  rosidl_runtime_c__String__fini(&msg->response);
}

bool
beluga_messages__srv__BelugaATCommand_Response__are_equal(const beluga_messages__srv__BelugaATCommand_Response * lhs, const beluga_messages__srv__BelugaATCommand_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
beluga_messages__srv__BelugaATCommand_Response__copy(
  const beluga_messages__srv__BelugaATCommand_Response * input,
  beluga_messages__srv__BelugaATCommand_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

beluga_messages__srv__BelugaATCommand_Response *
beluga_messages__srv__BelugaATCommand_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__srv__BelugaATCommand_Response * msg = (beluga_messages__srv__BelugaATCommand_Response *)allocator.allocate(sizeof(beluga_messages__srv__BelugaATCommand_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(beluga_messages__srv__BelugaATCommand_Response));
  bool success = beluga_messages__srv__BelugaATCommand_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
beluga_messages__srv__BelugaATCommand_Response__destroy(beluga_messages__srv__BelugaATCommand_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    beluga_messages__srv__BelugaATCommand_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
beluga_messages__srv__BelugaATCommand_Response__Sequence__init(beluga_messages__srv__BelugaATCommand_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__srv__BelugaATCommand_Response * data = NULL;

  if (size) {
    data = (beluga_messages__srv__BelugaATCommand_Response *)allocator.zero_allocate(size, sizeof(beluga_messages__srv__BelugaATCommand_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = beluga_messages__srv__BelugaATCommand_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        beluga_messages__srv__BelugaATCommand_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
beluga_messages__srv__BelugaATCommand_Response__Sequence__fini(beluga_messages__srv__BelugaATCommand_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      beluga_messages__srv__BelugaATCommand_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

beluga_messages__srv__BelugaATCommand_Response__Sequence *
beluga_messages__srv__BelugaATCommand_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__srv__BelugaATCommand_Response__Sequence * array = (beluga_messages__srv__BelugaATCommand_Response__Sequence *)allocator.allocate(sizeof(beluga_messages__srv__BelugaATCommand_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = beluga_messages__srv__BelugaATCommand_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
beluga_messages__srv__BelugaATCommand_Response__Sequence__destroy(beluga_messages__srv__BelugaATCommand_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    beluga_messages__srv__BelugaATCommand_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
beluga_messages__srv__BelugaATCommand_Response__Sequence__are_equal(const beluga_messages__srv__BelugaATCommand_Response__Sequence * lhs, const beluga_messages__srv__BelugaATCommand_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!beluga_messages__srv__BelugaATCommand_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
beluga_messages__srv__BelugaATCommand_Response__Sequence__copy(
  const beluga_messages__srv__BelugaATCommand_Response__Sequence * input,
  beluga_messages__srv__BelugaATCommand_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(beluga_messages__srv__BelugaATCommand_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    beluga_messages__srv__BelugaATCommand_Response * data =
      (beluga_messages__srv__BelugaATCommand_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!beluga_messages__srv__BelugaATCommand_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          beluga_messages__srv__BelugaATCommand_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!beluga_messages__srv__BelugaATCommand_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
