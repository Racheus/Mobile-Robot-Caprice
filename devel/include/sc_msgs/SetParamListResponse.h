// Generated by gencpp from file sc_msgs/SetParamListResponse.msg
// DO NOT EDIT!


#ifndef SC_MSGS_MESSAGE_SETPARAMLISTRESPONSE_H
#define SC_MSGS_MESSAGE_SETPARAMLISTRESPONSE_H


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
struct SetParamListResponse_
{
  typedef SetParamListResponse_<ContainerAllocator> Type;

  SetParamListResponse_()
    : succ(false)  {
    }
  SetParamListResponse_(const ContainerAllocator& _alloc)
    : succ(false)  {
  (void)_alloc;
    }



   typedef uint8_t _succ_type;
  _succ_type succ;





  typedef boost::shared_ptr< ::sc_msgs::SetParamListResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sc_msgs::SetParamListResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SetParamListResponse_

typedef ::sc_msgs::SetParamListResponse_<std::allocator<void> > SetParamListResponse;

typedef boost::shared_ptr< ::sc_msgs::SetParamListResponse > SetParamListResponsePtr;
typedef boost::shared_ptr< ::sc_msgs::SetParamListResponse const> SetParamListResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sc_msgs::SetParamListResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sc_msgs::SetParamListResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sc_msgs::SetParamListResponse_<ContainerAllocator1> & lhs, const ::sc_msgs::SetParamListResponse_<ContainerAllocator2> & rhs)
{
  return lhs.succ == rhs.succ;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sc_msgs::SetParamListResponse_<ContainerAllocator1> & lhs, const ::sc_msgs::SetParamListResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sc_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sc_msgs::SetParamListResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sc_msgs::SetParamListResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sc_msgs::SetParamListResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sc_msgs::SetParamListResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sc_msgs::SetParamListResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sc_msgs::SetParamListResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sc_msgs::SetParamListResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f680ede81341c83926ff269af0efb2e6";
  }

  static const char* value(const ::sc_msgs::SetParamListResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf680ede81341c839ULL;
  static const uint64_t static_value2 = 0x26ff269af0efb2e6ULL;
};

template<class ContainerAllocator>
struct DataType< ::sc_msgs::SetParamListResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sc_msgs/SetParamListResponse";
  }

  static const char* value(const ::sc_msgs::SetParamListResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sc_msgs::SetParamListResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool succ\n"
"\n"
;
  }

  static const char* value(const ::sc_msgs::SetParamListResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sc_msgs::SetParamListResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.succ);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetParamListResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sc_msgs::SetParamListResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sc_msgs::SetParamListResponse_<ContainerAllocator>& v)
  {
    s << indent << "succ: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.succ);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SC_MSGS_MESSAGE_SETPARAMLISTRESPONSE_H
