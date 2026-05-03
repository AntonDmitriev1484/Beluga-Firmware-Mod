// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from beluga_messages:msg/BelugaNeighbors.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBORS__TRAITS_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBORS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "beluga_messages/msg/detail/beluga_neighbors__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'neighbors'
#include "beluga_messages/msg/detail/beluga_neighbor__traits.hpp"

namespace beluga_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const BelugaNeighbors & msg,
  std::ostream & out)
{
  out << "{";
  // member: neighbors
  {
    if (msg.neighbors.size() == 0) {
      out << "neighbors: []";
    } else {
      out << "neighbors: [";
      size_t pending_items = msg.neighbors.size();
      for (auto item : msg.neighbors) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BelugaNeighbors & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: neighbors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.neighbors.size() == 0) {
      out << "neighbors: []\n";
    } else {
      out << "neighbors:\n";
      for (auto item : msg.neighbors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BelugaNeighbors & msg, bool use_flow_style = false)
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
  const beluga_messages::msg::BelugaNeighbors & msg,
  std::ostream & out, size_t indentation = 0)
{
  beluga_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use beluga_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const beluga_messages::msg::BelugaNeighbors & msg)
{
  return beluga_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<beluga_messages::msg::BelugaNeighbors>()
{
  return "beluga_messages::msg::BelugaNeighbors";
}

template<>
inline const char * name<beluga_messages::msg::BelugaNeighbors>()
{
  return "beluga_messages/msg/BelugaNeighbors";
}

template<>
struct has_fixed_size<beluga_messages::msg::BelugaNeighbors>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<beluga_messages::msg::BelugaNeighbors>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<beluga_messages::msg::BelugaNeighbors>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBORS__TRAITS_HPP_
