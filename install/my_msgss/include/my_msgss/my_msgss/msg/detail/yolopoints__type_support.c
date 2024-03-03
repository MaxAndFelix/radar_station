// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_msgss:msg/Yolopoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_msgss/msg/detail/yolopoints__rosidl_typesupport_introspection_c.h"
#include "my_msgss/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_msgss/msg/detail/yolopoints__functions.h"
#include "my_msgss/msg/detail/yolopoints__struct.h"


// Include directives for member types
// Member `text`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "my_msgss/msg/yolopoint.h"
// Member `data`
#include "my_msgss/msg/detail/yolopoint__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_msgss__msg__Yolopoints__init(message_memory);
}

void my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_fini_function(void * message_memory)
{
  my_msgss__msg__Yolopoints__fini(message_memory);
}

size_t my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__size_function__Yolopoints__data(
  const void * untyped_member)
{
  const my_msgss__msg__Yolopoint__Sequence * member =
    (const my_msgss__msg__Yolopoint__Sequence *)(untyped_member);
  return member->size;
}

const void * my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__get_const_function__Yolopoints__data(
  const void * untyped_member, size_t index)
{
  const my_msgss__msg__Yolopoint__Sequence * member =
    (const my_msgss__msg__Yolopoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__get_function__Yolopoints__data(
  void * untyped_member, size_t index)
{
  my_msgss__msg__Yolopoint__Sequence * member =
    (my_msgss__msg__Yolopoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__fetch_function__Yolopoints__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const my_msgss__msg__Yolopoint * item =
    ((const my_msgss__msg__Yolopoint *)
    my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__get_const_function__Yolopoints__data(untyped_member, index));
  my_msgss__msg__Yolopoint * value =
    (my_msgss__msg__Yolopoint *)(untyped_value);
  *value = *item;
}

void my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__assign_function__Yolopoints__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  my_msgss__msg__Yolopoint * item =
    ((my_msgss__msg__Yolopoint *)
    my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__get_function__Yolopoints__data(untyped_member, index));
  const my_msgss__msg__Yolopoint * value =
    (const my_msgss__msg__Yolopoint *)(untyped_value);
  *item = *value;
}

bool my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__resize_function__Yolopoints__data(
  void * untyped_member, size_t size)
{
  my_msgss__msg__Yolopoint__Sequence * member =
    (my_msgss__msg__Yolopoint__Sequence *)(untyped_member);
  my_msgss__msg__Yolopoint__Sequence__fini(member);
  return my_msgss__msg__Yolopoint__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_message_member_array[3] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgss__msg__Yolopoints, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "text",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgss__msg__Yolopoints, text),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgss__msg__Yolopoints, data),  // bytes offset in struct
    NULL,  // default value
    my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__size_function__Yolopoints__data,  // size() function pointer
    my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__get_const_function__Yolopoints__data,  // get_const(index) function pointer
    my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__get_function__Yolopoints__data,  // get(index) function pointer
    my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__fetch_function__Yolopoints__data,  // fetch(index, &value) function pointer
    my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__assign_function__Yolopoints__data,  // assign(index, value) function pointer
    my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__resize_function__Yolopoints__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_message_members = {
  "my_msgss__msg",  // message namespace
  "Yolopoints",  // message name
  3,  // number of fields
  sizeof(my_msgss__msg__Yolopoints),
  my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_message_member_array,  // message members
  my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_init_function,  // function to initialize message memory (memory has to be allocated)
  my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_message_type_support_handle = {
  0,
  &my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_msgss
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_msgss, msg, Yolopoints)() {
  my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_msgss, msg, Yolopoint)();
  if (!my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_message_type_support_handle.typesupport_identifier) {
    my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_msgss__msg__Yolopoints__rosidl_typesupport_introspection_c__Yolopoints_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
