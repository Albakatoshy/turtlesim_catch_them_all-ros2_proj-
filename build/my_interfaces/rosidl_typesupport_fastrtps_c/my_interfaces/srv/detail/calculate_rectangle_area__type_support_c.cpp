// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_interfaces:srv/CalculateRectangleArea.idl
// generated code does not contain a copyright notice
#include "my_interfaces/srv/detail/calculate_rectangle_area__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_interfaces/srv/detail/calculate_rectangle_area__struct.h"
#include "my_interfaces/srv/detail/calculate_rectangle_area__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _CalculateRectangleArea_Request__ros_msg_type = my_interfaces__srv__CalculateRectangleArea_Request;

static bool _CalculateRectangleArea_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CalculateRectangleArea_Request__ros_msg_type * ros_message = static_cast<const _CalculateRectangleArea_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: length
  {
    cdr << ros_message->length;
  }

  // Field name: width
  {
    cdr << ros_message->width;
  }

  return true;
}

static bool _CalculateRectangleArea_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CalculateRectangleArea_Request__ros_msg_type * ros_message = static_cast<_CalculateRectangleArea_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: length
  {
    cdr >> ros_message->length;
  }

  // Field name: width
  {
    cdr >> ros_message->width;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_interfaces
size_t get_serialized_size_my_interfaces__srv__CalculateRectangleArea_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CalculateRectangleArea_Request__ros_msg_type * ros_message = static_cast<const _CalculateRectangleArea_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name length
  {
    size_t item_size = sizeof(ros_message->length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name width
  {
    size_t item_size = sizeof(ros_message->width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CalculateRectangleArea_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_interfaces__srv__CalculateRectangleArea_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_interfaces
size_t max_serialized_size_my_interfaces__srv__CalculateRectangleArea_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: width
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_interfaces__srv__CalculateRectangleArea_Request;
    is_plain =
      (
      offsetof(DataType, width) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _CalculateRectangleArea_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_interfaces__srv__CalculateRectangleArea_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CalculateRectangleArea_Request = {
  "my_interfaces::srv",
  "CalculateRectangleArea_Request",
  _CalculateRectangleArea_Request__cdr_serialize,
  _CalculateRectangleArea_Request__cdr_deserialize,
  _CalculateRectangleArea_Request__get_serialized_size,
  _CalculateRectangleArea_Request__max_serialized_size
};

static rosidl_message_type_support_t _CalculateRectangleArea_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CalculateRectangleArea_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_interfaces, srv, CalculateRectangleArea_Request)() {
  return &_CalculateRectangleArea_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "my_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "my_interfaces/srv/detail/calculate_rectangle_area__struct.h"
// already included above
// #include "my_interfaces/srv/detail/calculate_rectangle_area__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _CalculateRectangleArea_Response__ros_msg_type = my_interfaces__srv__CalculateRectangleArea_Response;

static bool _CalculateRectangleArea_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CalculateRectangleArea_Response__ros_msg_type * ros_message = static_cast<const _CalculateRectangleArea_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: area
  {
    cdr << ros_message->area;
  }

  return true;
}

static bool _CalculateRectangleArea_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CalculateRectangleArea_Response__ros_msg_type * ros_message = static_cast<_CalculateRectangleArea_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: area
  {
    cdr >> ros_message->area;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_interfaces
size_t get_serialized_size_my_interfaces__srv__CalculateRectangleArea_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CalculateRectangleArea_Response__ros_msg_type * ros_message = static_cast<const _CalculateRectangleArea_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name area
  {
    size_t item_size = sizeof(ros_message->area);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CalculateRectangleArea_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_interfaces__srv__CalculateRectangleArea_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_interfaces
size_t max_serialized_size_my_interfaces__srv__CalculateRectangleArea_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: area
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_interfaces__srv__CalculateRectangleArea_Response;
    is_plain =
      (
      offsetof(DataType, area) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _CalculateRectangleArea_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_interfaces__srv__CalculateRectangleArea_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CalculateRectangleArea_Response = {
  "my_interfaces::srv",
  "CalculateRectangleArea_Response",
  _CalculateRectangleArea_Response__cdr_serialize,
  _CalculateRectangleArea_Response__cdr_deserialize,
  _CalculateRectangleArea_Response__get_serialized_size,
  _CalculateRectangleArea_Response__max_serialized_size
};

static rosidl_message_type_support_t _CalculateRectangleArea_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CalculateRectangleArea_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_interfaces, srv, CalculateRectangleArea_Response)() {
  return &_CalculateRectangleArea_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "my_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_interfaces/srv/calculate_rectangle_area.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t CalculateRectangleArea__callbacks = {
  "my_interfaces::srv",
  "CalculateRectangleArea",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_interfaces, srv, CalculateRectangleArea_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_interfaces, srv, CalculateRectangleArea_Response)(),
};

static rosidl_service_type_support_t CalculateRectangleArea__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &CalculateRectangleArea__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_interfaces, srv, CalculateRectangleArea)() {
  return &CalculateRectangleArea__handle;
}

#if defined(__cplusplus)
}
#endif
