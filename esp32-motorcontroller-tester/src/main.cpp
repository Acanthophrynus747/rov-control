#include <Arduino.h>

const int motor1_fwd = 14;
const int motor1_rev = 27;
const int motor2_fwd = 26;
const int motor2_rev = 25;
const int motor3_fwd = 33;
const int motor3_rev = 32;

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
    delay(2000);
    Serial.println("fwd 255");
    analogWrite(motor1_fwd, 255);
    delay(2000);
    Serial.println("fwd 100");
    analogWrite(motor1_fwd, 100);
    delay(2000);
    Serial.println("stop");
    analogWrite(motor1_fwd, 0);
    delay(1000);
    Serial.println("rev 100");
    analogWrite(motor1_rev, 100);
    delay(2000);
}