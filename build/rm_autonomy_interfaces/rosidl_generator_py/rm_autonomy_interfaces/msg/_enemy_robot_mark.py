# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_autonomy_interfaces:msg/EnemyRobotMark.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EnemyRobotMark(type):
    """Metaclass of message 'EnemyRobotMark'."""

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
                'rm_autonomy_interfaces.msg.EnemyRobotMark')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__enemy_robot_mark
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__enemy_robot_mark
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__enemy_robot_mark
            cls._TYPE_SUPPORT = module.type_support_msg__msg__enemy_robot_mark
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__enemy_robot_mark

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EnemyRobotMark(metaclass=Metaclass_EnemyRobotMark):
    """Message class 'EnemyRobotMark'."""

    __slots__ = [
        '_enemy_1_mark',
        '_enemy_2_mark',
        '_enemy_3_mark',
        '_enemy_4_mark',
        '_enemy_5_mark',
        '_enemy_7_mark',
    ]

    _fields_and_field_types = {
        'enemy_1_mark': 'uint8',
        'enemy_2_mark': 'uint8',
        'enemy_3_mark': 'uint8',
        'enemy_4_mark': 'uint8',
        'enemy_5_mark': 'uint8',
        'enemy_7_mark': 'uint8',
    }

    SLOT_TYPES = (
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
        self.enemy_1_mark = kwargs.get('enemy_1_mark', int())
        self.enemy_2_mark = kwargs.get('enemy_2_mark', int())
        self.enemy_3_mark = kwargs.get('enemy_3_mark', int())
        self.enemy_4_mark = kwargs.get('enemy_4_mark', int())
        self.enemy_5_mark = kwargs.get('enemy_5_mark', int())
        self.enemy_7_mark = kwargs.get('enemy_7_mark', int())

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
        if self.enemy_1_mark != other.enemy_1_mark:
            return False
        if self.enemy_2_mark != other.enemy_2_mark:
            return False
        if self.enemy_3_mark != other.enemy_3_mark:
            return False
        if self.enemy_4_mark != other.enemy_4_mark:
            return False
        if self.enemy_5_mark != other.enemy_5_mark:
            return False
        if self.enemy_7_mark != other.enemy_7_mark:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def enemy_1_mark(self):
        """Message field 'enemy_1_mark'."""
        return self._enemy_1_mark

    @enemy_1_mark.setter
    def enemy_1_mark(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_1_mark' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_1_mark' field must be an unsigned integer in [0, 255]"
        self._enemy_1_mark = value

    @property
    def enemy_2_mark(self):
        """Message field 'enemy_2_mark'."""
        return self._enemy_2_mark

    @enemy_2_mark.setter
    def enemy_2_mark(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_2_mark' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_2_mark' field must be an unsigned integer in [0, 255]"
        self._enemy_2_mark = value

    @property
    def enemy_3_mark(self):
        """Message field 'enemy_3_mark'."""
        return self._enemy_3_mark

    @enemy_3_mark.setter
    def enemy_3_mark(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_3_mark' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_3_mark' field must be an unsigned integer in [0, 255]"
        self._enemy_3_mark = value

    @property
    def enemy_4_mark(self):
        """Message field 'enemy_4_mark'."""
        return self._enemy_4_mark

    @enemy_4_mark.setter
    def enemy_4_mark(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_4_mark' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_4_mark' field must be an unsigned integer in [0, 255]"
        self._enemy_4_mark = value

    @property
    def enemy_5_mark(self):
        """Message field 'enemy_5_mark'."""
        return self._enemy_5_mark

    @enemy_5_mark.setter
    def enemy_5_mark(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_5_mark' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_5_mark' field must be an unsigned integer in [0, 255]"
        self._enemy_5_mark = value

    @property
    def enemy_7_mark(self):
        """Message field 'enemy_7_mark'."""
        return self._enemy_7_mark

    @enemy_7_mark.setter
    def enemy_7_mark(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_7_mark' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_7_mark' field must be an unsigned integer in [0, 255]"
        self._enemy_7_mark = value
