// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_autonomy_interfaces:msg/RadarEnemyPosition.idl
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
#include "rm_autonomy_interfaces/msg/detail/radar_enemy_position__struct.h"
#include "rm_autonomy_interfaces/msg/detail/radar_enemy_position__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_autonomy_interfaces__msg__radar_enemy_position__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
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
    assert(strncmp("rm_autonomy_interfaces.msg._radar_enemy_position.RadarEnemyPosition", full_classname_dest, 67) == 0);
  }
  rm_autonomy_interfaces__msg__RadarEnemyPosition * ros_message = _ros_message;
  {  // enemy_1_position_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_1_position_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_1_position_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_1_position_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_1_position_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_1_position_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_2_position_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_2_position_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_2_position_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_2_position_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_2_position_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_2_position_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_3_position_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_3_position_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_3_position_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_3_position_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_3_position_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_3_position_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_4_position_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_4_position_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_4_position_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_4_position_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_4_position_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_4_position_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_5_position_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_5_position_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_5_position_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_5_position_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_5_position_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_5_position_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_7_position_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_7_position_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_7_position_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_7_position_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_7_position_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_7_position_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_autonomy_interfaces__msg__radar_enemy_position__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RadarEnemyPosition */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_autonomy_interfaces.msg._radar_enemy_position");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RadarEnemyPosition");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_autonomy_interfaces__msg__RadarEnemyPosition * ros_message = (rm_autonomy_interfaces__msg__RadarEnemyPosition *)raw_ros_message;
  {  // enemy_1_position_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_1_position_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_1_position_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_1_position_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_1_position_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_1_position_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_2_position_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_2_position_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_2_position_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_2_position_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_2_position_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_2_position_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_3_position_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_3_position_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_3_position_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_3_position_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_3_position_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_3_position_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_4_position_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_4_position_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_4_position_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_4_position_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_4_position_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_4_position_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_5_position_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_5_position_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_5_position_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_5_position_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_5_position_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_5_position_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_7_position_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_7_position_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_7_position_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_7_position_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_7_position_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_7_position_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
