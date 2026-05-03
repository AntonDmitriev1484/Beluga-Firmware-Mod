// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from beluga_messages:msg/BelugaNeighbor.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBOR__BUILDER_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "beluga_messages/msg/detail/beluga_neighbor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace beluga_messages
{

namespace msg
{

namespace builder
{

class Init_BelugaNeighbor_timestamp
{
public:
  explicit Init_BelugaNeighbor_timestamp(::beluga_messages::msg::BelugaNeighbor & msg)
  : msg_(msg)
  {}
  ::beluga_messages::msg::BelugaNeighbor timestamp(::beluga_messages::msg::BelugaNeighbor::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::beluga_messages::msg::BelugaNeighbor msg_;
};

class Init_BelugaNeighbor_exchange
{
public:
  explicit Init_BelugaNeighbor_exchange(::beluga_messages::msg::BelugaNeighbor & msg)
  : msg_(msg)
  {}
  Init_BelugaNeighbor_timestamp exchange(::beluga_messages::msg::BelugaNeighbor::_exchange_type arg)
  {
    msg_.exchange = std::move(arg);
    return Init_BelugaNeighbor_timestamp(msg_);
  }

private:
  ::beluga_messages::msg::BelugaNeighbor msg_;
};

class Init_BelugaNeighbor_rssi
{
public:
  explicit Init_BelugaNeighbor_rssi(::beluga_messages::msg::BelugaNeighbor & msg)
  : msg_(msg)
  {}
  Init_BelugaNeighbor_exchange rssi(::beluga_messages::msg::BelugaNeighbor::_rssi_type arg)
  {
    msg_.rssi = std::move(arg);
    return Init_BelugaNeighbor_exchange(msg_);
  }

private:
  ::beluga_messages::msg::BelugaNeighbor msg_;
};

class Init_BelugaNeighbor_distance
{
public:
  explicit Init_BelugaNeighbor_distance(::beluga_messages::msg::BelugaNeighbor & msg)
  : msg_(msg)
  {}
  Init_BelugaNeighbor_rssi distance(::beluga_messages::msg::BelugaNeighbor::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_BelugaNeighbor_rssi(msg_);
  }

private:
  ::beluga_messages::msg::BelugaNeighbor msg_;
};

class Init_BelugaNeighbor_id
{
public:
  Init_BelugaNeighbor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BelugaNeighbor_distance id(::beluga_messages::msg::BelugaNeighbor::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_BelugaNeighbor_distance(msg_);
  }

private:
  ::beluga_messages::msg::BelugaNeighbor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::beluga_messages::msg::BelugaNeighbor>()
{
  return beluga_messages::msg::builder::Init_BelugaNeighbor_id();
}

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBOR__BUILDER_HPP_
