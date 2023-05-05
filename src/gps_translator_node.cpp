// Copyright 2023 Jakub Codogni
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "gps_translator/gps_translator_node.hpp"
#include <string.h>

namespace gps_translator
{

GpsTranslatorNode::GpsTranslatorNode(const rclcpp::NodeOptions & options)
:  Node("gps_translator", options)
{
  std::string gps_sub_topic = declare_parameter("gps_sub_topic", "gps");
  std::string gps_pub_topic = declare_parameter("gps_pub_topic", "gps_fix");

  // Custom qos profile with history = keep last , depth =1, durability = volatile,
  // reliability = best_effort
  rclcpp::QoS qos_profile = rclcpp::QoS(10);
  qos_profile.durability_volatile();
  qos_profile.reliability(rclcpp::ReliabilityPolicy::BestEffort);

  gps_sub_ = this->create_subscription<gps_msgs::msg::GPSFix>(
    gps_sub_topic, qos_profile, std::bind(&GpsTranslatorNode::gpsCallback, this, std::placeholders::_1));

  gps_pub_ = this->create_publisher<sensor_msgs::msg::NavSatFix>(gps_pub_topic, qos_profile);
}

void GpsTranslatorNode::gpsCallback(const gps_msgs::msg::GPSFix::SharedPtr msg)
{
  sensor_msgs::msg::NavSatFix gps_fix;
  gps_fix.header = msg->header;
  gps_fix.latitude = msg->latitude;
  gps_fix.longitude = msg->longitude;
  gps_fix.altitude = msg->altitude;
  gps_fix.position_covariance = msg->position_covariance;
  gps_fix.position_covariance_type = msg->position_covariance_type;
  gps_pub_->publish(gps_fix);
}

}  // namespace gps_translator

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(gps_translator::GpsTranslatorNode)
