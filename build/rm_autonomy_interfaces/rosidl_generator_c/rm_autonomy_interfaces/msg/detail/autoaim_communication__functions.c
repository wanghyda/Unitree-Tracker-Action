// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_autonomy_interfaces:msg/AutoaimCommunication.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/autoaim_communication__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_autonomy_interfaces__msg__AutoaimCommunication__init(rm_autonomy_interfaces__msg__AutoaimCommunication * msg)
{
  if (!msg) {
    return false;
  }
  // has_target
  // target_id
  // distance
  return true;
}

void
rm_autonomy_interfaces__msg__AutoaimCommunication__fini(rm_autonomy_interfaces__msg__AutoaimCommunication * msg)
{
  if (!msg) {
    return;
  }
  // has_target
  // target_id
  // distance
}

bool
rm_autonomy_interfaces__msg__AutoaimCommunication__are_equal(const rm_autonomy_interfaces__msg__AutoaimCommunication * lhs, const rm_autonomy_interfaces__msg__AutoaimCommunication * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // has_target
  if (lhs->has_target != rhs->has_target) {
    return false;
  }
  // target_id
  if (lhs->target_id != rhs->target_id) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__AutoaimCommunication__copy(
  const rm_autonomy_interfaces__msg__AutoaimCommunication * input,
  rm_autonomy_interfaces__msg__AutoaimCommunication * output)
{
  if (!input || !output) {
    return false;
  }
  // has_target
  output->has_target = input->has_target;
  // target_id
  output->target_id = input->target_id;
  // distance
  output->distance = input->distance;
  return true;
}

rm_autonomy_interfaces__msg__AutoaimCommunication *
rm_autonomy_interfaces__msg__AutoaimCommunication__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__AutoaimCommunication * msg = (rm_autonomy_interfaces__msg__AutoaimCommunication *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__AutoaimCommunication), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_autonomy_interfaces__msg__AutoaimCommunication));
  bool success = rm_autonomy_interfaces__msg__AutoaimCommunication__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_autonomy_interfaces__msg__AutoaimCommunication__destroy(rm_autonomy_interfaces__msg__AutoaimCommunication * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_autonomy_interfaces__msg__AutoaimCommunication__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence__init(rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__AutoaimCommunication * data = NULL;

  if (size) {
    data = (rm_autonomy_interfaces__msg__AutoaimCommunication *)allocator.zero_allocate(size, sizeof(rm_autonomy_interfaces__msg__AutoaimCommunication), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_autonomy_interfaces__msg__AutoaimCommunication__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_autonomy_interfaces__msg__AutoaimCommunication__fini(&data[i - 1]);
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
rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence__fini(rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence * array)
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
      rm_autonomy_interfaces__msg__AutoaimCommunication__fini(&array->data[i]);
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

rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence *
rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence * array = (rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence__destroy(rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence__are_equal(const rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence * lhs, const rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_autonomy_interfaces__msg__AutoaimCommunication__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence__copy(
  const rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence * input,
  rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_autonomy_interfaces__msg__AutoaimCommunication);
    rm_autonomy_interfaces__msg__AutoaimCommunication * data =
      (rm_autonomy_interfaces__msg__AutoaimCommunication *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_autonomy_interfaces__msg__AutoaimCommunication__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rm_autonomy_interfaces__msg__AutoaimCommunication__fini(&data[i]);
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
    if (!rm_autonomy_interfaces__msg__AutoaimCommunication__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
