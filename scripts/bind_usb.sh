#!/usr/bin/bash

echo "Start copy imu_usb.rules and gps_usb.rules to /etc/udev/rules.d..."
sudo cp scripts/imu_usb.rules /etc/udev/rules.d
sudo cp scripts/gps_usb.rules /etc/udev/rules.d
sudo chmod 777 /etc/udev/rules.d/imu_usb.rules
sudo chmod 777 /etc/udev/rules.d/gps_usb.rules
sudo service udev reload
sleep 2
sudo service udev restart
echo "Finish!!!"
