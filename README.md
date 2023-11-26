# IMU and GPS Converged Navigation ROS Guide

## Install dependicies

Execute both lines if your ROS was installed by APT Packager Manager. Otherwise execute the first line alone.

```bash
sudo apt install libgoogle-glog-dev hugin-tools enblend glibc-doc
sudo apt install ros-noetic-catkin-virtualenv ros-noetic-gps-common ros-noetic-navigation ros-noetic-move-base
```

# Build sepecific version of `python3-docutils` package

```bash
sudo apt remove python3-docutils docutils-common docutils-doc
mkdir ~/docutils_src && cd ~/docutils_src
wget https://mirrors.tuna.tsinghua.edu.cn/ubuntu/pool/main/p/python-docutils/python3-docutils_0.20.1%2Bdfsg-2_all.deb
wget https://mirrors.tuna.tsinghua.edu.cn/ubuntu/pool/main/p/python-docutils/docutils-common_0.20.1%2Bdfsg-2_all.deb
wget https://mirrors.tuna.tsinghua.edu.cn/ubuntu/pool/main/p/python-docutils/docutils-doc_0.20.1%2Bdfsg-2_all.deb
sudo dpkg -i docutils-common_0.20.1+dfsg-2_all.deb docutils-doc_0.20.1+dfsg-2_all.deb python3-docutils_0.20.1+dfsg-2_all.deb
sudo apt install python3-catkin-pkg python3-catkin-pkg-modules python3-catkin-tools python3-rosdep python3-rosdep-modules python3-rosdistro-modules python3-rosinstall-generator python3-rospkg python3-rospkg-modules
```

# Fetch Code

```bash
mkdir ~/catkin_ws && cd ~/catkin_ws
git clone --recurse-submodules https://github.com/hmxf/imu_gps_fusion src
```

## Bind USB devices

```bash
./scripts/bind_usb.sh
```

## Build drivers and packages

```bash
catkin_make clean
catkin_make
```

## Conncet BOTH IMU and GPS, then run

```bash
roslaunch imu_gps_localization imu_gps_test.launch
```