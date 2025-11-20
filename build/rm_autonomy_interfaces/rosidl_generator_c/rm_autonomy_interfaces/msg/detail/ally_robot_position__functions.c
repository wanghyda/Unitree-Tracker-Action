// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_autonomy_interfaces:msg/AllyRobotPosition.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/ally_robot_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_autonomy_interfaces__msg__AllyRobotPosition__init(rm_autonomy_interfaces__msg__AllyRobotPosition * msg)
{
  if (!msg) {
    return false;
  }
  // ally_1_position_x
  // ally_1_position_y
  // ally_2_position_x
  // ally_2_position_y
  // ally_3_position_x
  // ally_3_position_y
  // ally_4_position_x
  // ally_4_position_y
  // ally_5_position_x
  // ally_5_position_y
  // ally_7_position_x
  // ally_7_position_y
  return true;
}

void
rm_autonomy_interfaces__msg__AllyRobotPosition__fini(rm_autonomy_interfaces__msg__AllyRobotPosition * msg)
{
  if (!msg) {
    return;
  }
  // ally_1_position_x
  // ally_1_position_y
  // ally_2_position_x
  // ally_2_position_y
  // ally_3_position_x
  // ally_3_position_y
  // ally_4_position_x
  // ally_4_position_y
  // ally_5_position_x
  // ally_5_position_y
  // ally_7_position_x
  // ally_7_position_y
}

bool
rm_autonomy_interfaces__msg__AllyRobotPosition__are_equal(const rm_autonomy_interfaces__msg__AllyRobotPosition * lhs, const rm_autonomy_interfaces__msg__AllyRobotPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ally_1_position_x
  if (lhs->ally_1_position_x != rhs->ally_1_position_x) {
    return false;
  }
  // ally_1_position_y
  if (lhs->ally_1_position_y != rhs->ally_1_position_y) {
    return false;
  }
  // ally_2_position_x
  if (lhs->ally_2_position_x != rhs->ally_2_position_x) {
    return false;
  }
  // ally_2_position_y
  if (lhs->ally_2_position_y != rhs->ally_2_position_y) {
    return false;
  }
  // ally_3_position_x
  if (lhs->ally_3_position_x != rhs->ally_3_position_x) {
    return false;
  }
  // ally_3_position_y
  if (lhs->ally_3_position_y != rhs->ally_3_position_y) {
    return false;
  }
  // ally_4_position_x
  if (lhs->ally_4_position_x != rhs->ally_4_position_x) {
    return false;
  }
  // ally_4_position_y
  if (lhs->ally_4_position_y != rhs->ally_4_position_y) {
    return false;
  }
  // ally_5_position_x
  if (lhs->ally_5_position_x != rhs->ally_5_position_x) {
    return false;
  }
  // ally_5_position_y
  if (lhs->ally_5_position_y != rhs->ally_5_position_y) {
    return false;
  }
  // ally_7_position_x
  if (lhs->ally_7_position_x != rhs->ally_7_position_x) {
    return false;
  }
  // ally_7_position_y
  if (lhs->ally_7_position_y != rhs->ally_7_position_y) {
    return false;
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__AllyRobotPosition__copy(
  const rm_autonomy_interfaces__msg__AllyRobotPosition * input,
  rm_autonomy_interfaces__msg__AllyRobotPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // ally_1_position_x
  output->ally_1_position_x = input->ally_1_position_x;
  // ally_1_position_y
  output->ally_1_position_y = input->ally_1_position_y;
  // ally_2_position_x
  output->ally_2_position_x = input->ally_2_position_x;
  // ally_2_position_y
  output->ally_2_position_y = input->ally_2_position_y;
  // ally_3_position_x
  output->ally_3_position_x = input->ally_3_position_x;
  // ally_3_position_y
  output->ally_3_position_y = input->ally_3_position_y;
  // ally_4_position_x
  output->ally_4_position_x = input->ally_4_position_x;
  // ally_4_position_y
  output->ally_4_position_y = input->ally_4_position_y;
  // ally_5_position_x
  output->ally_5_position_x = input->ally_5_position_x;
  // ally_5_position_y
  output->ally_5_position_y = input->ally_5_position_y;
  // ally_7_position_x
  output->ally_7_position_x = input->ally_7_position_x;
  // ally_7_position_y
  output->ally_7_position_y = input->ally_7_position_y;
  return true;
}

rm_autonomy_interfaces__msg__AllyRobotPosition *
rm_autonomy_interfaces__msg__AllyRobotPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__AllyRobotPosition * msg = (rm_autonomy_interfaces__msg__AllyRobotPosition *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__AllyRobotPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_autonomy_interfaces__msg__AllyRobotPosition));
  bool success = rm_autonomy_interfaces__msg__AllyRobotPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_autonomy_interfaces__msg__AllyRobotPosition__destroy(rm_autonomy_interfaces__msg__AllyRobotPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_autonomy_interfaces__msg__AllyRobotPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence__init(rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__AllyRobotPosition * data = NULL;

  if (size) {
    data = (rm_autonomy_interfaces__msg__AllyRobotPosition *)allocator.zero_allocate(size, sizeof(rm_autonomy_interfaces__msg__AllyRobotPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_autonomy_interfaces__msg__AllyRobotPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_autonomy_interfaces__msg__AllyRobotPosition__fini(&data[i - 1]);
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
rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence__fini(rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence * array)
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
      rm_autonomy_interfaces__msg__AllyRobotPosition__fini(&array->data[i]);
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

rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence *
rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence * array = (rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence__destroy(rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence__are_equal(const rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence * lhs, const rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_autonomy_interfaces__msg__AllyRobotPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence__copy(
  const rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence * input,
  rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_autonomy_interfaces__msg__AllyRobotPosition);
    rm_autonomy_interfaces__msg__AllyRobotPosition * data =
      (rm_autonomy_interfaces__msg__AllyRobotPosition *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_autonomy_interfaces__msg__AllyRobotPosition__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rm_autonomy_interfaces__msg__AllyRobotPosition__fini(&data[i]);
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
    if (!rm_autonomy_interfaces__msg__AllyRobotPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
