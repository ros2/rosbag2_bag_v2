^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package rosbag2_bag_v2_plugins
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.0.10 (2020-06-05)
-------------------
* workaroud add shared_queues_vendor as test dependency (`#30 <https://github.com/ros2/rosbag2_bag_v2/issues/30>`_)
* Contributors: Karsten Knese

0.0.9 (2020-06-03)
------------------

0.0.8 (2020-05-08)
------------------
* Adapt storage interface for filtering topics. (`#28 <https://github.com/ros2/rosbag2_bag_v2/issues/28>`_)
* Raise an error instead of a warning without ROS 1. (`#23 <https://github.com/ros2/rosbag2_bag_v2/issues/23>`_)
* Use rosbag2 metapackage. (`#16 <https://github.com/ros2/rosbag2_bag_v2/issues/16>`_)
* Contributors: Emerson Knapp, Mabel Zhang, Zachary Michaels

0.0.7 (2019-11-18)
------------------
* Update interfaces to eloquent API. (`#8 <https://github.com/ros2/rosbag2_bag_v2/issues/8>`_)
* Implement changes in IO interfaces. (`#7 <https://github.com/ros2/rosbag2_bag_v2/issues/7>`_)
* Contributors: Zachary Michaels

0.0.6 (2019-06-06)
------------------
* warn when roscpp is not found (`#4 <https://github.com/ros2/rosbag2_bag_v2/issues/4>`_)
  Signed-off-by: osrf <karsten@openrobotics.org>
* New type identification (`#3 <https://github.com/ros2/rosbag2_bag_v2/issues/3>`_)
  * update logging macros
  Signed-off-by: osrf <karsten@openrobotics.org>
  * correct typo in filename
  Signed-off-by: osrf <karsten@openrobotics.org>
  * use new type identification
  Signed-off-by: osrf <karsten@openrobotics.org>
* compile tests (`#2 <https://github.com/ros2/rosbag2_bag_v2/issues/2>`_)
  Signed-off-by: Karsten Knese <karsten@openrobotics.org>
* remove duplicate repos (`#1 <https://github.com/ros2/rosbag2_bag_v2/issues/1>`_)
  Signed-off-by: Karsten Knese <karsten@openrobotics.org>
* correct missing linter errors (`#96 <https://github.com/ros2/rosbag2_bag_v2/issues/96>`_)
  Signed-off-by: Karsten Knese <karsten@openrobotics.org>
* removed dependency to ros1_bridge package (`#90 <https://github.com/ros2/rosbag2_bag_v2/issues/90>`_)
  * removed dependency to ros1_bridge package:
  * checking if package is available
  * if not skipping (with warnings)
  * now rosbag2_tests builds on systems without ros1
  * check ros1 deps correctly on all packages
  * add ros1_bridge to test package
  * silently try to find the bridge
* Contributors: DensoADAS, Karsten Knese

0.0.5 (2018-12-27)
------------------

0.0.4 (2018-12-19)
------------------
* 0.0.3
* manually bump version number as catkin_prepare_release complains
* generate changelog
* Contributors: Karsten Knese, Martin Idel

0.0.3 (2018-12-14)
------------------
* Release fixes (`#73 <https://github.com/ros2/rosbag2/issues/73>`_)
* Play old bagfiles (`#69 <https://github.com/ros2/rosbag2/issues/69>`_)
* Contributors: Karsten Knese, Martin Idel

0.0.2 (2018-12-12)
------------------

0.0.1 (2018-12-11)
------------------
