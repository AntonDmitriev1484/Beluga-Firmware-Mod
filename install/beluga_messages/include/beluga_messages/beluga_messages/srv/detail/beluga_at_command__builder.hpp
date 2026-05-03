// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from beluga_messages:srv/BelugaATCommand.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__BUILDER_HPP_
#define BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "beluga_messages/srv/detail/beluga_at_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace beluga_messages
{

namespace srv
{

namespace builder
{

class Init_BelugaATCommand_Request_at_command
{
public:
  explicit Init_BelugaATCommand_Request_at_command(::beluga_messages::srv::BelugaATCommand_Request & msg)
  : msg_(msg)
  {}
  ::beluga_messages::srv::BelugaATCommand_Request at_command(::beluga_messages::srv::BelugaATCommand_Request::_at_command_type arg)
  {
    msg_.at_command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::beluga_messages::srv::BelugaATCommand_Request msg_;
};

class Init_BelugaATCommand_Request_arg
{
public:
  Init_BelugaATCommand_Request_arg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BelugaATCommand_Request_at_command arg(::beluga_messages::srv::BelugaATCommand_Request::_arg_type arg)
  {
    msg_.arg = std::move(arg);
    return Init_BelugaATCommand_Request_at_command(msg_);
  }

private:
  ::beluga_messages::srv::BelugaATCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::beluga_messages::srv::BelugaATCommand_Request>()
{
  return beluga_messages::srv::builder::Init_BelugaATCommand_Request_arg();
}

}  // namespace beluga_messages


namespace beluga_messages
{

namespace srv
{

namespace builder
{

class Init_BelugaATCommand_Response_response
{
public:
  Init_BelugaATCommand_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::beluga_messages::srv::BelugaATCommand_Response response(::beluga_messages::srv::BelugaATCommand_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::beluga_messages::srv::BelugaATCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::beluga_messages::srv::BelugaATCommand_Response>()
{
  return beluga_messages::srv::builder::Init_BelugaATCommand_Response_response();
}

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__BUILDER_HPP_
