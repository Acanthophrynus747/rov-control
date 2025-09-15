#include <Arduino.h>

const int L_stick_x_pin = 1; //CHANGE THESE LATER
const int L_stick_y_pin = 2;
const int R_stick_x_pin = 3;
const int R_stick_y_pin = 4;

const int motor1 = 5; //CHANGE LATER TOO
const int motor2 = 6; //MOTOR CONTROLLERS
const int motor3 = 7;

void setup(){
    Serial.begin(115200);

    pinMode(L_stick_x_pin, INPUT);
    pinMode(L_stick_y_pin, INPUT);
    pinMode(R_stick_x_pin, INPUT);
    pinMode(R_stick_y_pin, INPUT);

    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    pinMode(motor3, OUTPUT);

}

void loop(){

}