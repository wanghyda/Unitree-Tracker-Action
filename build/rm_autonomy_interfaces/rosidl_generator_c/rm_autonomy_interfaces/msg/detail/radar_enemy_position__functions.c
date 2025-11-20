// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_autonomy_interfaces:msg/RadarEnemyPosition.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/radar_enemy_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_autonomy_interfaces__msg__RadarEnemyPosition__init(rm_autonomy_interfaces__msg__RadarEnemyPosition * msg)
{
  if (!msg) {
    return false;
  }
  // enemy_1_position_x
  // enemy_1_position_y
  // enemy_2_position_x
  // enemy_2_position_y
  // enemy_3_position_x
  // enemy_3_position_y
  // enemy_4_position_x
  // enemy_4_position_y
  // enemy_5_position_x
  // enemy_5_position_y
  // enemy_7_position_x
  // enemy_7_position_y
  return true;
}

void
rm_autonomy_interfaces__msg__RadarEnemyPosition__fini(rm_autonomy_interfaces__msg__RadarEnemyPosition * msg)
{
  if (!msg) {
    return;
  }
  // enemy_1_position_x
  // enemy_1_position_y
  // enemy_2_position_x
  // enemy_2_position_y
  // enemy_3_position_x
  // enemy_3_position_y
  // enemy_4_position_x
  // enemy_4_position_y
  // enemy_5_position_x
  // enemy_5_position_y
  // enemy_7_position_x
  // enemy_7_position_y
}

bool
rm_autonomy_interfaces__msg__RadarEnemyPosition__are_equal(const rm_autonomy_interfaces__msg__RadarEnemyPosition * lhs, const rm_autonomy_interfaces__msg__RadarEnemyPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // enemy_1_position_x
  if (lhs->enemy_1_position_x != rhs->enemy_1_position_x) {
    return false;
  }
  // enemy_1_position_y
  if (lhs->enemy_1_position_y != rhs->enemy_1_position_y) {
    return false;
  }
  // enemy_2_position_x
  if (lhs->enemy_2_position_x != rhs->enemy_2_position_x) {
    return false;
  }
  // enemy_2_position_y
  if (lhs->enemy_2_position_y != rhs->enemy_2_position_y) {
    return false;
  }
  // enemy_3_position_x
  if (lhs->enemy_3_position_x != rhs->enemy_3_position_x) {
    return false;
  }
  // enemy_3_position_y
  if (lhs->enemy_3_position_y != rhs->enemy_3_position_y) {
    return false;
  }
  // enemy_4_position_x
  if (lhs->enemy_4_position_x != rhs->enemy_4_position_x) {
    return false;
  }
  // enemy_4_position_y
  if (lhs->enemy_4_position_y != rhs->enemy_4_position_y) {
    return false;
  }
  // enemy_5_position_x
  if (lhs->enemy_5_position_x != rhs->enemy_5_position_x) {
    return false;
  }
  // enemy_5_position_y
  if (lhs->enemy_5_position_y != rhs->enemy_5_position_y) {
    return false;
  }
  // enemy_7_position_x
  if (lhs->enemy_7_position_x != rhs->enemy_7_position_x) {
    return false;
  }
  // enemy_7_position_y
  if (lhs->enemy_7_position_y != rhs->enemy_7_position_y) {
    return false;
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__RadarEnemyPosition__copy(
  const rm_autonomy_interfaces__msg__RadarEnemyPosition * input,
  rm_autonomy_interfaces__msg__RadarEnemyPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // enemy_1_position_x
  output->enemy_1_position_x = input->enemy_1_position_x;
  // enemy_1_position_y
  output->enemy_1_position_y = input->enemy_1_position_y;
  // enemy_2_position_x
  output->enemy_2_position_x = input->enemy_2_position_x;
  // enemy_2_position_y
  output->enemy_2_position_y = input->enemy_2_position_y;
  // enemy_3_position_x
  output->enemy_3_position_x = input->enemy_3_position_x;
  // enemy_3_position_y
  output->enemy_3_position_y = input->enemy_3_position_y;
  // enemy_4_position_x
  output->enemy_4_position_x = input->enemy_4_position_x;
  // enemy_4_position_y
  output->enemy_4_position_y = input->enemy_4_position_y;
  // enemy_5_position_x
  output->enemy_5_position_x = input->enemy_5_position_x;
  // enemy_5_position_y
  output->enemy_5_position_y = input->enemy_5_position_y;
  // enemy_7_position_x
  output->enemy_7_position_x = input->enemy_7_position_x;
  // enemy_7_position_y
  output->enemy_7_position_y = input->enemy_7_position_y;
  return true;
}

rm_autonomy_interfaces__msg__RadarEnemyPosition *
rm_autonomy_interfaces__msg__RadarEnemyPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__RadarEnemyPosition * msg = (rm_autonomy_interfaces__msg__RadarEnemyPosition *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__RadarEnemyPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_autonomy_interfaces__msg__RadarEnemyPosition));
  bool success = rm_autonomy_interfaces__msg__RadarEnemyPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_autonomy_interfaces__msg__RadarEnemyPosition__destroy(rm_autonomy_interfaces__msg__RadarEnemyPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_autonomy_interfaces__msg__RadarEnemyPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence__init(rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__RadarEnemyPosition * data = NULL;

  if (size) {
    data = (rm_autonomy_interfaces__msg__RadarEnemyPosition *)allocator.zero_allocate(size, sizeof(rm_autonomy_interfaces__msg__RadarEnemyPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_autonomy_interfaces__msg__RadarEnemyPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_autonomy_interfaces__msg__RadarEnemyPosition__fini(&data[i - 1]);
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
rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence__fini(rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence * array)
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
      rm_autonomy_interfaces__msg__RadarEnemyPosition__fini(&array->data[i]);
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

rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence *
rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence * array = (rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence__destroy(rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence__are_equal(const rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence * lhs, const rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_autonomy_interfaces__msg__RadarEnemyPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence__copy(
  const rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence * input,
  rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_autonomy_interfaces__msg__RadarEnemyPosition);
    rm_autonomy_interfaces__msg__RadarEnemyPosition * data =
      (rm_autonomy_interfaces__msg__RadarEnemyPosition *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_autonomy_interfaces__msg__RadarEnemyPosition__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rm_autonomy_interfaces__msg__RadarEnemyPosition__fini(&data[i]);
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
    if (!rm_autonomy_interfaces__msg__RadarEnemyPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
