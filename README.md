# IMU and GPS Converged Navigation ROS Guide

## Install dependicies

sudo apt install ros-noetic-gps-common ros-noetic-navigation ros-noetic-move-base libgoogle-glog-dev hugin-tools enblend

## Bind USB devicies

./scripts/bind_usb.sh

## Build drivers and packages

catkin_make clean
catkin_make

## Conncet BOTH IMU and GPS, then run

roslaunch imu_gps_localization imu_gps_test.launch

