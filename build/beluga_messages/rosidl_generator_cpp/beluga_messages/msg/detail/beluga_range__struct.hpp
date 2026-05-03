// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from beluga_messages:msg/BelugaRange.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__STRUCT_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__beluga_messages__msg__BelugaRange __attribute__((deprecated))
#else
# define DEPRECATED__beluga_messages__msg__BelugaRange __declspec(deprecated)
#endif

namespace beluga_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BelugaRange_
{
  using Type = BelugaRange_<ContainerAllocator>;

  explicit BelugaRange_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->range = 0.0f;
      this->exchange = 0ul;
      this->maxnoise = 0;
      this->firstpathamp1 = 0;
      this->firstpathamp2 = 0;
      this->firstpathamp3 = 0;
      this->stdnoise = 0;
      this->maxgrowthcir = 0;
      this->rxpreamcount = 0;
      this->firstpath = 0;
    }
  }

  explicit BelugaRange_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->range = 0.0f;
      this->exchange = 0ul;
      this->maxnoise = 0;
      this->firstpathamp1 = 0;
      this->firstpathamp2 = 0;
      this->firstpathamp3 = 0;
      this->stdnoise = 0;
      this->maxgrowthcir = 0;
      this->rxpreamcount = 0;
      this->firstpath = 0;
    }
  }

  // field types and members
  using _id_type =
    uint16_t;
  _id_type id;
  using _range_type =
    float;
  _range_type range;
  using _exchange_type =
    uint32_t;
  _exchange_type exchange;
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _maxnoise_type =
    uint16_t;
  _maxnoise_type maxnoise;
  using _firstpathamp1_type =
    uint16_t;
  _firstpathamp1_type firstpathamp1;
  using _firstpathamp2_type =
    uint16_t;
  _firstpathamp2_type firstpathamp2;
  using _firstpathamp3_type =
    uint16_t;
  _firstpathamp3_type firstpathamp3;
  using _stdnoise_type =
    uint16_t;
  _stdnoise_type stdnoise;
  using _maxgrowthcir_type =
    uint16_t;
  _maxgrowthcir_type maxgrowthcir;
  using _rxpreamcount_type =
    uint16_t;
  _rxpreamcount_type rxpreamcount;
  using _firstpath_type =
    uint16_t;
  _firstpath_type firstpath;

  // setters for named parameter idiom
  Type & set__id(
    const uint16_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__range(
    const float & _arg)
  {
    this->range = _arg;
    return *this;
  }
  Type & set__exchange(
    const uint32_t & _arg)
  {
    this->exchange = _arg;
    return *this;
  }
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__maxnoise(
    const uint16_t & _arg)
  {
    this->maxnoise = _arg;
    return *this;
  }
  Type & set__firstpathamp1(
    const uint16_t & _arg)
  {
    this->firstpathamp1 = _arg;
    return *this;
  }
  Type & set__firstpathamp2(
    const uint16_t & _arg)
  {
    this->firstpathamp2 = _arg;
    return *this;
  }
  Type & set__firstpathamp3(
    const uint16_t & _arg)
  {
    this->firstpathamp3 = _arg;
    return *this;
  }
  Type & set__stdnoise(
    const uint16_t & _arg)
  {
    this->stdnoise = _arg;
    return *this;
  }
  Type & set__maxgrowthcir(
    const uint16_t & _arg)
  {
    this->maxgrowthcir = _arg;
    return *this;
  }
  Type & set__rxpreamcount(
    const uint16_t & _arg)
  {
    this->rxpreamcount = _arg;
    return *this;
  }
  Type & set__firstpath(
    const uint16_t & _arg)
  {
    this->firstpath = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    beluga_messages::msg::BelugaRange_<ContainerAllocator> *;
  using ConstRawPtr =
    const beluga_messages::msg::BelugaRange_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<beluga_messages::msg::BelugaRange_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<beluga_messages::msg::BelugaRange_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      beluga_messages::msg::BelugaRange_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::msg::BelugaRange_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      beluga_messages::msg::BelugaRange_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::msg::BelugaRange_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<beluga_messages::msg::BelugaRange_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<beluga_messages::msg::BelugaRange_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__beluga_messages__msg__BelugaRange
    std::shared_ptr<beluga_messages::msg::BelugaRange_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__beluga_messages__msg__BelugaRange
    std::shared_ptr<beluga_messages::msg::BelugaRange_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BelugaRange_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->range != other.range) {
      return false;
    }
    if (this->exchange != other.exchange) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->maxnoise != other.maxnoise) {
      return false;
    }
    if (this->firstpathamp1 != other.firstpathamp1) {
      return false;
    }
    if (this->firstpathamp2 != other.firstpathamp2) {
      return false;
    }
    if (this->firstpathamp3 != other.firstpathamp3) {
      return false;
    }
    if (this->stdnoise != other.stdnoise) {
      return false;
    }
    if (this->maxgrowthcir != other.maxgrowthcir) {
      return false;
    }
    if (this->rxpreamcount != other.rxpreamcount) {
      return false;
    }
    if (this->firstpath != other.firstpath) {
      return false;
    }
    return true;
  }
  bool operator!=(const BelugaRange_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BelugaRange_

// alias to use template instance with default allocator
using BelugaRange =
  beluga_messages::msg::BelugaRange_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGE__STRUCT_HPP_
