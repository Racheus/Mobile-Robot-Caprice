// Generated by gencpp from file sc_msgs/parameters.msg
// DO NOT EDIT!


#ifndef SC_MSGS_MESSAGE_PARAMETERS_H
#define SC_MSGS_MESSAGE_PARAMETERS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sc_msgs
{
template <class ContainerAllocator>
struct parameters_
{
  typedef parameters_<ContainerAllocator> Type;

  parameters_()
    : param_name()
    , values()  {
    }
  parameters_(const ContainerAllocator& _alloc)
    : param_name(_alloc)
    , values(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> _param_name_type;
  _param_name_type param_name;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _values_type;
  _values_type values;





  typedef boost::shared_ptr< ::sc_msgs::parameters_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sc_msgs::parameters_<ContainerAllocator> const> ConstPtr;

}; // struct parameters_

typedef ::sc_msgs::parameters_<std::allocator<void> > parameters;

typedef boost::shared_ptr< ::sc_msgs::parameters > parametersPtr;
typedef boost::shared_ptr< ::sc_msgs::parameters const> parametersConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sc_msgs::parameters_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sc_msgs::parameters_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sc_msgs::parameters_<ContainerAllocator1> & lhs, const ::sc_msgs::parameters_<ContainerAllocator2> & rhs)
{
  return lhs.param_name == rhs.param_name &&
    lhs.values == rhs.values;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sc_msgs::parameters_<ContainerAllocator1> & lhs, const ::sc_msgs::parameters_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sc_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sc_msgs::parameters_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sc_msgs::parameters_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sc_msgs::parameters_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sc_msgs::parameters_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sc_msgs::parameters_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sc_msgs::parameters_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sc_msgs::parameters_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8796a60c7639dcd20659eaeb24d59fb3";
  }

  static const char* value(const ::sc_msgs::parameters_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8796a60c7639dcd2ULL;
  static const uint64_t static_value2 = 0x0659eaeb24d59fb3ULL;
};

template<class ContainerAllocator>
struct DataType< ::sc_msgs::parameters_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sc_msgs/parameters";
  }

  static const char* value(const ::sc_msgs::parameters_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sc_msgs::parameters_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] param_name\n"
"float64[] values\n"
"\n"
;
  }

  static const char* value(const ::sc_msgs::parameters_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sc_msgs::parameters_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.param_name);
      stream.next(m.values);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct parameters_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sc_msgs::parameters_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sc_msgs::parameters_<ContainerAllocator>& v)
  {
    s << indent << "param_name[]" << std::endl;
    for (size_t i = 0; i < v.param_name.size(); ++i)
    {
      s << indent << "  param_name[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.param_name[i]);
    }
    s << indent << "values[]" << std::endl;
    for (size_t i = 0; i < v.values.size(); ++i)
    {
      s << indent << "  values[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.values[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SC_MSGS_MESSAGE_PARAMETERS_H
