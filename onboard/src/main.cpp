#include <Arduino.h>

const int TXD2 = 17;
const int RXD2 = 16;

const int motor1_fwd = 5; //maybe CHANGE LATER
const int motor1_rev = 18;
const int motor2_fwd = 19; //MOTOR CONTROLLERS
const int motor2_rev = 21;
const int motor3_fwd = 22; //motor 1 left fwd, 2 right fwd, 3 up/dn
const int motor3_rev = 23;

const int enable_motors_pin = 25; //switch to enable motors/change state

HardwareSerial tetherSerial(2);

void setup() {
    Serial.begin(115200);
    tetherSerial.begin(1000);
}

void loop() {

}