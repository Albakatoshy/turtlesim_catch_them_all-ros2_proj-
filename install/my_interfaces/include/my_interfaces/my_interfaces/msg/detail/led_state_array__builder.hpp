// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/LedStateArray.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/led_state_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_LedStateArray_led_states
{
public:
  Init_LedStateArray_led_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::msg::LedStateArray led_states(::my_interfaces::msg::LedStateArray::_led_states_type arg)
  {
    msg_.led_states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::LedStateArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::LedStateArray>()
{
  return my_interfaces::msg::builder::Init_LedStateArray_led_states();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__BUILDER_HPP_
