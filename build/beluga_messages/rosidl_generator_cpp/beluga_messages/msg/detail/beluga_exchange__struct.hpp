// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from beluga_messages:msg/BelugaExchange.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_EXCHANGE__STRUCT_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_EXCHANGE__STRUCT_HPP_

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
# define DEPRECATED__beluga_messages__msg__BelugaExchange __attribute__((deprecated))
#else
# define DEPRECATED__beluga_messages__msg__BelugaExchange __declspec(deprecated)
#endif

namespace beluga_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BelugaExchange_
{
  using Type = BelugaExchange_<ContainerAllocator>;

  explicit BelugaExchange_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->exchange = 0ul;
    }
  }

  explicit BelugaExchange_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->exchange = 0ul;
    }
  }

  // field types and members
  using _id_type =
    uint16_t;
  _id_type id;
  using _exchange_type =
    uint32_t;
  _exchange_type exchange;
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__id(
    const uint16_t & _arg)
  {
    this->id = _arg;
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

  // constant declarations

  // pointer types
  using RawPtr =
    beluga_messages::msg::BelugaExchange_<ContainerAllocator> *;
  using ConstRawPtr =
    const beluga_messages::msg::BelugaExchange_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<beluga_messages::msg::BelugaExchange_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<beluga_messages::msg::BelugaExchange_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      beluga_messages::msg::BelugaExchange_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::msg::BelugaExchange_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      beluga_messages::msg::BelugaExchange_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::msg::BelugaExchange_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<beluga_messages::msg::BelugaExchange_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<beluga_messages::msg::BelugaExchange_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__beluga_messages__msg__BelugaExchange
    std::shared_ptr<beluga_messages::msg::BelugaExchange_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__beluga_messages__msg__BelugaExchange
    std::shared_ptr<beluga_messages::msg::BelugaExchange_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BelugaExchange_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->exchange != other.exchange) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const BelugaExchange_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BelugaExchange_

// alias to use template instance with default allocator
using BelugaExchange =
  beluga_messages::msg::BelugaExchange_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_EXCHANGE__STRUCT_HPP_
