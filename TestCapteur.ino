#include <Servo.h>
#include <Ultrasonic.h>

const int Trig1 = 12;     // pin "Trig" du HC-SR04 connectée à pin 13 de l'Arduino
const int Echo1 = 13;     // pin "Echo" du HC-SR04 connectée à pin 12 de l'Arduino

const int Trig2 = 10;     // pin "Trig" du HC-SR04 connectée à pin 13 de l'Arduino
const int Echo2 = 11;     // pin "Echo" du HC-SR04 connectée à pin 12 de l'Arduino

const int pinServo1 = 9;     // pin "Echo" du HC-SR04 connectée à pin 12 de l'Arduino


const int ecartFiabilite = 20;

Ultrasonic HCSR04_1(Trig1,Echo1);
Ultrasonic HCSR04_2(Trig2,Echo2);

Servo servo1;

long cm1, cm2, distance1, distance2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Init");
  servo1.write(0);
  servo1.attach(pinServo1);

}

void loop() {
  // put your main code here, to run repeatedly:
  distance1 = HCSR04_1.convert(HCSR04_1.timing(), 1);
  delay(100);
  /*distance2 = HCSR04_1.convert(HCSR04_1.timing(), 1);
  delay(100);
  if ((distance1<200) & (distance2<200) & (abs(distance1-distance2)< ecartFiabilite)) {
    cm1 = distance2;
    Serial.print("Distance1 :");
    Serial.println(cm1);
  }
  else
  {
    Serial.print("Distance1 :");
    Serial.println("NON FIABLE");
  }*/
  cm1 = distance1;
  Serial.print("Distance1 :");
  Serial.println(cm1);
  delay(100);
  cm2 = HCSR04_2.convert(HCSR04_2.timing(), 1);
  Serial.print("Distance2 :");
  Serial.println(cm2);
  delay(100);
  // calcul angle
  if (cm1 < cm2)
  {
    servo1.write(90);
    delay(100);
  }
  else
  {
      if (cm1 > cm2)
      {
         servo1.write(180);
         delay(100);
       }
      else
      {
         servo1.write(0);
        delay(100);
      }
  }
}
