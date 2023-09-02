/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/


#include <Servo.h>

Servo base;  // create servo object to control a servo
Servo tronco;
Servo braco;


int val_base;    // variable to read the value from the analog pin
int val_tronco;
int val_braco;

void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
  base.attach(9);
  tronco.attach(10);
  braco.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int val_base = analogRead(A0);
  int val_tronco = analogRead(A5);
  int val_braco = analogRead(A1);            // reads the value of the potentiometer (value between 0 and 1023)
  // Serial.println(val_tronco);
  // Serial.println(val_braco);
  //int val_base_aux = map(val_base, 0, 1023, 0, 1023);

  int angle_base = map(val_base, 0, 1023, 0, 180);
  int angle_tronco = map(val_tronco, 0, 1023, 0, 180);
  int angle_braco = map(val_braco, 0, 1023, 0, 180);    // scale it for use with the servo (value between 0 and 180)

  base.write(angle_base);
  tronco.write(angle_tronco);
  braco.write(angle_braco); // sets the servo position according to the scaled value
  delay(50);                           // waits for the servo to get there

  Serial.println(val_base);
}
