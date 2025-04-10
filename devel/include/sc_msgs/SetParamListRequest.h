// Generated by gencpp from file sc_msgs/SetParamListRequest.msg
// DO NOT EDIT!


#ifndef SC_MSGS_MESSAGE_SETPARAMLISTREQUEST_H
#define SC_MSGS_MESSAGE_SETPARAMLISTREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sc_msgs/parameters.h>

namespace sc_msgs
{
template <class ContainerAllocator>
struct SetParamListRequest_
{
  typedef SetParamListRequest_<ContainerAllocator> Type;

  SetParamListRequest_()
    : param()  {
    }
  SetParamListRequest_(const ContainerAllocator& _alloc)
    : param(_alloc)  {
  (void)_alloc;
    }



   typedef  ::sc_msgs::parameters_<ContainerAllocator>  _param_type;
  _param_type param;





  typedef boost::shared_ptr< ::sc_msgs::SetParamListRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sc_msgs::SetParamListRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetParamListRequest_

typedef ::sc_msgs::SetParamListRequest_<std::allocator<void> > SetParamListRequest;

typedef boost::shared_ptr< ::sc_msgs::SetParamListRequest > SetParamListRequestPtr;
typedef boost::shared_ptr< ::sc_msgs::SetParamListRequest const> SetParamListRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sc_msgs::SetParamListRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sc_msgs::SetParamListRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sc_msgs::SetParamListRequest_<ContainerAllocator1> & lhs, const ::sc_msgs::SetParamListRequest_<ContainerAllocator2> & rhs)
{
  return lhs.param == rhs.param;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sc_msgs::SetParamListRequest_<ContainerAllocator1> & lhs, const ::sc_msgs::SetParamListRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sc_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sc_msgs::SetParamListRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sc_msgs::SetParamListRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sc_msgs::SetParamListRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sc_msgs::SetParamListRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sc_msgs::SetParamListRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sc_msgs::SetParamListRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sc_msgs::SetParamListRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1dbbb9344d5148e4dc17b3b0135d5f58";
  }

  static const char* value(const ::sc_msgs::SetParamListRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1dbbb9344d5148e4ULL;
  static const uint64_t static_value2 = 0xdc17b3b0135d5f58ULL;
};

template<class ContainerAllocator>
struct DataType< ::sc_msgs::SetParamListRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sc_msgs/SetParamListRequest";
  }

  static const char* value(const ::sc_msgs::SetParamListRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sc_msgs::SetParamListRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sc_msgs/parameters param\n"
"\n"
"================================================================================\n"
"MSG: sc_msgs/parameters\n"
"string[] param_name\n"
"float64[] values\n"
"\n"
;
  }

  static const char* value(const ::sc_msgs::SetParamListRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sc_msgs::SetParamListRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.param);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetParamListRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sc_msgs::SetParamListRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sc_msgs::SetParamListRequest_<ContainerAllocator>& v)
  {
    s << indent << "param: ";
    s << std::endl;
    Printer< ::sc_msgs::parameters_<ContainerAllocator> >::stream(s, indent + "  ", v.param);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SC_MSGS_MESSAGE_SETPARAMLISTREQUEST_H
