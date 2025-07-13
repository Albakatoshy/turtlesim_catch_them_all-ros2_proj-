// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:srv/CalculateRectangleArea.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__BUILDER_HPP_
#define MY_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/srv/detail/calculate_rectangle_area__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace srv
{

namespace builder
{

class Init_CalculateRectangleArea_Request_width
{
public:
  explicit Init_CalculateRectangleArea_Request_width(::my_interfaces::srv::CalculateRectangleArea_Request & msg)
  : msg_(msg)
  {}
  ::my_interfaces::srv::CalculateRectangleArea_Request width(::my_interfaces::srv::CalculateRectangleArea_Request::_width_type arg)
  {
    msg_.width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::srv::CalculateRectangleArea_Request msg_;
};

class Init_CalculateRectangleArea_Request_length
{
public:
  Init_CalculateRectangleArea_Request_length()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalculateRectangleArea_Request_width length(::my_interfaces::srv::CalculateRectangleArea_Request::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_CalculateRectangleArea_Request_width(msg_);
  }

private:
  ::my_interfaces::srv::CalculateRectangleArea_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::srv::CalculateRectangleArea_Request>()
{
  return my_interfaces::srv::builder::Init_CalculateRectangleArea_Request_length();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace srv
{

namespace builder
{

class Init_CalculateRectangleArea_Response_area
{
public:
  Init_CalculateRectangleArea_Response_area()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::srv::CalculateRectangleArea_Response area(::my_interfaces::srv::CalculateRectangleArea_Response::_area_type arg)
  {
    msg_.area = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::srv::CalculateRectangleArea_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::srv::CalculateRectangleArea_Response>()
{
  return my_interfaces::srv::builder::Init_CalculateRectangleArea_Response_area();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__SRV__DETAIL__CALCULATE_RECTANGLE_AREA__BUILDER_HPP_
