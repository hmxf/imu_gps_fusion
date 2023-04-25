echo "Start copy imu_usb.rules and gps_usb.rules to /etc/udev/rules.d..."
sudo cp imu_usb.rules /etc/udev/rules.d
sudo cp gps_usb.rules /etc/udev/rules.d
sudo chmod 777 /etc/udev/rules.d/imu_usb.rules
sudo chmod 777 /etc/udev/rules.d/gps_usb.rules
service udev reload
sleep 2
service udev restart
echo "Finish!!!"
