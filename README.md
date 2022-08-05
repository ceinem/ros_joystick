# ros_joystick
Small project to create a joystick as a general controller for ROS. 

Follow tutorial of [rosserial](http://wiki.ros.org/rosserial_arduino/Tutorials) to properly setup the dependencies and run the code.

This project utilizes an Arduino Nano as well as a simble [two axis joystick](https://www.reichelt.com/ch/de/entwicklerboards-joystick-modul-debo-thumb-joy-p239254.html?&nbc=1).

Connect as following: 
```
GND  -- GND

VCC  -- 5V

VRx  -- A0

VRy  -- A1

SW  -- D2
```

