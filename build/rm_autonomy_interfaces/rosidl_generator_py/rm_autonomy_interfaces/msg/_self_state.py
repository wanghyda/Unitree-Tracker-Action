# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_autonomy_interfaces:msg/SelfState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SelfState(type):
    """Metaclass of message 'SelfState'."""

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
                'rm_autonomy_interfaces.msg.SelfState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__self_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__self_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__self_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__self_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__self_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SelfState(metaclass=Metaclass_SelfState):
    """Message class 'SelfState'."""

    __slots__ = [
        '_robot_id',
        '_current_hp',
        '_patrol_rfid',
        '_energy_rfid',
        '_under_attack',
        '_current_ammo',
        '_energy_left',
        '_decision_set',
    ]

    _fields_and_field_types = {
        'robot_id': 'uint8',
        'current_hp': 'uint16',
        'patrol_rfid': 'uint8',
        'energy_rfid': 'uint8',
        'under_attack': 'uint8',
        'current_ammo': 'uint16',
        'energy_left': 'uint16',
        'decision_set': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_id = kwargs.get('robot_id', int())
        self.current_hp = kwargs.get('current_hp', int())
        self.patrol_rfid = kwargs.get('patrol_rfid', int())
        self.energy_rfid = kwargs.get('energy_rfid', int())
        self.under_attack = kwargs.get('under_attack', int())
        self.current_ammo = kwargs.get('current_ammo', int())
        self.energy_left = kwargs.get('energy_left', int())
        self.decision_set = kwargs.get('decision_set', int())

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
        if self.robot_id != other.robot_id:
            return False
        if self.current_hp != other.current_hp:
            return False
        if self.patrol_rfid != other.patrol_rfid:
            return False
        if self.energy_rfid != other.energy_rfid:
            return False
        if self.under_attack != other.under_attack:
            return False
        if self.current_ammo != other.current_ammo:
            return False
        if self.energy_left != other.energy_left:
            return False
        if self.decision_set != other.decision_set:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def robot_id(self):
        """Message field 'robot_id'."""
        return self._robot_id

    @robot_id.setter
    def robot_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'robot_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'robot_id' field must be an unsigned integer in [0, 255]"
        self._robot_id = value

    @property
    def current_hp(self):
        """Message field 'current_hp'."""
        return self._current_hp

    @current_hp.setter
    def current_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'current_hp' field must be an unsigned integer in [0, 65535]"
        self._current_hp = value

    @property
    def patrol_rfid(self):
        """Message field 'patrol_rfid'."""
        return self._patrol_rfid

    @patrol_rfid.setter
    def patrol_rfid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'patrol_rfid' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'patrol_rfid' field must be an unsigned integer in [0, 255]"
        self._patrol_rfid = value

    @property
    def energy_rfid(self):
        """Message field 'energy_rfid'."""
        return self._energy_rfid

    @energy_rfid.setter
    def energy_rfid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'energy_rfid' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'energy_rfid' field must be an unsigned integer in [0, 255]"
        self._energy_rfid = value

    @property
    def under_attack(self):
        """Message field 'under_attack'."""
        return self._under_attack

    @under_attack.setter
    def under_attack(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'under_attack' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'under_attack' field must be an unsigned integer in [0, 255]"
        self._under_attack = value

    @property
    def current_ammo(self):
        """Message field 'current_ammo'."""
        return self._current_ammo

    @current_ammo.setter
    def current_ammo(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_ammo' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'current_ammo' field must be an unsigned integer in [0, 65535]"
        self._current_ammo = value

    @property
    def energy_left(self):
        """Message field 'energy_left'."""
        return self._energy_left

    @energy_left.setter
    def energy_left(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'energy_left' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'energy_left' field must be an unsigned integer in [0, 65535]"
        self._energy_left = value

    @property
    def decision_set(self):
        """Message field 'decision_set'."""
        return self._decision_set

    @decision_set.setter
    def decision_set(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'decision_set' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'decision_set' field must be an unsigned integer in [0, 255]"
        self._decision_set = value
