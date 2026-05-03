// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from beluga_messages:msg/BelugaNeighbors.idl
// generated code does not contain a copyright notice
#include "beluga_messages/msg/detail/beluga_neighbors__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `neighbors`
#include "beluga_messages/msg/detail/beluga_neighbor__functions.h"

bool
beluga_messages__msg__BelugaNeighbors__init(beluga_messages__msg__BelugaNeighbors * msg)
{
  if (!msg) {
    return false;
  }
  // neighbors
  if (!beluga_messages__msg__BelugaNeighbor__Sequence__init(&msg->neighbors, 0)) {
    beluga_messages__msg__BelugaNeighbors__fini(msg);
    return false;
  }
  return true;
}

void
beluga_messages__msg__BelugaNeighbors__fini(beluga_messages__msg__BelugaNeighbors * msg)
{
  if (!msg) {
    return;
  }
  // neighbors
  beluga_messages__msg__BelugaNeighbor__Sequence__fini(&msg->neighbors);
}

bool
beluga_messages__msg__BelugaNeighbors__are_equal(const beluga_messages__msg__BelugaNeighbors * lhs, const beluga_messages__msg__BelugaNeighbors * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // neighbors
  if (!beluga_messages__msg__BelugaNeighbor__Sequence__are_equal(
      &(lhs->neighbors), &(rhs->neighbors)))
  {
    return false;
  }
  return true;
}

bool
beluga_messages__msg__BelugaNeighbors__copy(
  const beluga_messages__msg__BelugaNeighbors * input,
  beluga_messages__msg__BelugaNeighbors * output)
{
  if (!input || !output) {
    return false;
  }
  // neighbors
  if (!beluga_messages__msg__BelugaNeighbor__Sequence__copy(
      &(input->neighbors), &(output->neighbors)))
  {
    return false;
  }
  return true;
}

beluga_messages__msg__BelugaNeighbors *
beluga_messages__msg__BelugaNeighbors__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__msg__BelugaNeighbors * msg = (beluga_messages__msg__BelugaNeighbors *)allocator.allocate(sizeof(beluga_messages__msg__BelugaNeighbors), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(beluga_messages__msg__BelugaNeighbors));
  bool success = beluga_messages__msg__BelugaNeighbors__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
beluga_messages__msg__BelugaNeighbors__destroy(beluga_messages__msg__BelugaNeighbors * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    beluga_messages__msg__BelugaNeighbors__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
beluga_messages__msg__BelugaNeighbors__Sequence__init(beluga_messages__msg__BelugaNeighbors__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__msg__BelugaNeighbors * data = NULL;

  if (size) {
    data = (beluga_messages__msg__BelugaNeighbors *)allocator.zero_allocate(size, sizeof(beluga_messages__msg__BelugaNeighbors), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = beluga_messages__msg__BelugaNeighbors__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        beluga_messages__msg__BelugaNeighbors__fini(&data[i - 1]);
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
beluga_messages__msg__BelugaNeighbors__Sequence__fini(beluga_messages__msg__BelugaNeighbors__Sequence * array)
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
      beluga_messages__msg__BelugaNeighbors__fini(&array->data[i]);
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

beluga_messages__msg__BelugaNeighbors__Sequence *
beluga_messages__msg__BelugaNeighbors__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__msg__BelugaNeighbors__Sequence * array = (beluga_messages__msg__BelugaNeighbors__Sequence *)allocator.allocate(sizeof(beluga_messages__msg__BelugaNeighbors__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = beluga_messages__msg__BelugaNeighbors__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
beluga_messages__msg__BelugaNeighbors__Sequence__destroy(beluga_messages__msg__BelugaNeighbors__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    beluga_messages__msg__BelugaNeighbors__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
beluga_messages__msg__BelugaNeighbors__Sequence__are_equal(const beluga_messages__msg__BelugaNeighbors__Sequence * lhs, const beluga_messages__msg__BelugaNeighbors__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!beluga_messages__msg__BelugaNeighbors__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
beluga_messages__msg__BelugaNeighbors__Sequence__copy(
  const beluga_messages__msg__BelugaNeighbors__Sequence * input,
  beluga_messages__msg__BelugaNeighbors__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(beluga_messages__msg__BelugaNeighbors);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    beluga_messages__msg__BelugaNeighbors * data =
      (beluga_messages__msg__BelugaNeighbors *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!beluga_messages__msg__BelugaNeighbors__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          beluga_messages__msg__BelugaNeighbors__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!beluga_messages__msg__BelugaNeighbors__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
