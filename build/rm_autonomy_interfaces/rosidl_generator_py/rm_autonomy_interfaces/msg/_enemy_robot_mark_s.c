// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_autonomy_interfaces:msg/EnemyRobotMark.idl
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
#include "rm_autonomy_interfaces/msg/detail/enemy_robot_mark__struct.h"
#include "rm_autonomy_interfaces/msg/detail/enemy_robot_mark__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_autonomy_interfaces__msg__enemy_robot_mark__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[60];
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
    assert(strncmp("rm_autonomy_interfaces.msg._enemy_robot_mark.EnemyRobotMark", full_classname_dest, 59) == 0);
  }
  rm_autonomy_interfaces__msg__EnemyRobotMark * ros_message = _ros_message;
  {  // enemy_1_mark
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_1_mark");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_1_mark = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_2_mark
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_2_mark");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_2_mark = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_3_mark
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_3_mark");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_3_mark = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_4_mark
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_4_mark");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_4_mark = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_5_mark
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_5_mark");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_5_mark = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_7_mark
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_7_mark");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_7_mark = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_autonomy_interfaces__msg__enemy_robot_mark__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EnemyRobotMark */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_autonomy_interfaces.msg._enemy_robot_mark");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EnemyRobotMark");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_autonomy_interfaces__msg__EnemyRobotMark * ros_message = (rm_autonomy_interfaces__msg__EnemyRobotMark *)raw_ros_message;
  {  // enemy_1_mark
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_1_mark);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_1_mark", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_2_mark
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_2_mark);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_2_mark", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_3_mark
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_3_mark);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_3_mark", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_4_mark
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_4_mark);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_4_mark", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_5_mark
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_5_mark);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_5_mark", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_7_mark
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_7_mark);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_7_mark", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
