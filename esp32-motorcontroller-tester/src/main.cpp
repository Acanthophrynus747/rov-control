#include <Arduino.h>
#include <ESP32Servo.h>

const int motor1_fwd = 27;
const int motor1_rev = 14;
const int motor2_fwd = 25;
const int motor2_rev = 26;
const int motor3_fwd = 32;
const int motor3_rev = 33;

void setup(){
    
    Serial.begin(115200);

    pinMode(motor1_fwd, OUTPUT);
    pinMode(motor1_rev, OUTPUT);
    pinMode(motor2_fwd, OUTPUT);
    pinMode(motor2_rev, OUTPUT);
    pinMode(motor3_fwd, OUTPUT);
    pinMode(motor3_rev, OUTPUT);
}

void loop(){

    Serial.println("fwd 255");
    analogWrite(motor1_fwd, 255);
    analogWrite(motor2_fwd, 255);
    analogWrite(motor3_fwd, 255);
    analogWrite(motor1_rev, 0);
    analogWrite(motor2_rev, 0);
    analogWrite(motor3_rev, 0);
    delay(5000);

    Serial.println("fwd 100");
    analogWrite(motor1_fwd, 100);
    analogWrite(motor2_fwd, 100);
    analogWrite(motor3_fwd, 100);
    analogWrite(motor1_rev, 0);
    analogWrite(motor2_rev, 0);
    analogWrite(motor3_rev, 0);
    delay(5000);

    Serial.println("stop");
    analogWrite(motor1_fwd, 0);
    analogWrite(motor2_fwd, 0);
    analogWrite(motor3_fwd, 0);
    analogWrite(motor1_rev, 0);
    analogWrite(motor2_rev, 0);
    analogWrite(motor3_rev, 0);
    delay(5000);

    Serial.println("rev 100");
    analogWrite(motor1_fwd, 0);
    analogWrite(motor2_fwd, 0);
    analogWrite(motor3_fwd, 0);
    analogWrite(motor1_rev, 100);
    analogWrite(motor2_rev, 100);
    analogWrite(motor3_rev, 100);
    delay(5000);

    Serial.println("rev 255");
    analogWrite(motor1_fwd, 0);
    analogWrite(motor2_fwd, 0);
    analogWrite(motor3_fwd, 0);
    analogWrite(motor1_rev, 255);
    analogWrite(motor2_rev, 255);
    analogWrite(motor3_rev, 255);
    delay(5000);

    Serial.println("stop");
    analogWrite(motor1_fwd, 0);
    analogWrite(motor2_fwd, 0);
    analogWrite(motor3_fwd, 0);
    analogWrite(motor1_rev, 255);
    analogWrite(motor2_rev, 255);
    analogWrite(motor3_rev, 255);
    delay(5000);
}