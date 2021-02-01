^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package ros1_rosbag_storage_vendor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Forthcoming
-----------
* Update to the latest rosbag1. (`#40 <https://github.com/ros2/rosbag2_bag_v2/issues/40>`_)
* Contributors: Chris Lalancette

0.0.9 (2020-06-03)
------------------

0.0.8 (2020-05-08)
------------------
* Adapt storage interface for filtering topics. (`#28 <https://github.com/ros2/rosbag2_bag_v2/issues/28>`_)
* Contributors: Mabel Zhang

0.0.7 (2019-11-18)
------------------

0.0.6 (2019-06-06)
------------------
* removed dependency to ros1_bridge package (`#90 <https://github.com/ros2/rosbag2_bag_v2/issues/90>`_)
  * removed dependency to ros1_bridge package:
  * checking if package is available
  * if not skipping (with warnings)
  * now rosbag2_tests builds on systems without ros1
  * check ros1 deps correctly on all packages
  * add ros1_bridge to test package
  * silently try to find the bridge
* Contributors: DensoADAS

0.0.5 (2018-12-27)
------------------
* add ros1bridge dependency
* Contributors: Karsten Knese

0.0.4 (2018-12-19)
------------------
* Fix patch command osx (`#82 <https://github.com/bsinno/rosbag2/issues/82>`_)
* Improve queue usage (`#75 <https://github.com/bsinno/rosbag2/issues/75>`_)
* add ros1 rosbag_storage dependencies to vendor package (`#77 <https://github.com/bsinno/rosbag2/issues/77>`_)
* find openssl (`#76 <https://github.com/bsinno/rosbag2/issues/76>`_)
* 0.0.3
* manually bump version number as catkin_prepare_release complains
* generate changelog
* Contributors: Andreas Holzner, Karsten Knese, Martin Idel

0.0.3 (2018-12-14)
------------------
* Release fixes (`#73 <https://github.com/ros2/rosbag2/issues/73>`_)
* Play old bagfiles (`#69 <https://github.com/ros2/rosbag2/issues/69>`_)
* Contributors: Karsten Knese, Martin Idel

0.0.2 (2018-12-12)
------------------

0.0.1 (2018-12-11)
------------------
