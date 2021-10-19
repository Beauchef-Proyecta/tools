
/*
 Helper Monster for Testing our Arduinos

 Created 19 Oct. 2021
 by FranciscoCasado

 */

#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 2038;  // DO NOT CHANGE THIS VALUE FOR THIS CODE


Stepper myStepper1(stepsPerRevolution, 0, 2, 1, 4);
Stepper myStepper2(stepsPerRevolution, 7, 12, 8, 13);

int stepCount = 0;

Servo myservo3;  
Servo myservo5; 
Servo myservo6;
Servo myservo9;
Servo myservo10;
Servo myservo11;

int pos = 0;    // variable to store the servo position

const int analog0 = A0;
const int analog1 = A1;
const int analog2 = A2;
const int analog3 = A3;
const int analog4 = A4;
const int analog5 = A5;
int sensorValue0 = 0;
int sensorValue1 = 0; 
int sensorValue2 = 0; 
int sensorValue3 = 0; 
int sensorValue4 = 0; 
int sensorValue5 = 0; 
int pos_servo0 = 0;
int pos_servo1 = 0;
int pos_servo2 = 0;
int pos_servo3 = 0;
int pos_servo4 = 0;
int pos_servo5 = 0;


void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  
  myservo3.attach(3);
  myservo5.attach(5);
  myservo6.attach(6);
  myservo9.attach(9);
  myservo10.attach(10);
  myservo11.attach(11);
  
  // initialize the serial port:
  Serial.begin(9600);

}

void loop() {
  

  for (pos = 0; pos <= 180; pos += 1) {
    
    sensorValue0 = analogRead(analog0);
    pos_servo0 = map(sensorValue0, 0, 1023, 0, 180);
    
    sensorValue1 = analogRead(analog1);
    pos_servo1 = map(sensorValue1, 0, 1023, 0, 180);
    
    sensorValue2 = analogRead(analog2);
    pos_servo2 = map(sensorValue2, 0, 1023, 0, 180);
    
    sensorValue3 = analogRead(analog3);
    pos_servo3 = map(sensorValue3, 0, 1023, 0, 180);
    
    sensorValue4 = analogRead(analog4);
    pos_servo4 = map(sensorValue4, 0, 1023, 0, 180);
    
    sensorValue5 = analogRead(analog5);
    pos_servo5 = map(sensorValue5, 0, 1023, 0, 180);
    
    Serial.print("A0[");
    Serial.print(sensorValue0);
    Serial.print("]..");
    Serial.print("A1[");
    Serial.print(sensorValue1);
    Serial.print("]..");
    Serial.print("A2[");
    Serial.print(sensorValue2);
    Serial.print("]..");
    Serial.print("A3[");
    Serial.print(sensorValue3);
    Serial.print("]..");
    Serial.print("A4[");
    Serial.print(sensorValue4);
    Serial.print("]..");
    Serial.print("A5[");
    Serial.print(sensorValue5);
    Serial.println("]");
  
    myservo3.write(pos_servo0);
    myservo5.write(pos_servo1);
    myservo6.write(pos_servo2);
    myservo9.write(pos_servo3);
    myservo10.write(pos_servo4);
    myservo11.write(pos_servo5);
  
    myStepper1.step(1);
    myStepper2.step(1);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    sensorValue0 = analogRead(analog0);
    pos_servo0 = map(sensorValue0, 0, 1023, 0, 180);
    
    sensorValue1 = analogRead(analog1);
    pos_servo1 = map(sensorValue1, 0, 1023, 0, 180);
    
    sensorValue2 = analogRead(analog2);
    pos_servo2 = map(sensorValue2, 0, 1023, 0, 180);
    
    sensorValue3 = analogRead(analog3);
    pos_servo3 = map(sensorValue3, 0, 1023, 0, 180);
    
    sensorValue4 = analogRead(analog4);
    pos_servo4 = map(sensorValue4, 0, 1023, 0, 180);
    
    sensorValue5 = analogRead(analog5);
    pos_servo5 = map(sensorValue5, 0, 1023, 0, 180);
    
    pinMode(0,INPUT);
    Serial.print("A0[");
    Serial.print(sensorValue0);
    Serial.print("]..");
    Serial.print("A1[");
    Serial.print(sensorValue1);
    Serial.print("]..");
    Serial.print("A2[");
    Serial.print(sensorValue2);
    Serial.print("]..");
    Serial.print("A3[");
    Serial.print(sensorValue3);
    Serial.print("]..");
    Serial.print("A4[");
    Serial.print(sensorValue4);
    Serial.print("]..");
    Serial.print("A5[");
    Serial.print(sensorValue5);
    Serial.println("]");
    pinMode(0,OUTPUT);
  
    myservo3.write(pos_servo0);
    myservo5.write(pos_servo1);
    myservo6.write(pos_servo2);
    myservo9.write(pos_servo3);
    myservo10.write(pos_servo4);
    myservo11.write(pos_servo5);
    myStepper1.step(-1);
    myStepper2.step(-1);
  }

  
}
