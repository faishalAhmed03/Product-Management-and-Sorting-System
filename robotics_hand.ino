#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();
SoftwareSerial getValue(10, 11); // TX , RX

#define servo1 4
#define servo2 5
#define servo3 6
#define servo4 7

int S1curntPos = 350;//150 - 600
int S2curntPos = 450;//150 - 600
int S3curntPos = 400;//150 - 600
int S4curntPos = 350;//150 - 600

int S1newPos;
int S2newPos;
int S3newPos;
int S4newPos;


void setup() {
  Serial.begin(9600);
  getValue.begin(9600);
  srituhobby.begin();
  srituhobby.setPWMFreq(60);
  srituhobby.setPWM(servo1, 0, S1curntPos);
  srituhobby.setPWM(servo2, 0, S2curntPos);
  srituhobby.setPWM(servo3, 0, S3curntPos);
  srituhobby.setPWM(servo4, 0, S4curntPos);
  delay(500);
}

void loop() {
  robotArm();
}

void robotArm() {
  if (getValue.available() > 0) {
    String value = getValue.readString();
    if (value.startsWith("S1")) {
      value = value.substring(3, value.length());
      int S1 = value.toInt();
      S1 = map(S1, 0, 180, 150, 600);

      S1 = S1 - S1curntPos;

      for (int a = 0; a <= S1 ; a++) {
        delay(1);
        Serial.println(a);
        S1newPos = S1curntPos + a;
        Serial.print("Servo");
        Serial.println(S1newPos);
        srituhobby.setPWM(servo1, 0, S1newPos);
      }

      for (int b = 0 ; b >= S1; b--) {
        delay(1);
        Serial.println(b);
        int c = b * -1;
        S1newPos = S1curntPos - c;
        Serial.print("Servo");
        Serial.println(S1newPos);
        srituhobby.setPWM(servo1, 0, S1newPos);
      }

      S1curntPos = S1curntPos + S1;
      Serial.print("curntPos:");
      Serial.print(S1curntPos);

    } else if (value.startsWith("S2")) {
      value = value.substring(3, value.length());
      int S2 = value.toInt();
      S2 = map(S2, 0, 180, 150, 600);

      S2 = S2 - S2curntPos;

      for (int a = 0; a <= S2 ; a++) {
        delay(1);
        S2newPos = S2curntPos + a;
        srituhobby.setPWM(servo2, 0, S2newPos);
      }

      for (int b = 0 ; b >= S2; b--) {
        delay(1);
        int c = b * -1;
        S2newPos = S2curntPos - c;
        srituhobby.setPWM(servo2, 0, S2newPos);
      }
      S2curntPos = S2curntPos + S2;

    } else if (value.startsWith("S3")) {
      value = value.substring(3, value.length());
      int S3 = value.toInt();
      S3 = map(S3, 0, 180, 150, 600);

      S3 = S3 - S3curntPos;

      for (int a = 0; a <= S3 ; a++) {
        delay(1);
        S3newPos = S3curntPos + a;
        srituhobby.setPWM(servo3, 0, S3newPos);
      }

      for (int b = 0 ; b >= S3; b--) {
        delay(1);
        int c = b * -1;
        S3newPos = S3curntPos - c;
        srituhobby.setPWM(servo3, 0, S3newPos);
      }
      S3curntPos = S3curntPos + S3;

    } else if (value.startsWith("S4")) {
      value = value.substring(3, value.length());
      int S4 = value.toInt();
      S4 = map(S4, 0, 180, 150, 600);

      S4 = S4 - S4curntPos;

      for (int a = 0; a <= S4 ; a++) {
        delay(1);
        S4newPos = S4curntPos + a;
        srituhobby.setPWM(servo4, 0, S4newPos);
      }

      for (int b = 0 ; b >= S4; b--) {
        delay(1);
        int c = b * -1;
        S4newPos = S4curntPos - c;
        srituhobby.setPWM(servo4, 0, S4newPos);
      }
      S4curntPos = S4curntPos + S4;
    }
  }
}
