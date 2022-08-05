#include <ros.h>
#include <std_msgs/String.h>
#include <joystick_msgs/status.h>


ros::NodeHandle nh;
std_msgs::String str_msg;
joystick_msgs::status cur_stat;
ros::Publisher joystick_status("/joystick/status", &cur_stat);


int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  nh.initNode();
  nh.advertise(joystick_status);
}

void loop() {

  xPosition = analogRead(VRx)-503+512;
  yPosition = analogRead(VRy)-505+512;
  SW_state = !digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  if(abs(mapX) < 20) {
    mapX = 0;
  }
  if(abs(mapY)<20) {
    mapY = 0;
  }

  cur_stat.x = mapX;
  cur_stat.y = mapY;
  cur_stat.button = SW_state;
  joystick_status.publish(&cur_stat);
  nh.spinOnce();  
}
