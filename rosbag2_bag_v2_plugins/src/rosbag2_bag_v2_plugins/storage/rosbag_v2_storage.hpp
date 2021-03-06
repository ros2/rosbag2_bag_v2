// Copyright 2018, Bosch Software Innovations GmbH.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROSBAG2_BAG_V2_PLUGINS__STORAGE__ROSBAG_V2_STORAGE_HPP_
#define ROSBAG2_BAG_V2_PLUGINS__STORAGE__ROSBAG_V2_STORAGE_HPP_

#include <memory>
#include <string>
#include <vector>

#include "rosbag2_storage/bag_metadata.hpp"
#include "rosbag2_storage/storage_interfaces/read_only_interface.hpp"
#include "rosbag2_storage/serialized_bag_message.hpp"
#include "rosbag2_storage/storage_filter.hpp"
#include "rosbag2_storage/topic_metadata.hpp"
#include "rosbag/bag.h"
#include "rosbag/view.h"

namespace rosbag2_bag_v2_plugins
{

class RosbagV2Storage : public rosbag2_storage::storage_interfaces::ReadOnlyInterface
{
public:
  RosbagV2Storage();

  ~RosbagV2Storage() override;

  void open(
    const rosbag2_storage::StorageOptions & storage_options,
    rosbag2_storage::storage_interfaces::IOFlag flag) override;

  bool has_next() override;

  std::shared_ptr<rosbag2_storage::SerializedBagMessage> read_next() override;

  std::vector<rosbag2_storage::TopicMetadata> get_all_topics_and_types() override;

  rosbag2_storage::BagMetadata get_metadata() override;

  uint64_t get_bagfile_size() const override;

  std::string get_relative_file_path() const override;

  /**
   * Returns the identifier for the rosbag_v2 plugin.
   * \returns the identifier "rosbag_v2"
   */
  std::string get_storage_identifier() const override;

  void set_filter(const rosbag2_storage::StorageFilter & storage_filter) override;

  void reset_filter() override;

private:
  template<typename T>
  bool vector_has_already_element(std::vector<T> vector, const T & element)
  {
    return std::find(vector.begin(), vector.end(), element) != vector.end();
  }
  std::vector<rosbag2_storage::TopicMetadata> get_all_topics_and_types_including_ros1_topics();
  std::vector<rosbag2_storage::TopicInformation> get_topic_information();

  std::unique_ptr<rosbag::Bag> ros_v2_bag_;
  std::unique_ptr<rosbag::View> bag_view_of_replayable_messages_;
  rosbag::View::iterator bag_iterator_;
  rosbag2_storage::StorageFilter storage_filter_ {};
};

}  // namespace rosbag2_bag_v2_plugins

#endif  // ROSBAG2_BAG_V2_PLUGINS__STORAGE__ROSBAG_V2_STORAGE_HPP_
