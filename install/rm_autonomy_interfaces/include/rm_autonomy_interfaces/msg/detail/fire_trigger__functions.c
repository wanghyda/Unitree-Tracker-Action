// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_autonomy_interfaces:msg/FireTrigger.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/fire_trigger__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_autonomy_interfaces__msg__FireTrigger__init(rm_autonomy_interfaces__msg__FireTrigger * msg)
{
  if (!msg) {
    return false;
  }
  // fire_trigger
  return true;
}

void
rm_autonomy_interfaces__msg__FireTrigger__fini(rm_autonomy_interfaces__msg__FireTrigger * msg)
{
  if (!msg) {
    return;
  }
  // fire_trigger
}

bool
rm_autonomy_interfaces__msg__FireTrigger__are_equal(const rm_autonomy_interfaces__msg__FireTrigger * lhs, const rm_autonomy_interfaces__msg__FireTrigger * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // fire_trigger
  if (lhs->fire_trigger != rhs->fire_trigger) {
    return false;
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__FireTrigger__copy(
  const rm_autonomy_interfaces__msg__FireTrigger * input,
  rm_autonomy_interfaces__msg__FireTrigger * output)
{
  if (!input || !output) {
    return false;
  }
  // fire_trigger
  output->fire_trigger = input->fire_trigger;
  return true;
}

rm_autonomy_interfaces__msg__FireTrigger *
rm_autonomy_interfaces__msg__FireTrigger__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__FireTrigger * msg = (rm_autonomy_interfaces__msg__FireTrigger *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__FireTrigger), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_autonomy_interfaces__msg__FireTrigger));
  bool success = rm_autonomy_interfaces__msg__FireTrigger__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_autonomy_interfaces__msg__FireTrigger__destroy(rm_autonomy_interfaces__msg__FireTrigger * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_autonomy_interfaces__msg__FireTrigger__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_autonomy_interfaces__msg__FireTrigger__Sequence__init(rm_autonomy_interfaces__msg__FireTrigger__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__FireTrigger * data = NULL;

  if (size) {
    data = (rm_autonomy_interfaces__msg__FireTrigger *)allocator.zero_allocate(size, sizeof(rm_autonomy_interfaces__msg__FireTrigger), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_autonomy_interfaces__msg__FireTrigger__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_autonomy_interfaces__msg__FireTrigger__fini(&data[i - 1]);
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
rm_autonomy_interfaces__msg__FireTrigger__Sequence__fini(rm_autonomy_interfaces__msg__FireTrigger__Sequence * array)
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
      rm_autonomy_interfaces__msg__FireTrigger__fini(&array->data[i]);
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

rm_autonomy_interfaces__msg__FireTrigger__Sequence *
rm_autonomy_interfaces__msg__FireTrigger__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__FireTrigger__Sequence * array = (rm_autonomy_interfaces__msg__FireTrigger__Sequence *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__FireTrigger__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_autonomy_interfaces__msg__FireTrigger__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_autonomy_interfaces__msg__FireTrigger__Sequence__destroy(rm_autonomy_interfaces__msg__FireTrigger__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_autonomy_interfaces__msg__FireTrigger__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_autonomy_interfaces__msg__FireTrigger__Sequence__are_equal(const rm_autonomy_interfaces__msg__FireTrigger__Sequence * lhs, const rm_autonomy_interfaces__msg__FireTrigger__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_autonomy_interfaces__msg__FireTrigger__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__FireTrigger__Sequence__copy(
  const rm_autonomy_interfaces__msg__FireTrigger__Sequence * input,
  rm_autonomy_interfaces__msg__FireTrigger__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_autonomy_interfaces__msg__FireTrigger);
    rm_autonomy_interfaces__msg__FireTrigger * data =
      (rm_autonomy_interfaces__msg__FireTrigger *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_autonomy_interfaces__msg__FireTrigger__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rm_autonomy_interfaces__msg__FireTrigger__fini(&data[i]);
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
    if (!rm_autonomy_interfaces__msg__FireTrigger__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
