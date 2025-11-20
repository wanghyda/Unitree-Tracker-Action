// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_autonomy_interfaces:msg/SelfState.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/self_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_autonomy_interfaces__msg__SelfState__init(rm_autonomy_interfaces__msg__SelfState * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  // current_hp
  // patrol_rfid
  // energy_rfid
  // under_attack
  // current_ammo
  // energy_left
  // decision_set
  return true;
}

void
rm_autonomy_interfaces__msg__SelfState__fini(rm_autonomy_interfaces__msg__SelfState * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  // current_hp
  // patrol_rfid
  // energy_rfid
  // under_attack
  // current_ammo
  // energy_left
  // decision_set
}

bool
rm_autonomy_interfaces__msg__SelfState__are_equal(const rm_autonomy_interfaces__msg__SelfState * lhs, const rm_autonomy_interfaces__msg__SelfState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (lhs->robot_id != rhs->robot_id) {
    return false;
  }
  // current_hp
  if (lhs->current_hp != rhs->current_hp) {
    return false;
  }
  // patrol_rfid
  if (lhs->patrol_rfid != rhs->patrol_rfid) {
    return false;
  }
  // energy_rfid
  if (lhs->energy_rfid != rhs->energy_rfid) {
    return false;
  }
  // under_attack
  if (lhs->under_attack != rhs->under_attack) {
    return false;
  }
  // current_ammo
  if (lhs->current_ammo != rhs->current_ammo) {
    return false;
  }
  // energy_left
  if (lhs->energy_left != rhs->energy_left) {
    return false;
  }
  // decision_set
  if (lhs->decision_set != rhs->decision_set) {
    return false;
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__SelfState__copy(
  const rm_autonomy_interfaces__msg__SelfState * input,
  rm_autonomy_interfaces__msg__SelfState * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  output->robot_id = input->robot_id;
  // current_hp
  output->current_hp = input->current_hp;
  // patrol_rfid
  output->patrol_rfid = input->patrol_rfid;
  // energy_rfid
  output->energy_rfid = input->energy_rfid;
  // under_attack
  output->under_attack = input->under_attack;
  // current_ammo
  output->current_ammo = input->current_ammo;
  // energy_left
  output->energy_left = input->energy_left;
  // decision_set
  output->decision_set = input->decision_set;
  return true;
}

rm_autonomy_interfaces__msg__SelfState *
rm_autonomy_interfaces__msg__SelfState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__SelfState * msg = (rm_autonomy_interfaces__msg__SelfState *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__SelfState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_autonomy_interfaces__msg__SelfState));
  bool success = rm_autonomy_interfaces__msg__SelfState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_autonomy_interfaces__msg__SelfState__destroy(rm_autonomy_interfaces__msg__SelfState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_autonomy_interfaces__msg__SelfState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_autonomy_interfaces__msg__SelfState__Sequence__init(rm_autonomy_interfaces__msg__SelfState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__SelfState * data = NULL;

  if (size) {
    data = (rm_autonomy_interfaces__msg__SelfState *)allocator.zero_allocate(size, sizeof(rm_autonomy_interfaces__msg__SelfState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_autonomy_interfaces__msg__SelfState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_autonomy_interfaces__msg__SelfState__fini(&data[i - 1]);
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
rm_autonomy_interfaces__msg__SelfState__Sequence__fini(rm_autonomy_interfaces__msg__SelfState__Sequence * array)
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
      rm_autonomy_interfaces__msg__SelfState__fini(&array->data[i]);
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

rm_autonomy_interfaces__msg__SelfState__Sequence *
rm_autonomy_interfaces__msg__SelfState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_autonomy_interfaces__msg__SelfState__Sequence * array = (rm_autonomy_interfaces__msg__SelfState__Sequence *)allocator.allocate(sizeof(rm_autonomy_interfaces__msg__SelfState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_autonomy_interfaces__msg__SelfState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_autonomy_interfaces__msg__SelfState__Sequence__destroy(rm_autonomy_interfaces__msg__SelfState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_autonomy_interfaces__msg__SelfState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_autonomy_interfaces__msg__SelfState__Sequence__are_equal(const rm_autonomy_interfaces__msg__SelfState__Sequence * lhs, const rm_autonomy_interfaces__msg__SelfState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_autonomy_interfaces__msg__SelfState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_autonomy_interfaces__msg__SelfState__Sequence__copy(
  const rm_autonomy_interfaces__msg__SelfState__Sequence * input,
  rm_autonomy_interfaces__msg__SelfState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_autonomy_interfaces__msg__SelfState);
    rm_autonomy_interfaces__msg__SelfState * data =
      (rm_autonomy_interfaces__msg__SelfState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_autonomy_interfaces__msg__SelfState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rm_autonomy_interfaces__msg__SelfState__fini(&data[i]);
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
    if (!rm_autonomy_interfaces__msg__SelfState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
