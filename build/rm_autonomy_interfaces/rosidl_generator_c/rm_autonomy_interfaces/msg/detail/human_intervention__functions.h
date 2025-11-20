// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rm_autonomy_interfaces:msg/HumanIntervention.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__HUMAN_INTERVENTION__FUNCTIONS_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__HUMAN_INTERVENTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rm_autonomy_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rm_autonomy_interfaces/msg/detail/human_intervention__struct.h"

/// Initialize msg/HumanIntervention message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rm_autonomy_interfaces__msg__HumanIntervention
 * )) before or use
 * rm_autonomy_interfaces__msg__HumanIntervention__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
bool
rm_autonomy_interfaces__msg__HumanIntervention__init(rm_autonomy_interfaces__msg__HumanIntervention * msg);

/// Finalize msg/HumanIntervention message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
void
rm_autonomy_interfaces__msg__HumanIntervention__fini(rm_autonomy_interfaces__msg__HumanIntervention * msg);

/// Create msg/HumanIntervention message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rm_autonomy_interfaces__msg__HumanIntervention__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
rm_autonomy_interfaces__msg__HumanIntervention *
rm_autonomy_interfaces__msg__HumanIntervention__create();

/// Destroy msg/HumanIntervention message.
/**
 * It calls
 * rm_autonomy_interfaces__msg__HumanIntervention__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
void
rm_autonomy_interfaces__msg__HumanIntervention__destroy(rm_autonomy_interfaces__msg__HumanIntervention * msg);

/// Check for msg/HumanIntervention message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
bool
rm_autonomy_interfaces__msg__HumanIntervention__are_equal(const rm_autonomy_interfaces__msg__HumanIntervention * lhs, const rm_autonomy_interfaces__msg__HumanIntervention * rhs);

/// Copy a msg/HumanIntervention message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
bool
rm_autonomy_interfaces__msg__HumanIntervention__copy(
  const rm_autonomy_interfaces__msg__HumanIntervention * input,
  rm_autonomy_interfaces__msg__HumanIntervention * output);

/// Initialize array of msg/HumanIntervention messages.
/**
 * It allocates the memory for the number of elements and calls
 * rm_autonomy_interfaces__msg__HumanIntervention__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
bool
rm_autonomy_interfaces__msg__HumanIntervention__Sequence__init(rm_autonomy_interfaces__msg__HumanIntervention__Sequence * array, size_t size);

/// Finalize array of msg/HumanIntervention messages.
/**
 * It calls
 * rm_autonomy_interfaces__msg__HumanIntervention__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
void
rm_autonomy_interfaces__msg__HumanIntervention__Sequence__fini(rm_autonomy_interfaces__msg__HumanIntervention__Sequence * array);

/// Create array of msg/HumanIntervention messages.
/**
 * It allocates the memory for the array and calls
 * rm_autonomy_interfaces__msg__HumanIntervention__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
rm_autonomy_interfaces__msg__HumanIntervention__Sequence *
rm_autonomy_interfaces__msg__HumanIntervention__Sequence__create(size_t size);

/// Destroy array of msg/HumanIntervention messages.
/**
 * It calls
 * rm_autonomy_interfaces__msg__HumanIntervention__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
void
rm_autonomy_interfaces__msg__HumanIntervention__Sequence__destroy(rm_autonomy_interfaces__msg__HumanIntervention__Sequence * array);

/// Check for msg/HumanIntervention message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
bool
rm_autonomy_interfaces__msg__HumanIntervention__Sequence__are_equal(const rm_autonomy_interfaces__msg__HumanIntervention__Sequence * lhs, const rm_autonomy_interfaces__msg__HumanIntervention__Sequence * rhs);

/// Copy an array of msg/HumanIntervention messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_autonomy_interfaces
bool
rm_autonomy_interfaces__msg__HumanIntervention__Sequence__copy(
  const rm_autonomy_interfaces__msg__HumanIntervention__Sequence * input,
  rm_autonomy_interfaces__msg__HumanIntervention__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__HUMAN_INTERVENTION__FUNCTIONS_H_
