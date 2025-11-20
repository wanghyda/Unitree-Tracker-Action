# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_autonomy_interfaces:msg/RadarEnemyPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RadarEnemyPosition(type):
    """Metaclass of message 'RadarEnemyPosition'."""

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
                'rm_autonomy_interfaces.msg.RadarEnemyPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__radar_enemy_position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__radar_enemy_position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__radar_enemy_position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__radar_enemy_position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__radar_enemy_position

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RadarEnemyPosition(metaclass=Metaclass_RadarEnemyPosition):
    """Message class 'RadarEnemyPosition'."""

    __slots__ = [
        '_enemy_1_position_x',
        '_enemy_1_position_y',
        '_enemy_2_position_x',
        '_enemy_2_position_y',
        '_enemy_3_position_x',
        '_enemy_3_position_y',
        '_enemy_4_position_x',
        '_enemy_4_position_y',
        '_enemy_5_position_x',
        '_enemy_5_position_y',
        '_enemy_7_position_x',
        '_enemy_7_position_y',
    ]

    _fields_and_field_types = {
        'enemy_1_position_x': 'float',
        'enemy_1_position_y': 'float',
        'enemy_2_position_x': 'float',
        'enemy_2_position_y': 'float',
        'enemy_3_position_x': 'float',
        'enemy_3_position_y': 'float',
        'enemy_4_position_x': 'float',
        'enemy_4_position_y': 'float',
        'enemy_5_position_x': 'float',
        'enemy_5_position_y': 'float',
        'enemy_7_position_x': 'float',
        'enemy_7_position_y': 'float',
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
        self.enemy_1_position_x = kwargs.get('enemy_1_position_x', float())
        self.enemy_1_position_y = kwargs.get('enemy_1_position_y', float())
        self.enemy_2_position_x = kwargs.get('enemy_2_position_x', float())
        self.enemy_2_position_y = kwargs.get('enemy_2_position_y', float())
        self.enemy_3_position_x = kwargs.get('enemy_3_position_x', float())
        self.enemy_3_position_y = kwargs.get('enemy_3_position_y', float())
        self.enemy_4_position_x = kwargs.get('enemy_4_position_x', float())
        self.enemy_4_position_y = kwargs.get('enemy_4_position_y', float())
        self.enemy_5_position_x = kwargs.get('enemy_5_position_x', float())
        self.enemy_5_position_y = kwargs.get('enemy_5_position_y', float())
        self.enemy_7_position_x = kwargs.get('enemy_7_position_x', float())
        self.enemy_7_position_y = kwargs.get('enemy_7_position_y', float())

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
        if self.enemy_1_position_x != other.enemy_1_position_x:
            return False
        if self.enemy_1_position_y != other.enemy_1_position_y:
            return False
        if self.enemy_2_position_x != other.enemy_2_position_x:
            return False
        if self.enemy_2_position_y != other.enemy_2_position_y:
            return False
        if self.enemy_3_position_x != other.enemy_3_position_x:
            return False
        if self.enemy_3_position_y != other.enemy_3_position_y:
            return False
        if self.enemy_4_position_x != other.enemy_4_position_x:
            return False
        if self.enemy_4_position_y != other.enemy_4_position_y:
            return False
        if self.enemy_5_position_x != other.enemy_5_position_x:
            return False
        if self.enemy_5_position_y != other.enemy_5_position_y:
            return False
        if self.enemy_7_position_x != other.enemy_7_position_x:
            return False
        if self.enemy_7_position_y != other.enemy_7_position_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def enemy_1_position_x(self):
        """Message field 'enemy_1_position_x'."""
        return self._enemy_1_position_x

    @enemy_1_position_x.setter
    def enemy_1_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_1_position_x' field must be of type 'float'"
        self._enemy_1_position_x = value

    @property
    def enemy_1_position_y(self):
        """Message field 'enemy_1_position_y'."""
        return self._enemy_1_position_y

    @enemy_1_position_y.setter
    def enemy_1_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_1_position_y' field must be of type 'float'"
        self._enemy_1_position_y = value

    @property
    def enemy_2_position_x(self):
        """Message field 'enemy_2_position_x'."""
        return self._enemy_2_position_x

    @enemy_2_position_x.setter
    def enemy_2_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_2_position_x' field must be of type 'float'"
        self._enemy_2_position_x = value

    @property
    def enemy_2_position_y(self):
        """Message field 'enemy_2_position_y'."""
        return self._enemy_2_position_y

    @enemy_2_position_y.setter
    def enemy_2_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_2_position_y' field must be of type 'float'"
        self._enemy_2_position_y = value

    @property
    def enemy_3_position_x(self):
        """Message field 'enemy_3_position_x'."""
        return self._enemy_3_position_x

    @enemy_3_position_x.setter
    def enemy_3_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_3_position_x' field must be of type 'float'"
        self._enemy_3_position_x = value

    @property
    def enemy_3_position_y(self):
        """Message field 'enemy_3_position_y'."""
        return self._enemy_3_position_y

    @enemy_3_position_y.setter
    def enemy_3_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_3_position_y' field must be of type 'float'"
        self._enemy_3_position_y = value

    @property
    def enemy_4_position_x(self):
        """Message field 'enemy_4_position_x'."""
        return self._enemy_4_position_x

    @enemy_4_position_x.setter
    def enemy_4_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_4_position_x' field must be of type 'float'"
        self._enemy_4_position_x = value

    @property
    def enemy_4_position_y(self):
        """Message field 'enemy_4_position_y'."""
        return self._enemy_4_position_y

    @enemy_4_position_y.setter
    def enemy_4_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_4_position_y' field must be of type 'float'"
        self._enemy_4_position_y = value

    @property
    def enemy_5_position_x(self):
        """Message field 'enemy_5_position_x'."""
        return self._enemy_5_position_x

    @enemy_5_position_x.setter
    def enemy_5_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_5_position_x' field must be of type 'float'"
        self._enemy_5_position_x = value

    @property
    def enemy_5_position_y(self):
        """Message field 'enemy_5_position_y'."""
        return self._enemy_5_position_y

    @enemy_5_position_y.setter
    def enemy_5_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_5_position_y' field must be of type 'float'"
        self._enemy_5_position_y = value

    @property
    def enemy_7_position_x(self):
        """Message field 'enemy_7_position_x'."""
        return self._enemy_7_position_x

    @enemy_7_position_x.setter
    def enemy_7_position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_7_position_x' field must be of type 'float'"
        self._enemy_7_position_x = value

    @property
    def enemy_7_position_y(self):
        """Message field 'enemy_7_position_y'."""
        return self._enemy_7_position_y

    @enemy_7_position_y.setter
    def enemy_7_position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'enemy_7_position_y' field must be of type 'float'"
        self._enemy_7_position_y = value
