// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from beluga_messages:msg/BelugaRange.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__TRAITS_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "beluga_messages/msg/detail/beluga_range__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace beluga_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const BelugaRange & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: range
  {
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
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
    out << ", ";
  }

  // member: maxnoise
  {
    out << "maxnoise: ";
    rosidl_generator_traits::value_to_yaml(msg.maxnoise, out);
    out << ", ";
  }

  // member: firstpathamp1
  {
    out << "firstpathamp1: ";
    rosidl_generator_traits::value_to_yaml(msg.firstpathamp1, out);
    out << ", ";
  }

  // member: firstpathamp2
  {
    out << "firstpathamp2: ";
    rosidl_generator_traits::value_to_yaml(msg.firstpathamp2, out);
    out << ", ";
  }

  // member: firstpathamp3
  {
    out << "firstpathamp3: ";
    rosidl_generator_traits::value_to_yaml(msg.firstpathamp3, out);
    out << ", ";
  }

  // member: stdnoise
  {
    out << "stdnoise: ";
    rosidl_generator_traits::value_to_yaml(msg.stdnoise, out);
    out << ", ";
  }

  // member: maxgrowthcir
  {
    out << "maxgrowthcir: ";
    rosidl_generator_traits::value_to_yaml(msg.maxgrowthcir, out);
    out << ", ";
  }

  // member: rxpreamcount
  {
    out << "rxpreamcount: ";
    rosidl_generator_traits::value_to_yaml(msg.rxpreamcount, out);
    out << ", ";
  }

  // member: firstpath
  {
    out << "firstpath: ";
    rosidl_generator_traits::value_to_yaml(msg.firstpath, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BelugaRange & msg,
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

  // member: range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
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

  // member: maxnoise
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "maxnoise: ";
    rosidl_generator_traits::value_to_yaml(msg.maxnoise, out);
    out << "\n";
  }

  // member: firstpathamp1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firstpathamp1: ";
    rosidl_generator_traits::value_to_yaml(msg.firstpathamp1, out);
    out << "\n";
  }

  // member: firstpathamp2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firstpathamp2: ";
    rosidl_generator_traits::value_to_yaml(msg.firstpathamp2, out);
    out << "\n";
  }

  // member: firstpathamp3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firstpathamp3: ";
    rosidl_generator_traits::value_to_yaml(msg.firstpathamp3, out);
    out << "\n";
  }

  // member: stdnoise
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stdnoise: ";
    rosidl_generator_traits::value_to_yaml(msg.stdnoise, out);
    out << "\n";
  }

  // member: maxgrowthcir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "maxgrowthcir: ";
    rosidl_generator_traits::value_to_yaml(msg.maxgrowthcir, out);
    out << "\n";
  }

  // member: rxpreamcount
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rxpreamcount: ";
    rosidl_generator_traits::value_to_yaml(msg.rxpreamcount, out);
    out << "\n";
  }

  // member: firstpath
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firstpath: ";
    rosidl_generator_traits::value_to_yaml(msg.firstpath, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BelugaRange & msg, bool use_flow_style = false)
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
  const beluga_messages::msg::BelugaRange & msg,
  std::ostream & out, size_t indentation = 0)
{
  beluga_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use beluga_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const beluga_messages::msg::BelugaRange & msg)
{
  return beluga_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<beluga_messages::msg::BelugaRange>()
{
  return "beluga_messages::msg::BelugaRange";
}

template<>
inline const char * name<beluga_messages::msg::BelugaRange>()
{
  return "beluga_messages/msg/BelugaRange";
}

template<>
struct has_fixed_size<beluga_messages::msg::BelugaRange>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<beluga_messages::msg::BelugaRange>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<beluga_messages::msg::BelugaRange>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__TRAITS_HPP_
