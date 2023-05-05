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

#ifndef GPS_TRANSLATOR__GPS_TRANSLATOR_NODE_HPP_
#define GPS_TRANSLATOR__GPS_TRANSLATOR_NODE_HPP_

#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <cstdint>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <gps_msgs/msg/gps_fix.hpp>

#include "gps_translator/visibility_control.hpp"

namespace gps_translator
{

class GPS_TRANSLATOR_PUBLIC GpsTranslatorNode : public rclcpp::Node
{
public:
  explicit GpsTranslatorNode(const rclcpp::NodeOptions & options);
  void gpsCallback(const gps_msgs::msg::GPSFix::SharedPtr msg);

private:
  rclcpp::Subscription<gps_msgs::msg::GPSFix>::SharedPtr gps_sub_;
  rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr gps_pub_;
};
}  // namespace gps_translator

#endif  // GPS_TRANSLATOR__GPS_TRANSLATOR_NODE_HPP_
