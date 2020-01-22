![License](https://img.shields.io/github/license/ros2/rosbag2_bag_v2)
[![GitHub Action Status](https://github.com/ros2/rosbag2_bag_v2/workflows/Test%20rosbag2_bag_v2/badge.svg)](https://github.com/ros2/rosbag2_bag_v2/actions)

The plugin for rosbags from ROS 1
=================================

This is the plugin for reading legacy ROS 1 bag files and introspect as well as replay them in ROS 2.
The name for this plugin refers to the version 2 of the ROS 1 bag format: https://wiki.ros.org/Bags/Format/2.0
This documentation is solely targeting the plugin for legacy ROS 1 bag files.
For general information about rosbag2, please refer to https://index.ros.org/r/rosbag2/github-ros2-rosbag2/.

Requirements
------------

In order to use this plugin, you need to have ROS 2 as well as ROS 1 installed.
Please refer to the [ROS 2 install instructions](https://index.ros.org/doc/ros2/Installation/) for installing the appropriate version of ROS2.
This plugin requires Crystal or higher as your ROS 2 release.
For ROS1, it is necessary to [install ROS Melodic](https://wiki.ros.org/melodic/Installation).

This plugin  requires translating ROS 1 messages into ROS 2 messages similar to the `ros1_bridge`.
You need to have the `ros1_bridge` built (see https://index.ros.org/p/ros1_bridge) in order to do that.
As a side note, you can run this plugin on other platforms than Ubuntu as long as you can guarantee to have the `ros1_bridge` package compiled successfully.

Secondly, this plugin is part of the rosbag2 plugin architecture.
It is thus required that rosbag2 is correctly installed, see https://index.ros.org/r/rosbag2.

Installing the ROS 1 plugin from debs
-------------------------------------

As of Dashing, you can easily install the plugin via aptitude (in case you are on Ubuntu).
Given that you set up your ROS 1 installation requirements such as [setting up your sources.list](http://wiki.ros.org/melodic/Installation/Ubuntu#Installation.2BAC8-Ubuntu.2BAC8-Sources.Setup_your_sources.list) as well as [set up the keys for ROS1](http://wiki.ros.org/melodic/Installation/Ubuntu#Installation.2BAC8-Ubuntu.2BAC8-Sources.Set_up_your_keys) you can install the plugin as follows:

```
sudo apt install -y ros-dashing-rosbag2-bag-v2-plugins
```

The command above will bring in all the dependencies such ROS 1, ROS 2 as well as all ROS 2 dependencies.

Building the ROS 1 plugin
-------------------------

If your ROS 1 rosbags contain custom message formats which can be translated into ROS 2 messages, the plugins need to be built from source.

We assume that the ROS1, ROS 2 as well as the rosbag2 environment is correctly built and sourced.
Then, in a fresh terminal:

Source your ROS 1 installation
```
source /opt/ros/melodic/setup.bash
```

Source your ROS 2 installation (including the `ros1_bridge`)
```
source /opt/ros/dashing/setup.bash  // change according to your ROS 2 installation
```

Build the workspace using `colcon build --merge-install`.
This will automatically match all ROS 1 messages to their ROS 2 counterpart using the same logic as the `ros1_bridge`.

N.B: The ROS 1 installation must be sourced first to avoid problems with the class_loader.
It happens to occur that cyclic dependencies are detected when compiling this plugin.
The reason for this is that some packages which contain message definitions in ROS 1 also depend on class loader.
It is therefore very important to source the ROS 2 installation after ROS 1 in order to guarantee that the ROS 2 class loader is correctly found and linked.
There is an open issue for this stating that the ROS 1 and ROS 2 class loader API should be provide some basic interoperability.
See https://github.com/ros/class_loader/issues/109

Using the plugins
-----------------

In order to use the plugins, again, the ROS 1 installation must be sourced before sourcing the ROS 2 installation.
You can then just use the plugin through the regular interface.
For instance, on the command line write:
```
ros2 bag info -s rosbag_v2 <path_to_bagfile>
```

Here, `-s rosbag_v2` tells rosbag2 to use the plugin to read rosbags (version 2) to query the bagfile.
For old rosbags, the storage format must be added to the info call as rosbag does not have the necessary information to read the plugin otherwise.
The command above should print something like the following:
```
Files:             test_bag.bag
Bag size:          8.8 KiB
Storage id:        rosbag_v2
Duration:          0.268s
Start:             Nov 29 2018 16:43:33.298 (1543509813.298)
End                Nov 29 2018 16:43:33.567 (1543509813.567)
Messages:          5
Topic information: Topic: /rosout | Type: rosgraph_msgs/Log | Count: 3 | Serialization Format: rosbag_v2
                   Topic: /test_topic | Type: std_msgs/String | Count: 1 | Serialization Format: rosbag_v2
                   Topic: /test_topic2 | Type: std_msgs/String | Count: 1 | Serialization Format: rosbag_v2
```

For playing, one can similarly write:
```
ros2 bag play -s rosbag_v2 <path_to_bagfile>
```

If there is ROS 1 data where no topic matching exists to ROS 2 these topics are ignored when replying.
When calling ros2 bag info, one can see a list of mismatching topics:
```
[INFO] [rosbag2_bag_v2_plugins]: ROS 1 to ROS 2 type mapping is not available for topic '/rosout' which is of type 'rosgraph_msgs/Log'. Skipping messages of this topic when replaying
```

Currently, split bagfiles are unsupported.
