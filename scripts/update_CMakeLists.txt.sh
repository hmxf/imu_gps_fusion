#!/usr/bin/bash

rm $PWD/CMakeLists.txt
ln -s $ROS_PACKAGE_PATH/catkin/cmake/toplevel.cmake CMakeLists.txt
