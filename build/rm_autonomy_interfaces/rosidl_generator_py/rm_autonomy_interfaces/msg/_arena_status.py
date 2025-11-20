# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_autonomy_interfaces:msg/ArenaStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ArenaStatus(type):
    """Metaclass of message 'ArenaStatus'."""

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
            module = import_type_support('rm_autonomy_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rm_autonomy_interfaces.msg.ArenaStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__arena_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__arena_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__arena_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__arena_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__arena_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ArenaStatus(metaclass=Metaclass_ArenaStatus):
    """Message class 'ArenaStatus'."""

    __slots__ = [
        '_healing_front',
        '_healing_inner',
        '_rmul_healing',
        '_energy_occupy_status',
        '_energy_small_status',
        '_energy_big_status',
        '_ring_highground_status',
        '_trapezoid_highground_status',
        '_base_shield_percentage',
        '_rump_central_buff_status',
    ]

    _fields_and_field_types = {
        'healing_front': 'uint8',
        'healing_inner': 'uint8',
        'rmul_healing': 'uint8',
        'energy_occupy_status': 'uint8',
        'energy_small_status': 'uint8',
        'energy_big_status': 'uint8',
        'ring_highground_status': 'uint8',
        'trapezoid_highground_status': 'uint8',
        'base_shield_percentage': 'uint8',
        'rump_central_buff_status': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.healing_front = kwargs.get('healing_front', int())
        self.healing_inner = kwargs.get('healing_inner', int())
        self.rmul_healing = kwargs.get('rmul_healing', int())
        self.energy_occupy_status = kwargs.get('energy_occupy_status', int())
        self.energy_small_status = kwargs.get('energy_small_status', int())
        self.energy_big_status = kwargs.get('energy_big_status', int())
        self.ring_highground_status = kwargs.get('ring_highground_status', int())
        self.trapezoid_highground_status = kwargs.get('trapezoid_highground_status', int())
        self.base_shield_percentage = kwargs.get('base_shield_percentage', int())
        self.rump_central_buff_status = kwargs.get('rump_central_buff_status', int())

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
        if self.healing_front != other.healing_front:
            return False
        if self.healing_inner != other.healing_inner:
            return False
        if self.rmul_healing != other.rmul_healing:
            return False
        if self.energy_occupy_status != other.energy_occupy_status:
            return False
        if self.energy_small_status != other.energy_small_status:
            return False
        if self.energy_big_status != other.energy_big_status:
            return False
        if self.ring_highground_status != other.ring_highground_status:
            return False
        if self.trapezoid_highground_status != other.trapezoid_highground_status:
            return False
        if self.base_shield_percentage != other.base_shield_percentage:
            return False
        if self.rump_central_buff_status != other.rump_central_buff_status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def healing_front(self):
        """Message field 'healing_front'."""
        return self._healing_front

    @healing_front.setter
    def healing_front(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'healing_front' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'healing_front' field must be an unsigned integer in [0, 255]"
        self._healing_front = value

    @property
    def healing_inner(self):
        """Message field 'healing_inner'."""
        return self._healing_inner

    @healing_inner.setter
    def healing_inner(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'healing_inner' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'healing_inner' field must be an unsigned integer in [0, 255]"
        self._healing_inner = value

    @property
    def rmul_healing(self):
        """Message field 'rmul_healing'."""
        return self._rmul_healing

    @rmul_healing.setter
    def rmul_healing(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rmul_healing' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rmul_healing' field must be an unsigned integer in [0, 255]"
        self._rmul_healing = value

    @property
    def energy_occupy_status(self):
        """Message field 'energy_occupy_status'."""
        return self._energy_occupy_status

    @energy_occupy_status.setter
    def energy_occupy_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'energy_occupy_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'energy_occupy_status' field must be an unsigned integer in [0, 255]"
        self._energy_occupy_status = value

    @property
    def energy_small_status(self):
        """Message field 'energy_small_status'."""
        return self._energy_small_status

    @energy_small_status.setter
    def energy_small_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'energy_small_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'energy_small_status' field must be an unsigned integer in [0, 255]"
        self._energy_small_status = value

    @property
    def energy_big_status(self):
        """Message field 'energy_big_status'."""
        return self._energy_big_status

    @energy_big_status.setter
    def energy_big_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'energy_big_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'energy_big_status' field must be an unsigned integer in [0, 255]"
        self._energy_big_status = value

    @property
    def ring_highground_status(self):
        """Message field 'ring_highground_status'."""
        return self._ring_highground_status

    @ring_highground_status.setter
    def ring_highground_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ring_highground_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'ring_highground_status' field must be an unsigned integer in [0, 255]"
        self._ring_highground_status = value

    @property
    def trapezoid_highground_status(self):
        """Message field 'trapezoid_highground_status'."""
        return self._trapezoid_highground_status

    @trapezoid_highground_status.setter
    def trapezoid_highground_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trapezoid_highground_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'trapezoid_highground_status' field must be an unsigned integer in [0, 255]"
        self._trapezoid_highground_status = value

    @property
    def base_shield_percentage(self):
        """Message field 'base_shield_percentage'."""
        return self._base_shield_percentage

    @base_shield_percentage.setter
    def base_shield_percentage(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'base_shield_percentage' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'base_shield_percentage' field must be an unsigned integer in [0, 255]"
        self._base_shield_percentage = value

    @property
    def rump_central_buff_status(self):
        """Message field 'rump_central_buff_status'."""
        return self._rump_central_buff_status

    @rump_central_buff_status.setter
    def rump_central_buff_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rump_central_buff_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rump_central_buff_status' field must be an unsigned integer in [0, 255]"
        self._rump_central_buff_status = value
