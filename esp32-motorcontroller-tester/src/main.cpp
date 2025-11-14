#include <Arduino.h>
#include <ESP32Servo.h>

// PROBLEM FOUND, BAD CUSTOM CIRCUIT BOARD
// TODO: check all motor drivers

const int motor1_fwd = 26;
const int motor1_rev = 25;
// const int motor2_fwd = 26;
// const int motor2_rev = 25;
// const int motor3_fwd = 33;
// const int motor3_rev = 32;

const int pwm_freq = 10000; // Hz
const int pwm_resolution = 8; // 8 bit, 0 to 255 value
const int pwm_channel = 0;

// ESP32PWM pwm;



void setup(){
    Serial.begin(115200);

    // pinMode(motor1_fwd, OUTPUT);
    // pinMode(motor1_rev, OUTPUT);

    // ESP32PWM::allocateTimer(0);
    // ESP32PWM::allocateTimer(1);
    // ESP32PWM::allocateTimer(2);
    // ESP32PWM::allocateTimer(3);

    // pwm.attachPin(motor1_fwd, pwm_freq, pwm_resolution);
    
    pinMode(motor1_fwd, OUTPUT);
    pinMode(motor1_rev, OUTPUT);
    // pinMode(motor2_fwd, OUTPUT);
    // pinMode(motor2_rev, OUTPUT);
    // pinMode(motor3_fwd, OUTPUT);
    // pinMode(motor3_rev, OUTPUT);
}

void loop(){

    Serial.println("fwd 255");
    analogWrite(motor1_fwd, 255);
    // analogWrite(motor1_rev, 0);
    // ledcWrite(motor1_fwd, 255);
    // pwm.write(255);
    delay(5000);

    Serial.println("fwd 100");
    analogWrite(motor1_fwd, 100);
    // analogWrite(motor1_rev, 0);
    // ledcWrite(motor1_fwd, 100);
    // pwm.write(100);
    // delay(5000);

    // Serial.println("stop");
    // analogWrite(motor1_fwd, 0);
    // analogWrite(motor1_rev, 0);
    // ledcWrite(motor1_fwd, 0);
    // pwm.write(0);
    delay(5000);

    // Serial.println("rev 100");
    // analogWrite(motor1_rev, 100);
    // // ledcWrite(motor1_rev, 100);
    // delay(2000);

    // Serial.println("stop");
    // analogWrite(motor1_rev, 0);
    // // ledcWrite(motor1_rev, 0);
    // delay(2000);
}