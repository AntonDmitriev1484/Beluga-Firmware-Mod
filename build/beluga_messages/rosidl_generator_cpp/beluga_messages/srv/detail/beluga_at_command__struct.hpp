// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from beluga_messages:srv/BelugaATCommand.idl
// generated code does not contain a copyright notice

#ifndef BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__STRUCT_HPP_
#define BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__beluga_messages__srv__BelugaATCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__beluga_messages__srv__BelugaATCommand_Request __declspec(deprecated)
#endif

namespace beluga_messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BelugaATCommand_Request_
{
  using Type = BelugaATCommand_Request_<ContainerAllocator>;

  explicit BelugaATCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arg = "";
      this->at_command = 0;
    }
  }

  explicit BelugaATCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : arg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arg = "";
      this->at_command = 0;
    }
  }

  // field types and members
  using _arg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _arg_type arg;
  using _at_command_type =
    uint8_t;
  _at_command_type at_command;

  // setters for named parameter idiom
  Type & set__arg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->arg = _arg;
    return *this;
  }
  Type & set__at_command(
    const uint8_t & _arg)
  {
    this->at_command = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t AT_COMMAND_STARTUWB =
    0u;
  static constexpr uint8_t AT_COMMAND_STOPUWB =
    1u;
  static constexpr uint8_t AT_COMMAND_STARTBLE =
    2u;
  static constexpr uint8_t AT_COMMAND_STOPBLE =
    3u;
  static constexpr uint8_t AT_COMMAND_ID =
    4u;
  static constexpr uint8_t AT_COMMAND_BOOTMODE =
    5u;
  static constexpr uint8_t AT_COMMAND_RATE =
    6u;
  static constexpr uint8_t AT_COMMAND_CHANNEL =
    7u;
  static constexpr uint8_t AT_COMMAND_RESET =
    8u;
  static constexpr uint8_t AT_COMMAND_TIMEOUT =
    9u;
  static constexpr uint8_t AT_COMMAND_TXPOWER =
    10u;
  static constexpr uint8_t AT_COMMAND_STREAMMODE =
    11u;
  static constexpr uint8_t AT_COMMAND_TWRMODE =
    12u;
  static constexpr uint8_t AT_COMMAND_LEDMODE =
    13u;
  static constexpr uint8_t AT_COMMAND_REBOOT =
    14u;
  static constexpr uint8_t AT_COMMAND_PWRAMP =
    15u;
  static constexpr uint8_t AT_COMMAND_ANTENNA =
    16u;
  static constexpr uint8_t AT_COMMAND_TIME =
    17u;
  static constexpr uint8_t AT_COMMAND_DEEPSLEEP =
    18u;
  static constexpr uint8_t AT_COMMAND_DATARATE =
    19u;
  static constexpr uint8_t AT_COMMAND_PREAMBLE =
    20u;
  static constexpr uint8_t AT_COMMAND_PULSERATE =
    21u;
  static constexpr uint8_t AT_COMMAND_PHR =
    22u;
  static constexpr uint8_t AT_COMMAND_PAC =
    23u;
  static constexpr uint8_t AT_COMMAND_SFD =
    24u;
  static constexpr uint8_t AT_COMMAND_PANID =
    25u;

  // pointer types
  using RawPtr =
    beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__beluga_messages__srv__BelugaATCommand_Request
    std::shared_ptr<beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__beluga_messages__srv__BelugaATCommand_Request
    std::shared_ptr<beluga_messages::srv::BelugaATCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BelugaATCommand_Request_ & other) const
  {
    if (this->arg != other.arg) {
      return false;
    }
    if (this->at_command != other.at_command) {
      return false;
    }
    return true;
  }
  bool operator!=(const BelugaATCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BelugaATCommand_Request_

// alias to use template instance with default allocator
using BelugaATCommand_Request =
  beluga_messages::srv::BelugaATCommand_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_STARTUWB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_STOPUWB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_STARTBLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_STOPBLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_BOOTMODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_RATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_CHANNEL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_RESET;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_TIMEOUT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_TXPOWER;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_STREAMMODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_TWRMODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_LEDMODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_REBOOT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_PWRAMP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_ANTENNA;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_DEEPSLEEP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_DATARATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_PREAMBLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_PULSERATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_PHR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_PAC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_SFD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BelugaATCommand_Request_<ContainerAllocator>::AT_COMMAND_PANID;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace beluga_messages


#ifndef _WIN32
# define DEPRECATED__beluga_messages__srv__BelugaATCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__beluga_messages__srv__BelugaATCommand_Response __declspec(deprecated)
#endif

namespace beluga_messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BelugaATCommand_Response_
{
  using Type = BelugaATCommand_Response_<ContainerAllocator>;

  explicit BelugaATCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  explicit BelugaATCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  // field types and members
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__beluga_messages__srv__BelugaATCommand_Response
    std::shared_ptr<beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__beluga_messages__srv__BelugaATCommand_Response
    std::shared_ptr<beluga_messages::srv::BelugaATCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BelugaATCommand_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const BelugaATCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BelugaATCommand_Response_

// alias to use template instance with default allocator
using BelugaATCommand_Response =
  beluga_messages::srv::BelugaATCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace beluga_messages

namespace beluga_messages
{

namespace srv
{

struct BelugaATCommand
{
  using Request = beluga_messages::srv::BelugaATCommand_Request;
  using Response = beluga_messages::srv::BelugaATCommand_Response;
};

}  // namespace srv

}  // namespace beluga_messages

#endif  // BELUGA_MESSAGES__SRV__DETAIL__BELUGA_AT_COMMAND__STRUCT_HPP_
