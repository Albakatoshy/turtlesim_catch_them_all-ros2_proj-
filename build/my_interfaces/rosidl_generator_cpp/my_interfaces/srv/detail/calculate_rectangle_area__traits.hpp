// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:srv/CalculateRectangleArea.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__TRAITS_HPP_
#define MY_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/srv/detail/calculate_rectangle_area__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CalculateRectangleArea_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: length
  {
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CalculateRectangleArea_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CalculateRectangleArea_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_interfaces::srv::CalculateRectangleArea_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::srv::CalculateRectangleArea_Request & msg)
{
  return my_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::srv::CalculateRectangleArea_Request>()
{
  return "my_interfaces::srv::CalculateRectangleArea_Request";
}

template<>
inline const char * name<my_interfaces::srv::CalculateRectangleArea_Request>()
{
  return "my_interfaces/srv/CalculateRectangleArea_Request";
}

template<>
struct has_fixed_size<my_interfaces::srv::CalculateRectangleArea_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_interfaces::srv::CalculateRectangleArea_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_interfaces::srv::CalculateRectangleArea_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CalculateRectangleArea_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: area
  {
    out << "area: ";
    rosidl_generator_traits::value_to_yaml(msg.area, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CalculateRectangleArea_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: area
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "area: ";
    rosidl_generator_traits::value_to_yaml(msg.area, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CalculateRectangleArea_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_interfaces::srv::CalculateRectangleArea_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::srv::CalculateRectangleArea_Response & msg)
{
  return my_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::srv::CalculateRectangleArea_Response>()
{
  return "my_interfaces::srv::CalculateRectangleArea_Response";
}

template<>
inline const char * name<my_interfaces::srv::CalculateRectangleArea_Response>()
{
  return "my_interfaces/srv/CalculateRectangleArea_Response";
}

template<>
struct has_fixed_size<my_interfaces::srv::CalculateRectangleArea_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_interfaces::srv::CalculateRectangleArea_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_interfaces::srv::CalculateRectangleArea_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_interfaces::srv::CalculateRectangleArea>()
{
  return "my_interfaces::srv::CalculateRectangleArea";
}

template<>
inline const char * name<my_interfaces::srv::CalculateRectangleArea>()
{
  return "my_interfaces/srv/CalculateRectangleArea";
}

template<>
struct has_fixed_size<my_interfaces::srv::CalculateRectangleArea>
  : std::integral_constant<
    bool,
    has_fixed_size<my_interfaces::srv::CalculateRectangleArea_Request>::value &&
    has_fixed_size<my_interfaces::srv::CalculateRectangleArea_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_interfaces::srv::CalculateRectangleArea>
  : std::integral_constant<
    bool,
    has_bounded_size<my_interfaces::srv::CalculateRectangleArea_Request>::value &&
    has_bounded_size<my_interfaces::srv::CalculateRectangleArea_Response>::value
  >
{
};

template<>
struct is_service<my_interfaces::srv::CalculateRectangleArea>
  : std::true_type
{
};

template<>
struct is_service_request<my_interfaces::srv::CalculateRectangleArea_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_interfaces::srv::CalculateRectangleArea_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__TRAITS_HPP_
