# IMU and GPS Converged Navigation ROS Guide

## Install dependicies

Execute both lines if your ROS was installed by APT Packager Manager. Otherwise execute the first line alone.

```bash
sudo apt install libgoogle-glog-dev hugin-tools enblend glibc-doc
sudo apt install ros-noetic-catkin-virtualenv ros-noetic-gps-common ros-noetic-navigation ros-noetic-move-base
```

### Install nmea_navsat_driver for GPS

```bash
sudo apt install ros-noetic-nmea-navsat-driver ros-noetic-nmea-msgs
```

# Fetch Code

```bash
mkdir ~/catkin_ws && cd ~/catkin_ws
git clone --recurse-submodules https://github.com/hmxf/imu_gps_fusion src
```

## Bind USB devices and update CMakeLists.txt

```bash
./scripts/bind_usb.sh
./scripts/update_CMakeLists.txt.sh
```

## Build drivers and packages

```bash
catkin clean
catkin build
```

## Conncet BOTH IMU and GPS, then run

```bash
roslaunch imu_gps_localization imu_gps_test.launch
```
