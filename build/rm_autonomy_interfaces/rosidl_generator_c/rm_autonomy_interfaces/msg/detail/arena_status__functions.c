// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_autonomy_interfaces:msg/ArenaStatus.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/arena_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_autonomy_interfaces__msg__ArenaStatus__init(rm_autonomy_interfaces__msg__ArenaStatus * msg)
{
  if (!msg) {
    return false;
  }
  // healing_front
  // healing_inner
  // rmul_healing
  // energy_occupy_status
  // energy_small_status
  // energy_big_status
  // ring_highground_status
  // trapezoid_highground_status
  // base_shield_percentage
  // rump_central_buff_status
  return true;
}

void
rm_autonomy_interfaces__msg__ArenaStatus__fini(rm_autonomy_interfaces__msg__ArenaStatus * msg)
{
  if (!msg) {
    return;
  }
  // healing_front
  // healing_inner
  // rmul_healing
  // energy_occupy_status
  // energy_small_status
  // energy_big_status
  // ring_highground_status
  // trapezoid_highground_status
  // base_shield_percentage
  // rump_central_buff_status
}

bool
rm_autonomy_interfaces__msg__ArenaStatus__are_equal(const rm_autonomy_interfaces__msg__ArenaStatus * lhs, const rm_autonomy_interfaces__msg__ArenaStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // healing_front
  if (lhs->healing_front != rhs->healing_front) {
    return false;
  }
  // healing_inner
  if (lhs->healing_inner != rhs->healing_inner) {
    return false;
  }
  // rmul_healing
  if (lhs->rmul_healing != rhs->rmul_healing) {
    return false;
  }
  // energy_occupy_status
  if (lhs->energy_occupy_status != rhs->energy_occupy_status) {
    return false;
  }
  // energy_small_status
  if (lhs->energy_small_status != rhs->energy_small_status) {
    return false;
  }
  // energy_big_status
  if (lhs->energy_big_status != rhs->energy_big_status) {
    return false;
  }
  // ring_highground_status
  if (lhs->ring_highground_status != rhs->ring_highground_status) {
    return false;
  }
  // trapezoid_highground_status
  if (lhs->trapezoid_highground_status != rhs->trapezoid_highground_status) {
    return false;
  }
  // base_shield_percentage
  if (lhs->base_shield_percentage != rhs->base_shield_percentage) {
    return false;
  }
  // rump_central_buff_status
  if (lhs->rump_central_buff_status != rhs->rump_central_buff_status) {
    return false;
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__ArenaStatus__copy(
  const rm_autonomy_interfaces__msg__ArenaStatus * input,
  rm_autonomy_interfaces__msg__ArenaStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // healing_front
  output->healing_front = input->healing_front;
  // healing_inner
  output->healing_inner = input->healing_inner;
  // rmul_healing
  output->rmul_healing = input->rmul_healing;
  // energy_occupy_status
  output->energy_occupy_status = input->energy_occupy_status;
  // energy_small_status
  output->energy_small_status = input->energy_small_status;
  // energy_big_status
  output->energy_big_status = input->energy_big_status;
  // ring_highground_status
  output->ring_highground_status = input->ring_highground_status;
  // trapezoid_highground_status
  output->trapezoid_highground_status = input->trapezoid_highground_status;
  // base_shield_percentage
  output->base_shield_percentage = input->base_shield_percentage;
  // rump_central_buff_status
  output->rump_central_buff_status = input->rump_central_buff_status;
  return true;
}

rm_autonomy_interfaces__msg__ArenaStatus *
rm_autonomy_interfaces__msg__ArenaStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__ArenaStatus * msg = (rm_autonomy_interfaces__msg__ArenaStatus *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__ArenaStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_autonomy_interfaces__msg__ArenaStatus));
  bool success = rm_autonomy_interfaces__msg__ArenaStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_autonomy_interfaces__msg__ArenaStatus__destroy(rm_autonomy_interfaces__msg__ArenaStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_autonomy_interfaces__msg__ArenaStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_autonomy_interfaces__msg__ArenaStatus__Sequence__init(rm_autonomy_interfaces__msg__ArenaStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__ArenaStatus * data = NULL;

  if (size) {
    data = (rm_autonomy_interfaces__msg__ArenaStatus *)allocator.zero_allocate(size, sizeof(rm_autonomy_interfaces__msg__ArenaStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_autonomy_interfaces__msg__ArenaStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_autonomy_interfaces__msg__ArenaStatus__fini(&data[i - 1]);
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
rm_autonomy_interfaces__msg__ArenaStatus__Sequence__fini(rm_autonomy_interfaces__msg__ArenaStatus__Sequence * array)
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
      rm_autonomy_interfaces__msg__ArenaStatus__fini(&array->data[i]);
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

rm_autonomy_interfaces__msg__ArenaStatus__Sequence *
rm_autonomy_interfaces__msg__ArenaStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__ArenaStatus__Sequence * array = (rm_autonomy_interfaces__msg__ArenaStatus__Sequence *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__ArenaStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_autonomy_interfaces__msg__ArenaStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_autonomy_interfaces__msg__ArenaStatus__Sequence__destroy(rm_autonomy_interfaces__msg__ArenaStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_autonomy_interfaces__msg__ArenaStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_autonomy_interfaces__msg__ArenaStatus__Sequence__are_equal(const rm_autonomy_interfaces__msg__ArenaStatus__Sequence * lhs, const rm_autonomy_interfaces__msg__ArenaStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_autonomy_interfaces__msg__ArenaStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__ArenaStatus__Sequence__copy(
  const rm_autonomy_interfaces__msg__ArenaStatus__Sequence * input,
  rm_autonomy_interfaces__msg__ArenaStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_autonomy_interfaces__msg__ArenaStatus);
    rm_autonomy_interfaces__msg__ArenaStatus * data =
      (rm_autonomy_interfaces__msg__ArenaStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_autonomy_interfaces__msg__ArenaStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rm_autonomy_interfaces__msg__ArenaStatus__fini(&data[i]);
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
    if (!rm_autonomy_interfaces__msg__ArenaStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
