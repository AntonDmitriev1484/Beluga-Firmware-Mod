// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from beluga_messages:msg/BelugaNeighbors.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBORS__BUILDER_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBORS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "beluga_messages/msg/detail/beluga_neighbors__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace beluga_messages
{

namespace msg
{

namespace builder
{

class Init_BelugaNeighbors_neighbors
{
public:
  Init_BelugaNeighbors_neighbors()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::beluga_messages::msg::BelugaNeighbors neighbors(::beluga_messages::msg::BelugaNeighbors::_neighbors_type arg)
  {
    msg_.neighbors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::beluga_messages::msg::BelugaNeighbors msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::beluga_messages::msg::BelugaNeighbors>()
{
  return beluga_messages::msg::builder::Init_BelugaNeighbors_neighbors();
}

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBORS__BUILDER_HPP_
