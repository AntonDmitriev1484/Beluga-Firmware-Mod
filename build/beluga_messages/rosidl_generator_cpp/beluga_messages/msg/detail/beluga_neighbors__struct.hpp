// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from beluga_messages:msg/BelugaNeighbors.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBORS__STRUCT_HPP_
#define BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBORS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'neighbors'
#include "beluga_messages/msg/detail/beluga_neighbor__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__beluga_messages__msg__BelugaNeighbors __attribute__((deprecated))
#else
# define DEPRECATED__beluga_messages__msg__BelugaNeighbors __declspec(deprecated)
#endif

namespace beluga_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BelugaNeighbors_
{
  using Type = BelugaNeighbors_<ContainerAllocator>;

  explicit BelugaNeighbors_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit BelugaNeighbors_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _neighbors_type =
    std::vector<beluga_messages::msg::BelugaNeighbor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<beluga_messages::msg::BelugaNeighbor_<ContainerAllocator>>>;
  _neighbors_type neighbors;

  // setters for named parameter idiom
  Type & set__neighbors(
    const std::vector<beluga_messages::msg::BelugaNeighbor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<beluga_messages::msg::BelugaNeighbor_<ContainerAllocator>>> & _arg)
  {
    this->neighbors = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    beluga_messages::msg::BelugaNeighbors_<ContainerAllocator> *;
  using ConstRawPtr =
    const beluga_messages::msg::BelugaNeighbors_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<beluga_messages::msg::BelugaNeighbors_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<beluga_messages::msg::BelugaNeighbors_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      beluga_messages::msg::BelugaNeighbors_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::msg::BelugaNeighbors_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      beluga_messages::msg::BelugaNeighbors_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::msg::BelugaNeighbors_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<beluga_messages::msg::BelugaNeighbors_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<beluga_messages::msg::BelugaNeighbors_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__beluga_messages__msg__BelugaNeighbors
    std::shared_ptr<beluga_messages::msg::BelugaNeighbors_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__beluga_messages__msg__BelugaNeighbors
    std::shared_ptr<beluga_messages::msg::BelugaNeighbors_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BelugaNeighbors_ & other) const
  {
    if (this->neighbors != other.neighbors) {
      return false;
    }
    return true;
  }
  bool operator!=(const BelugaNeighbors_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BelugaNeighbors_

// alias to use template instance with default allocator
using BelugaNeighbors =
  beluga_messages::msg::BelugaNeighbors_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__MSG__DETAIL__BELUGA_NEIGHBORS__STRUCT_HPP_
