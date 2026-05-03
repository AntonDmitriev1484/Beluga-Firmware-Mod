# generated from rosidl_generator_py/resource/_idl.py.em
# with input from beluga_messages:srv/BelugaATCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BelugaATCommand_Request(type):
    """Metaclass of message 'BelugaATCommand_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'AT_COMMAND_STARTUWB': 0,
        'AT_COMMAND_STOPUWB': 1,
        'AT_COMMAND_STARTBLE': 2,
        'AT_COMMAND_STOPBLE': 3,
        'AT_COMMAND_ID': 4,
        'AT_COMMAND_BOOTMODE': 5,
        'AT_COMMAND_RATE': 6,
        'AT_COMMAND_CHANNEL': 7,
        'AT_COMMAND_RESET': 8,
        'AT_COMMAND_TIMEOUT': 9,
        'AT_COMMAND_TXPOWER': 10,
        'AT_COMMAND_STREAMMODE': 11,
        'AT_COMMAND_TWRMODE': 12,
        'AT_COMMAND_LEDMODE': 13,
        'AT_COMMAND_REBOOT': 14,
        'AT_COMMAND_PWRAMP': 15,
        'AT_COMMAND_ANTENNA': 16,
        'AT_COMMAND_TIME': 17,
        'AT_COMMAND_DEEPSLEEP': 18,
        'AT_COMMAND_DATARATE': 19,
        'AT_COMMAND_PREAMBLE': 20,
        'AT_COMMAND_PULSERATE': 21,
        'AT_COMMAND_PHR': 22,
        'AT_COMMAND_PAC': 23,
        'AT_COMMAND_SFD': 24,
        'AT_COMMAND_PANID': 25,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('beluga_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'beluga_messages.srv.BelugaATCommand_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__beluga_at_command__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__beluga_at_command__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__beluga_at_command__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__beluga_at_command__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__beluga_at_command__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'AT_COMMAND_STARTUWB': cls.__constants['AT_COMMAND_STARTUWB'],
            'AT_COMMAND_STOPUWB': cls.__constants['AT_COMMAND_STOPUWB'],
            'AT_COMMAND_STARTBLE': cls.__constants['AT_COMMAND_STARTBLE'],
            'AT_COMMAND_STOPBLE': cls.__constants['AT_COMMAND_STOPBLE'],
            'AT_COMMAND_ID': cls.__constants['AT_COMMAND_ID'],
            'AT_COMMAND_BOOTMODE': cls.__constants['AT_COMMAND_BOOTMODE'],
            'AT_COMMAND_RATE': cls.__constants['AT_COMMAND_RATE'],
            'AT_COMMAND_CHANNEL': cls.__constants['AT_COMMAND_CHANNEL'],
            'AT_COMMAND_RESET': cls.__constants['AT_COMMAND_RESET'],
            'AT_COMMAND_TIMEOUT': cls.__constants['AT_COMMAND_TIMEOUT'],
            'AT_COMMAND_TXPOWER': cls.__constants['AT_COMMAND_TXPOWER'],
            'AT_COMMAND_STREAMMODE': cls.__constants['AT_COMMAND_STREAMMODE'],
            'AT_COMMAND_TWRMODE': cls.__constants['AT_COMMAND_TWRMODE'],
            'AT_COMMAND_LEDMODE': cls.__constants['AT_COMMAND_LEDMODE'],
            'AT_COMMAND_REBOOT': cls.__constants['AT_COMMAND_REBOOT'],
            'AT_COMMAND_PWRAMP': cls.__constants['AT_COMMAND_PWRAMP'],
            'AT_COMMAND_ANTENNA': cls.__constants['AT_COMMAND_ANTENNA'],
            'AT_COMMAND_TIME': cls.__constants['AT_COMMAND_TIME'],
            'AT_COMMAND_DEEPSLEEP': cls.__constants['AT_COMMAND_DEEPSLEEP'],
            'AT_COMMAND_DATARATE': cls.__constants['AT_COMMAND_DATARATE'],
            'AT_COMMAND_PREAMBLE': cls.__constants['AT_COMMAND_PREAMBLE'],
            'AT_COMMAND_PULSERATE': cls.__constants['AT_COMMAND_PULSERATE'],
            'AT_COMMAND_PHR': cls.__constants['AT_COMMAND_PHR'],
            'AT_COMMAND_PAC': cls.__constants['AT_COMMAND_PAC'],
            'AT_COMMAND_SFD': cls.__constants['AT_COMMAND_SFD'],
            'AT_COMMAND_PANID': cls.__constants['AT_COMMAND_PANID'],
        }

    @property
    def AT_COMMAND_STARTUWB(self):
        """Message constant 'AT_COMMAND_STARTUWB'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_STARTUWB']

    @property
    def AT_COMMAND_STOPUWB(self):
        """Message constant 'AT_COMMAND_STOPUWB'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_STOPUWB']

    @property
    def AT_COMMAND_STARTBLE(self):
        """Message constant 'AT_COMMAND_STARTBLE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_STARTBLE']

    @property
    def AT_COMMAND_STOPBLE(self):
        """Message constant 'AT_COMMAND_STOPBLE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_STOPBLE']

    @property
    def AT_COMMAND_ID(self):
        """Message constant 'AT_COMMAND_ID'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_ID']

    @property
    def AT_COMMAND_BOOTMODE(self):
        """Message constant 'AT_COMMAND_BOOTMODE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_BOOTMODE']

    @property
    def AT_COMMAND_RATE(self):
        """Message constant 'AT_COMMAND_RATE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_RATE']

    @property
    def AT_COMMAND_CHANNEL(self):
        """Message constant 'AT_COMMAND_CHANNEL'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_CHANNEL']

    @property
    def AT_COMMAND_RESET(self):
        """Message constant 'AT_COMMAND_RESET'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_RESET']

    @property
    def AT_COMMAND_TIMEOUT(self):
        """Message constant 'AT_COMMAND_TIMEOUT'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_TIMEOUT']

    @property
    def AT_COMMAND_TXPOWER(self):
        """Message constant 'AT_COMMAND_TXPOWER'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_TXPOWER']

    @property
    def AT_COMMAND_STREAMMODE(self):
        """Message constant 'AT_COMMAND_STREAMMODE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_STREAMMODE']

    @property
    def AT_COMMAND_TWRMODE(self):
        """Message constant 'AT_COMMAND_TWRMODE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_TWRMODE']

    @property
    def AT_COMMAND_LEDMODE(self):
        """Message constant 'AT_COMMAND_LEDMODE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_LEDMODE']

    @property
    def AT_COMMAND_REBOOT(self):
        """Message constant 'AT_COMMAND_REBOOT'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_REBOOT']

    @property
    def AT_COMMAND_PWRAMP(self):
        """Message constant 'AT_COMMAND_PWRAMP'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_PWRAMP']

    @property
    def AT_COMMAND_ANTENNA(self):
        """Message constant 'AT_COMMAND_ANTENNA'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_ANTENNA']

    @property
    def AT_COMMAND_TIME(self):
        """Message constant 'AT_COMMAND_TIME'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_TIME']

    @property
    def AT_COMMAND_DEEPSLEEP(self):
        """Message constant 'AT_COMMAND_DEEPSLEEP'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_DEEPSLEEP']

    @property
    def AT_COMMAND_DATARATE(self):
        """Message constant 'AT_COMMAND_DATARATE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_DATARATE']

    @property
    def AT_COMMAND_PREAMBLE(self):
        """Message constant 'AT_COMMAND_PREAMBLE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_PREAMBLE']

    @property
    def AT_COMMAND_PULSERATE(self):
        """Message constant 'AT_COMMAND_PULSERATE'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_PULSERATE']

    @property
    def AT_COMMAND_PHR(self):
        """Message constant 'AT_COMMAND_PHR'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_PHR']

    @property
    def AT_COMMAND_PAC(self):
        """Message constant 'AT_COMMAND_PAC'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_PAC']

    @property
    def AT_COMMAND_SFD(self):
        """Message constant 'AT_COMMAND_SFD'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_SFD']

    @property
    def AT_COMMAND_PANID(self):
        """Message constant 'AT_COMMAND_PANID'."""
        return Metaclass_BelugaATCommand_Request.__constants['AT_COMMAND_PANID']


class BelugaATCommand_Request(metaclass=Metaclass_BelugaATCommand_Request):
    """
    Message class 'BelugaATCommand_Request'.

    Constants:
      AT_COMMAND_STARTUWB
      AT_COMMAND_STOPUWB
      AT_COMMAND_STARTBLE
      AT_COMMAND_STOPBLE
      AT_COMMAND_ID
      AT_COMMAND_BOOTMODE
      AT_COMMAND_RATE
      AT_COMMAND_CHANNEL
      AT_COMMAND_RESET
      AT_COMMAND_TIMEOUT
      AT_COMMAND_TXPOWER
      AT_COMMAND_STREAMMODE
      AT_COMMAND_TWRMODE
      AT_COMMAND_LEDMODE
      AT_COMMAND_REBOOT
      AT_COMMAND_PWRAMP
      AT_COMMAND_ANTENNA
      AT_COMMAND_TIME
      AT_COMMAND_DEEPSLEEP
      AT_COMMAND_DATARATE
      AT_COMMAND_PREAMBLE
      AT_COMMAND_PULSERATE
      AT_COMMAND_PHR
      AT_COMMAND_PAC
      AT_COMMAND_SFD
      AT_COMMAND_PANID
    """

    __slots__ = [
        '_arg',
        '_at_command',
    ]

    _fields_and_field_types = {
        'arg': 'string',
        'at_command': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.arg = kwargs.get('arg', str())
        self.at_command = kwargs.get('at_command', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.arg != other.arg:
            return False
        if self.at_command != other.at_command:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def arg(self):
        """Message field 'arg'."""
        return self._arg

    @arg.setter
    def arg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'arg' field must be of type 'str'"
        self._arg = value

    @builtins.property
    def at_command(self):
        """Message field 'at_command'."""
        return self._at_command

    @at_command.setter
    def at_command(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'at_command' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'at_command' field must be an unsigned integer in [0, 255]"
        self._at_command = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_BelugaATCommand_Response(type):
    """Metaclass of message 'BelugaATCommand_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('beluga_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'beluga_messages.srv.BelugaATCommand_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__beluga_at_command__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__beluga_at_command__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__beluga_at_command__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__beluga_at_command__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__beluga_at_command__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BelugaATCommand_Response(metaclass=Metaclass_BelugaATCommand_Response):
    """Message class 'BelugaATCommand_Response'."""

    __slots__ = [
        '_response',
    ]

    _fields_and_field_types = {
        'response': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.response = kwargs.get('response', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'response' field must be of type 'str'"
        self._response = value


class Metaclass_BelugaATCommand(type):
    """Metaclass of service 'BelugaATCommand'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('beluga_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'beluga_messages.srv.BelugaATCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__beluga_at_command

            from beluga_messages.srv import _beluga_at_command
            if _beluga_at_command.Metaclass_BelugaATCommand_Request._TYPE_SUPPORT is None:
                _beluga_at_command.Metaclass_BelugaATCommand_Request.__import_type_support__()
            if _beluga_at_command.Metaclass_BelugaATCommand_Response._TYPE_SUPPORT is None:
                _beluga_at_command.Metaclass_BelugaATCommand_Response.__import_type_support__()


class BelugaATCommand(metaclass=Metaclass_BelugaATCommand):
    from beluga_messages.srv._beluga_at_command import BelugaATCommand_Request as Request
    from beluga_messages.srv._beluga_at_command import BelugaATCommand_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
