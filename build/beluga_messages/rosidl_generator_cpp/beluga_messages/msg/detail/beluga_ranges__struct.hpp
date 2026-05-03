// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from beluga_messages:msg/BelugaRanges.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGES__STRUCT_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'ranges'
#include "beluga_messages/msg/detail/beluga_range__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__beluga_messages__msg__BelugaRanges __attribute__((deprecated))
#else
# define DEPRECATED__beluga_messages__msg__BelugaRanges __declspec(deprecated)
#endif

namespace beluga_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BelugaRanges_
{
  using Type = BelugaRanges_<ContainerAllocator>;

  explicit BelugaRanges_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit BelugaRanges_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _ranges_type =
    std::vector<beluga_messages::msg::BelugaRange_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<beluga_messages::msg::BelugaRange_<ContainerAllocator>>>;
  _ranges_type ranges;

  // setters for named parameter idiom
  Type & set__ranges(
    const std::vector<beluga_messages::msg::BelugaRange_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<beluga_messages::msg::BelugaRange_<ContainerAllocator>>> & _arg)
  {
    this->ranges = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    beluga_messages::msg::BelugaRanges_<ContainerAllocator> *;
  using ConstRawPtr =
    const beluga_messages::msg::BelugaRanges_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<beluga_messages::msg::BelugaRanges_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<beluga_messages::msg::BelugaRanges_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      beluga_messages::msg::BelugaRanges_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::msg::BelugaRanges_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      beluga_messages::msg::BelugaRanges_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::msg::BelugaRanges_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<beluga_messages::msg::BelugaRanges_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<beluga_messages::msg::BelugaRanges_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__beluga_messages__msg__BelugaRanges
    std::shared_ptr<beluga_messages::msg::BelugaRanges_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__beluga_messages__msg__BelugaRanges
    std::shared_ptr<beluga_messages::msg::BelugaRanges_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BelugaRanges_ & other) const
  {
    if (this->ranges != other.ranges) {
      return false;
    }
    return true;
  }
  bool operator!=(const BelugaRanges_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BelugaRanges_

// alias to use template instance with default allocator
using BelugaRanges =
  beluga_messages::msg::BelugaRanges_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_RANGES__STRUCT_HPP_
