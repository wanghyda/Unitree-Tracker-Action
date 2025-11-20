# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_autonomy_interfaces:msg/AllyRobotPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AllyRobotPosition(type):
    """Metaclass of message 'AllyRobotPosition'."""

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
                'rm_autonomy_interfaces.msg.AllyRobotPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ally_robot_position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ally_robot_position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ally_robot_position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ally_robot_position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ally_robot_position

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AllyRobotPosition(metaclass=Metaclass_AllyRobotPosition):
    """Message class 'AllyRobotPosition'."""

    __slots__ = [
        '_ally_1_position_x',
        '_ally_1_position_y',
        '_ally_2_position_x',
        '_ally_2_position_y',
        '_ally_3_position_x',
        '_ally_3_position_y',
        '_ally_4_position_x',
        '_ally_4_position_y',
        '_ally_5_position_x',
        '_ally_5_position_y',
        '_ally_7_position_x',
        '_ally_7_position_y',
    ]

    _fields_and_field_types = {
        'ally_1_position_x': 'float',
        'ally_1_position_y': 'float',
        'ally_2_position_x': 'float',
        'ally_2_position_y': 'float',
        'ally_3_position_x': 'float',
        'ally_3_position_y': 'float',
        'ally_4_position_x': 'float',
        'ally_4_position_y': 'float',
        'ally_5_position_x': 'float',
        'ally_5_position_y': 'float',
        'ally_7_position_x': 'float',
        'ally_7_position_y': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ally_1_position_x = kwargs.get('ally_1_position_x', float())
        self.ally_1_position_y = kwargs.get('ally_1_position_y', float())
        self.ally_2_position_x = kwargs.get('ally_2_position_x', float())
        self.ally_2_position_y = kwargs.get('ally_2_position_y', float())
        self.ally_3_position_x = kwargs.get('ally_3_position_x', float())
        self.ally_3_position_y = kwargs.get('ally_3_position_y', float())
        self.ally_4_position_x = kwargs.get('ally_4_position_x', float())
        self.ally_4_position_y = kwargs.get('ally_4_position_y', float())
        self.ally_5_position_x = kwargs.get('ally_5_position_x', float())
        self.ally_5_position_y = kwargs.get('ally_5_position_y', float())
        self.ally_7_position_x = kwargs.get('ally_7_position_x', float())
        self.ally_7_position_y = kwargs.get('ally_7_position_y', float())

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
        if self.ally_1_position_x != other.ally_1_position_x:
            return False
        if self.ally_1_position_y != other.ally_1_position_y:
            return False
        if self.ally_2_position_x != other.ally_2_position_x:
            return False
        if self.ally_2_position_y != other.ally_2_position_y:
            return False
        if self.ally_3_position_x != other.ally_3_position_x:
            return False
        if self.ally_3_position_y != other.ally_3_position_y:
            return False
        if self.ally_4_position_x != other.ally_4_position_x:
            return False
        if self.ally_4_position_y != other.ally_4_position_y:
            return False
        if self.ally_5_position_x != other.ally_5_position_x:
            return False
        if self.ally_5_position_y != other.ally_5_position_y:
            return False
        if self.ally_7_position_x != other.ally_7_position_x:
            return False
        if self.ally_7_position_y != other.ally_7_position_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def ally_1_position_x(self):
        """Message field 'ally_1_position_x'."""
        return self._ally_1_position_x

    @ally_1_position_x.setter
    def ally_1_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_1_position_x' field must be of type 'float'"
        self._ally_1_position_x = value

    @property
    def ally_1_position_y(self):
        """Message field 'ally_1_position_y'."""
        return self._ally_1_position_y

    @ally_1_position_y.setter
    def ally_1_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_1_position_y' field must be of type 'float'"
        self._ally_1_position_y = value

    @property
    def ally_2_position_x(self):
        """Message field 'ally_2_position_x'."""
        return self._ally_2_position_x

    @ally_2_position_x.setter
    def ally_2_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_2_position_x' field must be of type 'float'"
        self._ally_2_position_x = value

    @property
    def ally_2_position_y(self):
        """Message field 'ally_2_position_y'."""
        return self._ally_2_position_y

    @ally_2_position_y.setter
    def ally_2_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_2_position_y' field must be of type 'float'"
        self._ally_2_position_y = value

    @property
    def ally_3_position_x(self):
        """Message field 'ally_3_position_x'."""
        return self._ally_3_position_x

    @ally_3_position_x.setter
    def ally_3_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_3_position_x' field must be of type 'float'"
        self._ally_3_position_x = value

    @property
    def ally_3_position_y(self):
        """Message field 'ally_3_position_y'."""
        return self._ally_3_position_y

    @ally_3_position_y.setter
    def ally_3_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_3_position_y' field must be of type 'float'"
        self._ally_3_position_y = value

    @property
    def ally_4_position_x(self):
        """Message field 'ally_4_position_x'."""
        return self._ally_4_position_x

    @ally_4_position_x.setter
    def ally_4_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_4_position_x' field must be of type 'float'"
        self._ally_4_position_x = value

    @property
    def ally_4_position_y(self):
        """Message field 'ally_4_position_y'."""
        return self._ally_4_position_y

    @ally_4_position_y.setter
    def ally_4_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_4_position_y' field must be of type 'float'"
        self._ally_4_position_y = value

    @property
    def ally_5_position_x(self):
        """Message field 'ally_5_position_x'."""
        return self._ally_5_position_x

    @ally_5_position_x.setter
    def ally_5_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_5_position_x' field must be of type 'float'"
        self._ally_5_position_x = value

    @property
    def ally_5_position_y(self):
        """Message field 'ally_5_position_y'."""
        return self._ally_5_position_y

    @ally_5_position_y.setter
    def ally_5_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_5_position_y' field must be of type 'float'"
        self._ally_5_position_y = value

    @property
    def ally_7_position_x(self):
        """Message field 'ally_7_position_x'."""
        return self._ally_7_position_x

    @ally_7_position_x.setter
    def ally_7_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_7_position_x' field must be of type 'float'"
        self._ally_7_position_x = value

    @property
    def ally_7_position_y(self):
        """Message field 'ally_7_position_y'."""
        return self._ally_7_position_y

    @ally_7_position_y.setter
    def ally_7_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ally_7_position_y' field must be of type 'float'"
        self._ally_7_position_y = value
