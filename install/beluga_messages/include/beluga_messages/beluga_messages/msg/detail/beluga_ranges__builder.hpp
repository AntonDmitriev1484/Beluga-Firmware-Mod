// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from beluga_messages:msg/BelugaRanges.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGES__BUILDER_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "beluga_messages/msg/detail/beluga_ranges__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace beluga_messages
{

namespace msg
{

namespace builder
{

class Init_BelugaRanges_ranges
{
public:
  Init_BelugaRanges_ranges()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::beluga_messages::msg::BelugaRanges ranges(::beluga_messages::msg::BelugaRanges::_ranges_type arg)
  {
    msg_.ranges = std::move(arg);
    return std::move(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRanges msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::beluga_messages::msg::BelugaRanges>()
{
  return beluga_messages::msg::builder::Init_BelugaRanges_ranges();
}

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGES__BUILDER_HPP_
