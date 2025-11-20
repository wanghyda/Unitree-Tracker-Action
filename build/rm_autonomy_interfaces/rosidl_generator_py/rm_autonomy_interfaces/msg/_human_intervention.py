# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_autonomy_interfaces:msg/HumanIntervention.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HumanIntervention(type):
    """Metaclass of message 'HumanIntervention'."""

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
                'rm_autonomy_interfaces.msg.HumanIntervention')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__human_intervention
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__human_intervention
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__human_intervention
            cls._TYPE_SUPPORT = module.type_support_msg__msg__human_intervention
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__human_intervention

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HumanIntervention(metaclass=Metaclass_HumanIntervention):
    """Message class 'HumanIntervention'."""

    __slots__ = [
        '_command_header',
        '_goal_pose_x',
        '_goal_pose_y',
    ]

    _fields_and_field_types = {
        'command_header': 'uint8',
        'goal_pose_x': 'float',
        'goal_pose_y': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.command_header = kwargs.get('command_header', int())
        self.goal_pose_x = kwargs.get('goal_pose_x', float())
        self.goal_pose_y = kwargs.get('goal_pose_y', float())

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
        if self.command_header != other.command_header:
            return False
        if self.goal_pose_x != other.goal_pose_x:
            return False
        if self.goal_pose_y != other.goal_pose_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def command_header(self):
        """Message field 'command_header'."""
        return self._command_header

    @command_header.setter
    def command_header(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'command_header' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'command_header' field must be an unsigned integer in [0, 255]"
        self._command_header = value

    @property
    def goal_pose_x(self):
        """Message field 'goal_pose_x'."""
        return self._goal_pose_x

    @goal_pose_x.setter
    def goal_pose_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'goal_pose_x' field must be of type 'float'"
        self._goal_pose_x = value

    @property
    def goal_pose_y(self):
        """Message field 'goal_pose_y'."""
        return self._goal_pose_y

    @goal_pose_y.setter
    def goal_pose_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'goal_pose_y' field must be of type 'float'"
        self._goal_pose_y = value
