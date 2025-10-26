#include <Arduino.h>
#include <HardwareSerial.h>

String msg = "ZA234B128C056D1X";

HardwareSerial TestSerial(2);

void setup(){
    Serial.begin(115200);
    TestSerial.begin(1000);
}

void loop(){
    TestSerial.print(msg);
    Serial.println("sent test message");
}