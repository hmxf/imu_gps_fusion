# IMU and GPS Converged Navigation ROS Guide

## Install dependicies

    sudo apt install ros-noetic-catkin-virtualenv ros-noetic-gps-common ros-noetic-gps-goal ros-noetic-navigation ros-noetic-move-base libgoogle-glog-dev hugin-tools enblend

# Fetch Code

    mkdir ~/catkin_ws && cd ~/catkin_ws
    git clone --recurse-submodules https://github.com/hmxf/imu_gps_fusion src

## Bind USB devicies

    ./scripts/bind_usb.sh

## Build drivers and packages

    catkin_make clean
    catkin_make

## Conncet BOTH IMU and GPS, then run

    roslaunch imu_gps_localization imu_gps_test.launch
