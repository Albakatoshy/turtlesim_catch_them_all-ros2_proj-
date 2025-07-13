// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:srv/CalculateRectangleArea.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__STRUCT_H_
#define MY_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CalculateRectangleArea in the package my_interfaces.
typedef struct my_interfaces__srv__CalculateRectangleArea_Request
{
  double length;
  double width;
} my_interfaces__srv__CalculateRectangleArea_Request;

// Struct for a sequence of my_interfaces__srv__CalculateRectangleArea_Request.
typedef struct my_interfaces__srv__CalculateRectangleArea_Request__Sequence
{
  my_interfaces__srv__CalculateRectangleArea_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__srv__CalculateRectangleArea_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CalculateRectangleArea in the package my_interfaces.
typedef struct my_interfaces__srv__CalculateRectangleArea_Response
{
  double area;
} my_interfaces__srv__CalculateRectangleArea_Response;

// Struct for a sequence of my_interfaces__srv__CalculateRectangleArea_Response.
typedef struct my_interfaces__srv__CalculateRectangleArea_Response__Sequence
{
  my_interfaces__srv__CalculateRectangleArea_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__srv__CalculateRectangleArea_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__STRUCT_H_
