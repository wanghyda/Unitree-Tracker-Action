// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_autonomy_interfaces:msg/RadarTarget.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/radar_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_autonomy_interfaces__msg__RadarTarget__init(rm_autonomy_interfaces__msg__RadarTarget * msg)
{
  if (!msg) {
    return false;
  }
  // target_id
  // target_map_x
  // target_map_y
  return true;
}

void
rm_autonomy_interfaces__msg__RadarTarget__fini(rm_autonomy_interfaces__msg__RadarTarget * msg)
{
  if (!msg) {
    return;
  }
  // target_id
  // target_map_x
  // target_map_y
}

bool
rm_autonomy_interfaces__msg__RadarTarget__are_equal(const rm_autonomy_interfaces__msg__RadarTarget * lhs, const rm_autonomy_interfaces__msg__RadarTarget * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_id
  if (lhs->target_id != rhs->target_id) {
    return false;
  }
  // target_map_x
  if (lhs->target_map_x != rhs->target_map_x) {
    return false;
  }
  // target_map_y
  if (lhs->target_map_y != rhs->target_map_y) {
    return false;
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__RadarTarget__copy(
  const rm_autonomy_interfaces__msg__RadarTarget * input,
  rm_autonomy_interfaces__msg__RadarTarget * output)
{
  if (!input || !output) {
    return false;
  }
  // target_id
  output->target_id = input->target_id;
  // target_map_x
  output->target_map_x = input->target_map_x;
  // target_map_y
  output->target_map_y = input->target_map_y;
  return true;
}

rm_autonomy_interfaces__msg__RadarTarget *
rm_autonomy_interfaces__msg__RadarTarget__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__RadarTarget * msg = (rm_autonomy_interfaces__msg__RadarTarget *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__RadarTarget), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_autonomy_interfaces__msg__RadarTarget));
  bool success = rm_autonomy_interfaces__msg__RadarTarget__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_autonomy_interfaces__msg__RadarTarget__destroy(rm_autonomy_interfaces__msg__RadarTarget * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_autonomy_interfaces__msg__RadarTarget__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_autonomy_interfaces__msg__RadarTarget__Sequence__init(rm_autonomy_interfaces__msg__RadarTarget__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__RadarTarget * data = NULL;

  if (size) {
    data = (rm_autonomy_interfaces__msg__RadarTarget *)allocator.zero_allocate(size, sizeof(rm_autonomy_interfaces__msg__RadarTarget), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_autonomy_interfaces__msg__RadarTarget__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_autonomy_interfaces__msg__RadarTarget__fini(&data[i - 1]);
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
rm_autonomy_interfaces__msg__RadarTarget__Sequence__fini(rm_autonomy_interfaces__msg__RadarTarget__Sequence * array)
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
      rm_autonomy_interfaces__msg__RadarTarget__fini(&array->data[i]);
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

rm_autonomy_interfaces__msg__RadarTarget__Sequence *
rm_autonomy_interfaces__msg__RadarTarget__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__RadarTarget__Sequence * array = (rm_autonomy_interfaces__msg__RadarTarget__Sequence *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__RadarTarget__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_autonomy_interfaces__msg__RadarTarget__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_autonomy_interfaces__msg__RadarTarget__Sequence__destroy(rm_autonomy_interfaces__msg__RadarTarget__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_autonomy_interfaces__msg__RadarTarget__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_autonomy_interfaces__msg__RadarTarget__Sequence__are_equal(const rm_autonomy_interfaces__msg__RadarTarget__Sequence * lhs, const rm_autonomy_interfaces__msg__RadarTarget__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_autonomy_interfaces__msg__RadarTarget__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__RadarTarget__Sequence__copy(
  const rm_autonomy_interfaces__msg__RadarTarget__Sequence * input,
  rm_autonomy_interfaces__msg__RadarTarget__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_autonomy_interfaces__msg__RadarTarget);
    rm_autonomy_interfaces__msg__RadarTarget * data =
      (rm_autonomy_interfaces__msg__RadarTarget *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_autonomy_interfaces__msg__RadarTarget__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rm_autonomy_interfaces__msg__RadarTarget__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_autonomy_interfaces__msg__RadarTarget__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
