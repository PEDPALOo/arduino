#include <Servo.h>
#include <ros.h>
Servo esc_front,esc_back,servo_front,servo_back;     // create servo object to control the ESC

int potValue,i=90;  // value from the analog pin

ros::NodeHandle nh;



void setup() {
  // Attach the ESC on pin 9
  nh.initNode();
  nh.subscribe();
  esc_front.attach(4,1000,2000); // (pin, min pulse width, max pulse width in microseconds)
  esc_back.attach(6,1000,2000);
  servo_front.attach(5,1000,2000); 
  servo_back.attach(7,1000,2000); 
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  if( i >= 90 && i <= 121)
  {
    i = i +1 ;
    delay(500);
  }
  esc_front.write(i);    // Send the signal to the ESC
  esc_back.write(i);
  Serial.println(i);
  servo_front.write(90);
  servo_back.write(90);
  nh.spinOnce();
  
}
