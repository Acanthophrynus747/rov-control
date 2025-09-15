//TODO: research alternative motor drivers (currently HW-039). something easier to reverse? check parts supply

#include <Arduino.h>

const int L_stick_x_pin = 1; //CHANGE THESE LATER
const int L_stick_y_pin = 2;
const int R_stick_x_pin = 3;
const int R_stick_y_pin = 4;

const int motor1_fwd = 5; //CHANGE LATER TOO
const int motor1_rev = 6;
const int motor2_fwd = 7; //MOTOR CONTROLLERS
const int motor2_rev = 8;
const int motor3_fwd = 9;
const int motor3_rev = 10;

void setup(){
    Serial.begin(115200);

    pinMode(L_stick_x_pin, INPUT);
    pinMode(L_stick_y_pin, INPUT);
    pinMode(R_stick_x_pin, INPUT);
    pinMode(R_stick_y_pin, INPUT);

    pinMode(motor1_fwd, OUTPUT);
    pinMode(motor1_rev, OUTPUT);
    pinMode(motor2_fwd, OUTPUT);
    pinMode(motor2_rev, OUTPUT);
    pinMode(motor3_fwd, OUTPUT);
    pinMode(motor3_rev, OUTPUT);
}

void loop(){



}