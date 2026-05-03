# generated from rosidl_generator_py/resource/_idl.py.em
# with input from beluga_messages:msg/BelugaRange.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BelugaRange(type):
    """Metaclass of message 'BelugaRange'."""

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
                'beluga_messages.msg.BelugaRange')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__beluga_range
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__beluga_range
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__beluga_range
            cls._TYPE_SUPPORT = module.type_support_msg__msg__beluga_range
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__beluga_range

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BelugaRange(metaclass=Metaclass_BelugaRange):
    """Message class 'BelugaRange'."""

    __slots__ = [
        '_id',
        '_range',
        '_exchange',
        '_timestamp',
        '_maxnoise',
        '_firstpathamp1',
        '_firstpathamp2',
        '_firstpathamp3',
        '_stdnoise',
        '_maxgrowthcir',
        '_rxpreamcount',
        '_firstpath',
    ]

    _fields_and_field_types = {
        'id': 'uint16',
        'range': 'float',
        'exchange': 'uint32',
        'timestamp': 'builtin_interfaces/Time',
        'maxnoise': 'uint16',
        'firstpathamp1': 'uint16',
        'firstpathamp2': 'uint16',
        'firstpathamp3': 'uint16',
        'stdnoise': 'uint16',
        'maxgrowthcir': 'uint16',
        'rxpreamcount': 'uint16',
        'firstpath': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.range = kwargs.get('range', float())
        self.exchange = kwargs.get('exchange', int())
        from builtin_interfaces.msg import Time
        self.timestamp = kwargs.get('timestamp', Time())
        self.maxnoise = kwargs.get('maxnoise', int())
        self.firstpathamp1 = kwargs.get('firstpathamp1', int())
        self.firstpathamp2 = kwargs.get('firstpathamp2', int())
        self.firstpathamp3 = kwargs.get('firstpathamp3', int())
        self.stdnoise = kwargs.get('stdnoise', int())
        self.maxgrowthcir = kwargs.get('maxgrowthcir', int())
        self.rxpreamcount = kwargs.get('rxpreamcount', int())
        self.firstpath = kwargs.get('firstpath', int())

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
        if self.id != other.id:
            return False
        if self.range != other.range:
            return False
        if self.exchange != other.exchange:
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.maxnoise != other.maxnoise:
            return False
        if self.firstpathamp1 != other.firstpathamp1:
            return False
        if self.firstpathamp2 != other.firstpathamp2:
            return False
        if self.firstpathamp3 != other.firstpathamp3:
            return False
        if self.stdnoise != other.stdnoise:
            return False
        if self.maxgrowthcir != other.maxgrowthcir:
            return False
        if self.rxpreamcount != other.rxpreamcount:
            return False
        if self.firstpath != other.firstpath:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'id' field must be an unsigned integer in [0, 65535]"
        self._id = value

    @builtins.property  # noqa: A003
    def range(self):  # noqa: A003
        """Message field 'range'."""
        return self._range

    @range.setter  # noqa: A003
    def range(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'range' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'range' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._range = value

    @builtins.property
    def exchange(self):
        """Message field 'exchange'."""
        return self._exchange

    @exchange.setter
    def exchange(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'exchange' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'exchange' field must be an unsigned integer in [0, 4294967295]"
        self._exchange = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'timestamp' field must be a sub message of type 'Time'"
        self._timestamp = value

    @builtins.property
    def maxnoise(self):
        """Message field 'maxnoise'."""
        return self._maxnoise

    @maxnoise.setter
    def maxnoise(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'maxnoise' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'maxnoise' field must be an unsigned integer in [0, 65535]"
        self._maxnoise = value

    @builtins.property
    def firstpathamp1(self):
        """Message field 'firstpathamp1'."""
        return self._firstpathamp1

    @firstpathamp1.setter
    def firstpathamp1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'firstpathamp1' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'firstpathamp1' field must be an unsigned integer in [0, 65535]"
        self._firstpathamp1 = value

    @builtins.property
    def firstpathamp2(self):
        """Message field 'firstpathamp2'."""
        return self._firstpathamp2

    @firstpathamp2.setter
    def firstpathamp2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'firstpathamp2' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'firstpathamp2' field must be an unsigned integer in [0, 65535]"
        self._firstpathamp2 = value

    @builtins.property
    def firstpathamp3(self):
        """Message field 'firstpathamp3'."""
        return self._firstpathamp3

    @firstpathamp3.setter
    def firstpathamp3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'firstpathamp3' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'firstpathamp3' field must be an unsigned integer in [0, 65535]"
        self._firstpathamp3 = value

    @builtins.property
    def stdnoise(self):
        """Message field 'stdnoise'."""
        return self._stdnoise

    @stdnoise.setter
    def stdnoise(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'stdnoise' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'stdnoise' field must be an unsigned integer in [0, 65535]"
        self._stdnoise = value

    @builtins.property
    def maxgrowthcir(self):
        """Message field 'maxgrowthcir'."""
        return self._maxgrowthcir

    @maxgrowthcir.setter
    def maxgrowthcir(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'maxgrowthcir' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'maxgrowthcir' field must be an unsigned integer in [0, 65535]"
        self._maxgrowthcir = value

    @builtins.property
    def rxpreamcount(self):
        """Message field 'rxpreamcount'."""
        return self._rxpreamcount

    @rxpreamcount.setter
    def rxpreamcount(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rxpreamcount' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'rxpreamcount' field must be an unsigned integer in [0, 65535]"
        self._rxpreamcount = value

    @builtins.property
    def firstpath(self):
        """Message field 'firstpath'."""
        return self._firstpath

    @firstpath.setter
    def firstpath(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'firstpath' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'firstpath' field must be an unsigned integer in [0, 65535]"
        self._firstpath = value
