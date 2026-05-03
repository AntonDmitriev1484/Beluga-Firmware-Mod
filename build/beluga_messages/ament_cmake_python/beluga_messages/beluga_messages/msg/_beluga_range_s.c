// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from beluga_messages:msg/BelugaRange.idl
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
#include "beluga_messages/msg/detail/beluga_range__struct.h"
#include "beluga_messages/msg/detail/beluga_range__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool beluga_messages__msg__beluga_range__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("beluga_messages.msg._beluga_range.BelugaRange", full_classname_dest, 45) == 0);
  }
  beluga_messages__msg__BelugaRange * ros_message = _ros_message;
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // range
    PyObject * field = PyObject_GetAttrString(_pymsg, "range");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->range = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // exchange
    PyObject * field = PyObject_GetAttrString(_pymsg, "exchange");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->exchange = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // timestamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->timestamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // maxnoise
    PyObject * field = PyObject_GetAttrString(_pymsg, "maxnoise");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->maxnoise = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // firstpathamp1
    PyObject * field = PyObject_GetAttrString(_pymsg, "firstpathamp1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->firstpathamp1 = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // firstpathamp2
    PyObject * field = PyObject_GetAttrString(_pymsg, "firstpathamp2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->firstpathamp2 = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // firstpathamp3
    PyObject * field = PyObject_GetAttrString(_pymsg, "firstpathamp3");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->firstpathamp3 = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // stdnoise
    PyObject * field = PyObject_GetAttrString(_pymsg, "stdnoise");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->stdnoise = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // maxgrowthcir
    PyObject * field = PyObject_GetAttrString(_pymsg, "maxgrowthcir");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->maxgrowthcir = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rxpreamcount
    PyObject * field = PyObject_GetAttrString(_pymsg, "rxpreamcount");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rxpreamcount = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // firstpath
    PyObject * field = PyObject_GetAttrString(_pymsg, "firstpath");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->firstpath = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * beluga_messages__msg__beluga_range__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BelugaRange */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("beluga_messages.msg._beluga_range");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BelugaRange");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  beluga_messages__msg__BelugaRange * ros_message = (beluga_messages__msg__BelugaRange *)raw_ros_message;
  {  // id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->range);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // exchange
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->exchange);
    {
      int rc = PyObject_SetAttrString(_pymessage, "exchange", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timestamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->timestamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // maxnoise
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->maxnoise);
    {
      int rc = PyObject_SetAttrString(_pymessage, "maxnoise", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // firstpathamp1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->firstpathamp1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "firstpathamp1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // firstpathamp2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->firstpathamp2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "firstpathamp2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // firstpathamp3
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->firstpathamp3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "firstpathamp3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stdnoise
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->stdnoise);
    {
      int rc = PyObject_SetAttrString(_pymessage, "stdnoise", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // maxgrowthcir
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->maxgrowthcir);
    {
      int rc = PyObject_SetAttrString(_pymessage, "maxgrowthcir", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rxpreamcount
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rxpreamcount);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rxpreamcount", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // firstpath
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->firstpath);
    {
      int rc = PyObject_SetAttrString(_pymessage, "firstpath", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
