#include <Servo.h>

Servo servo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  servo.attach(11);  // attaches the servo on pin 11 to the servo object
}

void loop() {
  if (Serial.available()) { // if there is data comming
    int angle = Serial.parseInt();

    if (angle >= 0 && angle <= 180) {
      servo.write(angle);
      delay(5000);
      Serial.print("Rotated servo to angle: ");// reports action to smartphone app
      Serial.println(angle);
    }
    else {
      Serial.print("Invalid angle: ");// reports invalid value to smartphone app
      Serial.println(angle);
    }
  }
}
