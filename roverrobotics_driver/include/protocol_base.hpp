#pragma once
#include <boost/bind.hpp>

#include "robot_info.hpp"
#include "status_data.hpp"
namespace RoverRobotics {
class BaseProtocolObject;
}
class RoverRobotics::BaseProtocolObject {
 public:
  BaseProtocolObject();
  virtual ~BaseProtocolObject() = 0;
  virtual void update_drivetrim(double) = 0;
  virtual void translate_send_estop() = 0;
  virtual void translate_send_speed(double linearx, double angularz) = 0;
  virtual statusData translate_send_robot_status_request() = 0;
  virtual robotInfo translate_send_robot_info_request() = 0;
  virtual void handle_unsupported_ros_message() = 0;
  virtual void unpack_robot_response() = 0;
  virtual bool isConnected() = 0;
  // virtual void register_state_response_cb(boost::function<int(void)> _f);
  virtual void register_comm_base();
};
