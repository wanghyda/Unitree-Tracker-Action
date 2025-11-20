// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_autonomy_interfaces:msg/ArenaStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "rm_autonomy_interfaces/msg/detail/arena_status__struct.h"
#include "rm_autonomy_interfaces/msg/detail/arena_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_autonomy_interfaces__msg__arena_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("rm_autonomy_interfaces.msg._arena_status.ArenaStatus", full_classname_dest, 52) == 0);
  }
  rm_autonomy_interfaces__msg__ArenaStatus * ros_message = _ros_message;
  {  // healing_front
    PyObject * field = PyObject_GetAttrString(_pymsg, "healing_front");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->healing_front = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // healing_inner
    PyObject * field = PyObject_GetAttrString(_pymsg, "healing_inner");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->healing_inner = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rmul_healing
    PyObject * field = PyObject_GetAttrString(_pymsg, "rmul_healing");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rmul_healing = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // energy_occupy_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "energy_occupy_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->energy_occupy_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // energy_small_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "energy_small_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->energy_small_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // energy_big_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "energy_big_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->energy_big_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ring_highground_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "ring_highground_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ring_highground_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // trapezoid_highground_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "trapezoid_highground_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->trapezoid_highground_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // base_shield_percentage
    PyObject * field = PyObject_GetAttrString(_pymsg, "base_shield_percentage");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->base_shield_percentage = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rump_central_buff_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "rump_central_buff_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rump_central_buff_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_autonomy_interfaces__msg__arena_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ArenaStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_autonomy_interfaces.msg._arena_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ArenaStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_autonomy_interfaces__msg__ArenaStatus * ros_message = (rm_autonomy_interfaces__msg__ArenaStatus *)raw_ros_message;
  {  // healing_front
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->healing_front);
    {
      int rc = PyObject_SetAttrString(_pymessage, "healing_front", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // healing_inner
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->healing_inner);
    {
      int rc = PyObject_SetAttrString(_pymessage, "healing_inner", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rmul_healing
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rmul_healing);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rmul_healing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // energy_occupy_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->energy_occupy_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "energy_occupy_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // energy_small_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->energy_small_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "energy_small_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // energy_big_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->energy_big_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "energy_big_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ring_highground_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ring_highground_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ring_highground_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trapezoid_highground_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->trapezoid_highground_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "trapezoid_highground_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // base_shield_percentage
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->base_shield_percentage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "base_shield_percentage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rump_central_buff_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rump_central_buff_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rump_central_buff_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
