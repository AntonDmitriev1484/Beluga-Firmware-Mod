// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from beluga_messages:msg/BelugaRange.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__BUILDER_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "beluga_messages/msg/detail/beluga_range__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace beluga_messages
{

namespace msg
{

namespace builder
{

class Init_BelugaRange_firstpath
{
public:
  explicit Init_BelugaRange_firstpath(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  ::beluga_messages::msg::BelugaRange firstpath(::beluga_messages::msg::BelugaRange::_firstpath_type arg)
  {
    msg_.firstpath = std::move(arg);
    return std::move(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_rxpreamcount
{
public:
  explicit Init_BelugaRange_rxpreamcount(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_firstpath rxpreamcount(::beluga_messages::msg::BelugaRange::_rxpreamcount_type arg)
  {
    msg_.rxpreamcount = std::move(arg);
    return Init_BelugaRange_firstpath(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_maxgrowthcir
{
public:
  explicit Init_BelugaRange_maxgrowthcir(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_rxpreamcount maxgrowthcir(::beluga_messages::msg::BelugaRange::_maxgrowthcir_type arg)
  {
    msg_.maxgrowthcir = std::move(arg);
    return Init_BelugaRange_rxpreamcount(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_stdnoise
{
public:
  explicit Init_BelugaRange_stdnoise(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_maxgrowthcir stdnoise(::beluga_messages::msg::BelugaRange::_stdnoise_type arg)
  {
    msg_.stdnoise = std::move(arg);
    return Init_BelugaRange_maxgrowthcir(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_firstpathamp3
{
public:
  explicit Init_BelugaRange_firstpathamp3(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_stdnoise firstpathamp3(::beluga_messages::msg::BelugaRange::_firstpathamp3_type arg)
  {
    msg_.firstpathamp3 = std::move(arg);
    return Init_BelugaRange_stdnoise(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_firstpathamp2
{
public:
  explicit Init_BelugaRange_firstpathamp2(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_firstpathamp3 firstpathamp2(::beluga_messages::msg::BelugaRange::_firstpathamp2_type arg)
  {
    msg_.firstpathamp2 = std::move(arg);
    return Init_BelugaRange_firstpathamp3(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_firstpathamp1
{
public:
  explicit Init_BelugaRange_firstpathamp1(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_firstpathamp2 firstpathamp1(::beluga_messages::msg::BelugaRange::_firstpathamp1_type arg)
  {
    msg_.firstpathamp1 = std::move(arg);
    return Init_BelugaRange_firstpathamp2(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_maxnoise
{
public:
  explicit Init_BelugaRange_maxnoise(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_firstpathamp1 maxnoise(::beluga_messages::msg::BelugaRange::_maxnoise_type arg)
  {
    msg_.maxnoise = std::move(arg);
    return Init_BelugaRange_firstpathamp1(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_timestamp
{
public:
  explicit Init_BelugaRange_timestamp(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_maxnoise timestamp(::beluga_messages::msg::BelugaRange::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_BelugaRange_maxnoise(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_exchange
{
public:
  explicit Init_BelugaRange_exchange(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_timestamp exchange(::beluga_messages::msg::BelugaRange::_exchange_type arg)
  {
    msg_.exchange = std::move(arg);
    return Init_BelugaRange_timestamp(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_range
{
public:
  explicit Init_BelugaRange_range(::beluga_messages::msg::BelugaRange & msg)
  : msg_(msg)
  {}
  Init_BelugaRange_exchange range(::beluga_messages::msg::BelugaRange::_range_type arg)
  {
    msg_.range = std::move(arg);
    return Init_BelugaRange_exchange(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

class Init_BelugaRange_id
{
public:
  Init_BelugaRange_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BelugaRange_range id(::beluga_messages::msg::BelugaRange::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_BelugaRange_range(msg_);
  }

private:
  ::beluga_messages::msg::BelugaRange msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::beluga_messages::msg::BelugaRange>()
{
  return beluga_messages::msg::builder::Init_BelugaRange_id();
}

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__BUILDER_HPP_
