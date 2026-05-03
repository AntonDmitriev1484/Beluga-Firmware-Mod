// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from beluga_messages:srv/BelugaATCommand.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__TRAITS_HPP_
#define BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "beluga_messages/srv/detail/beluga_at_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace beluga_messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const BelugaATCommand_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: arg
  {
    out << "arg: ";
    rosidl_generator_traits::value_to_yaml(msg.arg, out);
    out << ", ";
  }

  // member: at_command
  {
    out << "at_command: ";
    rosidl_generator_traits::value_to_yaml(msg.at_command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BelugaATCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: arg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg: ";
    rosidl_generator_traits::value_to_yaml(msg.arg, out);
    out << "\n";
  }

  // member: at_command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "at_command: ";
    rosidl_generator_traits::value_to_yaml(msg.at_command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BelugaATCommand_Request & msg, bool use_flow_style = false)
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

}  // namespace beluga_messages

namespace rosidl_generator_traits
{

[[deprecated("use beluga_messages::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const beluga_messages::srv::BelugaATCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  beluga_messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use beluga_messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const beluga_messages::srv::BelugaATCommand_Request & msg)
{
  return beluga_messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<beluga_messages::srv::BelugaATCommand_Request>()
{
  return "beluga_messages::srv::BelugaATCommand_Request";
}

template<>
inline const char * name<beluga_messages::srv::BelugaATCommand_Request>()
{
  return "beluga_messages/srv/BelugaATCommand_Request";
}

template<>
struct has_fixed_size<beluga_messages::srv::BelugaATCommand_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<beluga_messages::srv::BelugaATCommand_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<beluga_messages::srv::BelugaATCommand_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace beluga_messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const BelugaATCommand_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BelugaATCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BelugaATCommand_Response & msg, bool use_flow_style = false)
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

}  // namespace beluga_messages

namespace rosidl_generator_traits
{

[[deprecated("use beluga_messages::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const beluga_messages::srv::BelugaATCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  beluga_messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use beluga_messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const beluga_messages::srv::BelugaATCommand_Response & msg)
{
  return beluga_messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<beluga_messages::srv::BelugaATCommand_Response>()
{
  return "beluga_messages::srv::BelugaATCommand_Response";
}

template<>
inline const char * name<beluga_messages::srv::BelugaATCommand_Response>()
{
  return "beluga_messages/srv/BelugaATCommand_Response";
}

template<>
struct has_fixed_size<beluga_messages::srv::BelugaATCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<beluga_messages::srv::BelugaATCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<beluga_messages::srv::BelugaATCommand_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<beluga_messages::srv::BelugaATCommand>()
{
  return "beluga_messages::srv::BelugaATCommand";
}

template<>
inline const char * name<beluga_messages::srv::BelugaATCommand>()
{
  return "beluga_messages/srv/BelugaATCommand";
}

template<>
struct has_fixed_size<beluga_messages::srv::BelugaATCommand>
  : std::integral_constant<
    bool,
    has_fixed_size<beluga_messages::srv::BelugaATCommand_Request>::value &&
    has_fixed_size<beluga_messages::srv::BelugaATCommand_Response>::value
  >
{
};

template<>
struct has_bounded_size<beluga_messages::srv::BelugaATCommand>
  : std::integral_constant<
    bool,
    has_bounded_size<beluga_messages::srv::BelugaATCommand_Request>::value &&
    has_bounded_size<beluga_messages::srv::BelugaATCommand_Response>::value
  >
{
};

template<>
struct is_service<beluga_messages::srv::BelugaATCommand>
  : std::true_type
{
};

template<>
struct is_service_request<beluga_messages::srv::BelugaATCommand_Request>
  : std::true_type
{
};

template<>
struct is_service_response<beluga_messages::srv::BelugaATCommand_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__TRAITS_HPP_
