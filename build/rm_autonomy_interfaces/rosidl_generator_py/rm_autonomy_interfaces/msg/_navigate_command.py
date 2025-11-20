# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_autonomy_interfaces:msg/NavigateCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavigateCommand(type):
    """Metaclass of message 'NavigateCommand'."""

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
                'rm_autonomy_interfaces.msg.NavigateCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__navigate_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__navigate_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__navigate_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__navigate_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__navigate_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigateCommand(metaclass=Metaclass_NavigateCommand):
    """Message class 'NavigateCommand'."""

    __slots__ = [
        '_spin_speed',
        '_scap_state',
        '_align_chassis_big_yaw',
    ]

    _fields_and_field_types = {
        'spin_speed': 'float',
        'scap_state': 'boolean',
        'align_chassis_big_yaw': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.spin_speed = kwargs.get('spin_speed', float())
        self.scap_state = kwargs.get('scap_state', bool())
        self.align_chassis_big_yaw = kwargs.get('align_chassis_big_yaw', bool())

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
        if self.spin_speed != other.spin_speed:
            return False
        if self.scap_state != other.scap_state:
            return False
        if self.align_chassis_big_yaw != other.align_chassis_big_yaw:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def spin_speed(self):
        """Message field 'spin_speed'."""
        return self._spin_speed

    @spin_speed.setter
    def spin_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'spin_speed' field must be of type 'float'"
        self._spin_speed = value

    @property
    def scap_state(self):
        """Message field 'scap_state'."""
        return self._scap_state

    @scap_state.setter
    def scap_state(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'scap_state' field must be of type 'bool'"
        self._scap_state = value

    @property
    def align_chassis_big_yaw(self):
        """Message field 'align_chassis_big_yaw'."""
        return self._align_chassis_big_yaw

    @align_chassis_big_yaw.setter
    def align_chassis_big_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'align_chassis_big_yaw' field must be of type 'bool'"
        self._align_chassis_big_yaw = value
