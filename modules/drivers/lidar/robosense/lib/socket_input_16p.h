/******************************************************************************
 * Copyright 2021 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once
#include <pcap.h>
#include <unistd.h>

#include <cstdio>

#include "modules/drivers/lidar/robosense/lib/data_type.h"
#include "modules/drivers/lidar/robosense/lib/input.h"

namespace apollo {
namespace drivers {
namespace robosense {

/** @brief Live suteng input from socket. */
class SocketInput16P : public Input {
 public:
  SocketInput16P();
  virtual ~SocketInput16P();
  void init(uint32_t port);
  int get_firing_data_packet(apollo::drivers::suteng::SutengPacket* pkt,
                             bool use_gps_time);
  int get_positioning_data_packet(apollo::drivers::suteng::SutengPacket* pkt,
                                  bool use_gps_time);
  bool exract_utc_time_from_packet(uint64_t& utc_time_ns, const uint8_t* bytes);
  int get_firing_data_packet(apollo::drivers::suteng::SutengPacket* pkt,
                             int time_zone, uint64_t start_time_) {
    return 0;
  };
  int get_positioning_data_packtet(const NMEATimePtr& nmea_time) { return 0; };

 private:
  int sockfd_;
  int port_;
  bool input_available(int timeout);
};
}  // namespace robosense
}  // namespace drivers
}  // namespace apollo