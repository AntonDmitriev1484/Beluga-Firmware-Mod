// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from beluga_messages:msg/BelugaExchange.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_EXCHANGE__BUILDER_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_EXCHANGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "beluga_messages/msg/detail/beluga_exchange__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace beluga_messages
{

namespace msg
{

namespace builder
{

class Init_BelugaExchange_timestamp
{
public:
  explicit Init_BelugaExchange_timestamp(::beluga_messages::msg::BelugaExchange & msg)
  : msg_(msg)
  {}
  ::beluga_messages::msg::BelugaExchange timestamp(::beluga_messages::msg::BelugaExchange::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::beluga_messages::msg::BelugaExchange msg_;
};

class Init_BelugaExchange_exchange
{
public:
  explicit Init_BelugaExchange_exchange(::beluga_messages::msg::BelugaExchange & msg)
  : msg_(msg)
  {}
  Init_BelugaExchange_timestamp exchange(::beluga_messages::msg::BelugaExchange::_exchange_type arg)
  {
    msg_.exchange = std::move(arg);
    return Init_BelugaExchange_timestamp(msg_);
  }

private:
  ::beluga_messages::msg::BelugaExchange msg_;
};

class Init_BelugaExchange_id
{
public:
  Init_BelugaExchange_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BelugaExchange_exchange id(::beluga_messages::msg::BelugaExchange::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_BelugaExchange_exchange(msg_);
  }

private:
  ::beluga_messages::msg::BelugaExchange msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::beluga_messages::msg::BelugaExchange>()
{
  return beluga_messages::msg::builder::Init_BelugaExchange_id();
}

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_EXCHANGE__BUILDER_HPP_
