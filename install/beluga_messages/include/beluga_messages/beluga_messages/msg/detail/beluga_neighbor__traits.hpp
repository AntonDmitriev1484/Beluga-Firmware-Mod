// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from beluga_messages:msg/BelugaNeighbor.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBOR__TRAITS_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "beluga_messages/msg/detail/beluga_neighbor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace beluga_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const BelugaNeighbor & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: rssi
  {
    out << "rssi: ";
    rosidl_generator_traits::value_to_yaml(msg.rssi, out);
    out << ", ";
  }

  // member: exchange
  {
    out << "exchange: ";
    rosidl_generator_traits::value_to_yaml(msg.exchange, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BelugaNeighbor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: rssi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rssi: ";
    rosidl_generator_traits::value_to_yaml(msg.rssi, out);
    out << "\n";
  }

  // member: exchange
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "exchange: ";
    rosidl_generator_traits::value_to_yaml(msg.exchange, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp:\n";
    to_block_style_yaml(msg.timestamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BelugaNeighbor & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace beluga_messages

namespace rosidl_generator_traits
{

[[deprecated("use beluga_messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const beluga_messages::msg::BelugaNeighbor & msg,
  std::ostream & out, size_t indentation = 0)
{
  beluga_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use beluga_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const beluga_messages::msg::BelugaNeighbor & msg)
{
  return beluga_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<beluga_messages::msg::BelugaNeighbor>()
{
  return "beluga_messages::msg::BelugaNeighbor";
}

template<>
inline const char * name<beluga_messages::msg::BelugaNeighbor>()
{
  return "beluga_messages/msg/BelugaNeighbor";
}

template<>
struct has_fixed_size<beluga_messages::msg::BelugaNeighbor>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<beluga_messages::msg::BelugaNeighbor>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<beluga_messages::msg::BelugaNeighbor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBOR__TRAITS_HPP_
