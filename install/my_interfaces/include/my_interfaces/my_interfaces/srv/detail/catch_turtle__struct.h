// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:srv/CatchTurtle.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__CATCH_TURTLE__STRUCT_H_
#define MY_INTERFACES__SRV__DETAIL__CATCH_TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CatchTurtle in the package my_interfaces.
typedef struct my_interfaces__srv__CatchTurtle_Request
{
  rosidl_runtime_c__String name;
} my_interfaces__srv__CatchTurtle_Request;

// Struct for a sequence of my_interfaces__srv__CatchTurtle_Request.
typedef struct my_interfaces__srv__CatchTurtle_Request__Sequence
{
  my_interfaces__srv__CatchTurtle_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__srv__CatchTurtle_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CatchTurtle in the package my_interfaces.
typedef struct my_interfaces__srv__CatchTurtle_Response
{
  bool success;
} my_interfaces__srv__CatchTurtle_Response;

// Struct for a sequence of my_interfaces__srv__CatchTurtle_Response.
typedef struct my_interfaces__srv__CatchTurtle_Response__Sequence
{
  my_interfaces__srv__CatchTurtle_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__srv__CatchTurtle_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__SRV__DETAIL__CATCH_TURTLE__STRUCT_H_
