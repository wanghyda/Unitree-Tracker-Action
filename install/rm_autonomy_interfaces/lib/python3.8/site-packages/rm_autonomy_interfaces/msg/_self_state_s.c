// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_autonomy_interfaces:msg/SelfState.idl
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
#include "rm_autonomy_interfaces/msg/detail/self_state__struct.h"
#include "rm_autonomy_interfaces/msg/detail/self_state__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_autonomy_interfaces__msg__self_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
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
    assert(strncmp("rm_autonomy_interfaces.msg._self_state.SelfState", full_classname_dest, 48) == 0);
  }
  rm_autonomy_interfaces__msg__SelfState * ros_message = _ros_message;
  {  // robot_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->robot_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // current_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // patrol_rfid
    PyObject * field = PyObject_GetAttrString(_pymsg, "patrol_rfid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->patrol_rfid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // energy_rfid
    PyObject * field = PyObject_GetAttrString(_pymsg, "energy_rfid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->energy_rfid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // under_attack
    PyObject * field = PyObject_GetAttrString(_pymsg, "under_attack");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->under_attack = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // current_ammo
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_ammo");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current_ammo = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // energy_left
    PyObject * field = PyObject_GetAttrString(_pymsg, "energy_left");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->energy_left = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // decision_set
    PyObject * field = PyObject_GetAttrString(_pymsg, "decision_set");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->decision_set = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_autonomy_interfaces__msg__self_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SelfState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_autonomy_interfaces.msg._self_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SelfState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_autonomy_interfaces__msg__SelfState * ros_message = (rm_autonomy_interfaces__msg__SelfState *)raw_ros_message;
  {  // robot_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->robot_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->current_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // patrol_rfid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->patrol_rfid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "patrol_rfid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // energy_rfid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->energy_rfid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "energy_rfid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // under_attack
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->under_attack);
    {
      int rc = PyObject_SetAttrString(_pymessage, "under_attack", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_ammo
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->current_ammo);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_ammo", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // energy_left
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->energy_left);
    {
      int rc = PyObject_SetAttrString(_pymessage, "energy_left", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // decision_set
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->decision_set);
    {
      int rc = PyObject_SetAttrString(_pymessage, "decision_set", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
