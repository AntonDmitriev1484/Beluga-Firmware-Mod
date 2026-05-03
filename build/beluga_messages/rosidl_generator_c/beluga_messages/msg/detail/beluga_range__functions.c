// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from beluga_messages:msg/BelugaRange.idl
// generated code does not contain a copyright notice
#include "beluga_messages/msg/detail/beluga_range__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
beluga_messages__msg__BelugaRange__init(beluga_messages__msg__BelugaRange * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // range
  // exchange
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    beluga_messages__msg__BelugaRange__fini(msg);
    return false;
  }
  // maxnoise
  // firstpathamp1
  // firstpathamp2
  // firstpathamp3
  // stdnoise
  // maxgrowthcir
  // rxpreamcount
  // firstpath
  return true;
}

void
beluga_messages__msg__BelugaRange__fini(beluga_messages__msg__BelugaRange * msg)
{
  if (!msg) {
    return;
  }
  // id
  // range
  // exchange
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
  // maxnoise
  // firstpathamp1
  // firstpathamp2
  // firstpathamp3
  // stdnoise
  // maxgrowthcir
  // rxpreamcount
  // firstpath
}

bool
beluga_messages__msg__BelugaRange__are_equal(const beluga_messages__msg__BelugaRange * lhs, const beluga_messages__msg__BelugaRange * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // range
  if (lhs->range != rhs->range) {
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
  // maxnoise
  if (lhs->maxnoise != rhs->maxnoise) {
    return false;
  }
  // firstpathamp1
  if (lhs->firstpathamp1 != rhs->firstpathamp1) {
    return false;
  }
  // firstpathamp2
  if (lhs->firstpathamp2 != rhs->firstpathamp2) {
    return false;
  }
  // firstpathamp3
  if (lhs->firstpathamp3 != rhs->firstpathamp3) {
    return false;
  }
  // stdnoise
  if (lhs->stdnoise != rhs->stdnoise) {
    return false;
  }
  // maxgrowthcir
  if (lhs->maxgrowthcir != rhs->maxgrowthcir) {
    return false;
  }
  // rxpreamcount
  if (lhs->rxpreamcount != rhs->rxpreamcount) {
    return false;
  }
  // firstpath
  if (lhs->firstpath != rhs->firstpath) {
    return false;
  }
  return true;
}

bool
beluga_messages__msg__BelugaRange__copy(
  const beluga_messages__msg__BelugaRange * input,
  beluga_messages__msg__BelugaRange * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // range
  output->range = input->range;
  // exchange
  output->exchange = input->exchange;
  // timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  // maxnoise
  output->maxnoise = input->maxnoise;
  // firstpathamp1
  output->firstpathamp1 = input->firstpathamp1;
  // firstpathamp2
  output->firstpathamp2 = input->firstpathamp2;
  // firstpathamp3
  output->firstpathamp3 = input->firstpathamp3;
  // stdnoise
  output->stdnoise = input->stdnoise;
  // maxgrowthcir
  output->maxgrowthcir = input->maxgrowthcir;
  // rxpreamcount
  output->rxpreamcount = input->rxpreamcount;
  // firstpath
  output->firstpath = input->firstpath;
  return true;
}

beluga_messages__msg__BelugaRange *
beluga_messages__msg__BelugaRange__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__msg__BelugaRange * msg = (beluga_messages__msg__BelugaRange *)allocator.allocate(sizeof(beluga_messages__msg__BelugaRange), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(beluga_messages__msg__BelugaRange));
  bool success = beluga_messages__msg__BelugaRange__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
beluga_messages__msg__BelugaRange__destroy(beluga_messages__msg__BelugaRange * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    beluga_messages__msg__BelugaRange__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
beluga_messages__msg__BelugaRange__Sequence__init(beluga_messages__msg__BelugaRange__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__msg__BelugaRange * data = NULL;

  if (size) {
    data = (beluga_messages__msg__BelugaRange *)allocator.zero_allocate(size, sizeof(beluga_messages__msg__BelugaRange), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = beluga_messages__msg__BelugaRange__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        beluga_messages__msg__BelugaRange__fini(&data[i - 1]);
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
beluga_messages__msg__BelugaRange__Sequence__fini(beluga_messages__msg__BelugaRange__Sequence * array)
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
      beluga_messages__msg__BelugaRange__fini(&array->data[i]);
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

beluga_messages__msg__BelugaRange__Sequence *
beluga_messages__msg__BelugaRange__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  beluga_messages__msg__BelugaRange__Sequence * array = (beluga_messages__msg__BelugaRange__Sequence *)allocator.allocate(sizeof(beluga_messages__msg__BelugaRange__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = beluga_messages__msg__BelugaRange__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
beluga_messages__msg__BelugaRange__Sequence__destroy(beluga_messages__msg__BelugaRange__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    beluga_messages__msg__BelugaRange__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
beluga_messages__msg__BelugaRange__Sequence__are_equal(const beluga_messages__msg__BelugaRange__Sequence * lhs, const beluga_messages__msg__BelugaRange__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!beluga_messages__msg__BelugaRange__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
beluga_messages__msg__BelugaRange__Sequence__copy(
  const beluga_messages__msg__BelugaRange__Sequence * input,
  beluga_messages__msg__BelugaRange__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(beluga_messages__msg__BelugaRange);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    beluga_messages__msg__BelugaRange * data =
      (beluga_messages__msg__BelugaRange *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!beluga_messages__msg__BelugaRange__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          beluga_messages__msg__BelugaRange__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!beluga_messages__msg__BelugaRange__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
