// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from beluga_messages:msg/BelugaExchange.idl
// generated code does not contain a copyright notice
#include "beluga_messages/msg/detail/beluga_exchange__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
beluga_messages__msg__BelugaExchange__init(beluga_messages__msg__BelugaExchange * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // exchange
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    beluga_messages__msg__BelugaExchange__fini(msg);
    return false;
  }
  return true;
}

void
beluga_messages__msg__BelugaExchange__fini(beluga_messages__msg__BelugaExchange * msg)
{
  if (!msg) {
    return;
  }
  // id
  // exchange
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
}

bool
beluga_messages__msg__BelugaExchange__are_equal(const beluga_messages__msg__BelugaExchange * lhs, const beluga_messages__msg__BelugaExchange * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // exchange
  if (lhs->exchange != rhs->exchange) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->timestamp), &(rhs->timestamp)))
  {
    return false;
  }
  return true;
}

bool
beluga_messages__msg__BelugaExchange__copy(
  const beluga_messages__msg__BelugaExchange * input,
  beluga_messages__msg__BelugaExchange * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // exchange
  output->exchange = input->exchange;
  // timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  return true;
}

beluga_messages__msg__BelugaExchange *
beluga_messages__msg__BelugaExchange__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__msg__BelugaExchange * msg = (beluga_messages__msg__BelugaExchange *)allocator.allocate(sizeof(beluga_messages__msg__BelugaExchange), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(beluga_messages__msg__BelugaExchange));
  bool success = beluga_messages__msg__BelugaExchange__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
beluga_messages__msg__BelugaExchange__destroy(beluga_messages__msg__BelugaExchange * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    beluga_messages__msg__BelugaExchange__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
beluga_messages__msg__BelugaExchange__Sequence__init(beluga_messages__msg__BelugaExchange__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__msg__BelugaExchange * data = NULL;

  if (size) {
    data = (beluga_messages__msg__BelugaExchange *)allocator.zero_allocate(size, sizeof(beluga_messages__msg__BelugaExchange), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = beluga_messages__msg__BelugaExchange__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        beluga_messages__msg__BelugaExchange__fini(&data[i - 1]);
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
beluga_messages__msg__BelugaExchange__Sequence__fini(beluga_messages__msg__BelugaExchange__Sequence * array)
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
      beluga_messages__msg__BelugaExchange__fini(&array->data[i]);
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

beluga_messages__msg__BelugaExchange__Sequence *
beluga_messages__msg__BelugaExchange__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__msg__BelugaExchange__Sequence * array = (beluga_messages__msg__BelugaExchange__Sequence *)allocator.allocate(sizeof(beluga_messages__msg__BelugaExchange__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = beluga_messages__msg__BelugaExchange__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
beluga_messages__msg__BelugaExchange__Sequence__destroy(beluga_messages__msg__BelugaExchange__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    beluga_messages__msg__BelugaExchange__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
beluga_messages__msg__BelugaExchange__Sequence__are_equal(const beluga_messages__msg__BelugaExchange__Sequence * lhs, const beluga_messages__msg__BelugaExchange__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!beluga_messages__msg__BelugaExchange__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
beluga_messages__msg__BelugaExchange__Sequence__copy(
  const beluga_messages__msg__BelugaExchange__Sequence * input,
  beluga_messages__msg__BelugaExchange__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(beluga_messages__msg__BelugaExchange);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    beluga_messages__msg__BelugaExchange * data =
      (beluga_messages__msg__BelugaExchange *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!beluga_messages__msg__BelugaExchange__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          beluga_messages__msg__BelugaExchange__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!beluga_messages__msg__BelugaExchange__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
