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

int pot_base = A0;  // analog pin used to connect the potentiometer
int pot_tronco = A1;    // variable to read the value from the analog pin
int pot_braco = A2;

void setup() {
  Serial.begin(9600);
  base.attach(9);  // attaches the servo on pin 9 to the servo object
  tronco.attach(10);
  braco.attach(11);
  }


void loop() {
  int val_base = analogRead(pot_base);
  int val_tronco = analogRead(pot_tronco);
  int val_braco = analogRead(pot_braco); 

  //Serial.println(val_braco);           // reads the value of the potentiometer (value between 0 and 1023)

  int angle_base = map(val_base, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  int angle_tronco = map(val_tronco, 0, 1023, 0, 180);
  int angle_braco = map(val_braco, 0, 1023, 0, 180);
  
  base.write(angle_base);                  // sets the servo position according to the scaled value
  tronco.write(angle_tronco);
  braco.write(angle_braco);
  int angle_print = angle_braco + 50;
  Serial.print("ANGULO JUNTA: ");
  Serial.println(angle_print);
  delay(50);                           // waits for the servo to get there
}
