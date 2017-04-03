# Notes
Requires https://github.com/hallard/ArduiPi_SSD1306 to be installed 

For proper rotation on MagWebPro, the above library should be modified to have a rotation value of 2

## Examples
```
sudo ./tinyFrontOLED "Ethernet Interface   " "" "IP: `ifconfig eth0 | grep "inet addr" | cut -c 21-35`" "HW:`ifconfig eth0 | cut -c 39-`"
sudo ./tinyFrontOLED "WiFi Interface       " "" "IP: `ifconfig wlan0 | grep "inet addr" | cut -c 21-35`" "HW:`ifconfig wlan0 | cut -c 39-`"
```
