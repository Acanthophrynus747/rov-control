/*
TODO: research alternative motor drivers (currently HW-039). something easier to reverse? check parts supply
https://www.handsontec.com/dataspecs/module/BTS7960%20Motor%20Driver.pdf
*/
#include <Arduino.h>

const int L_stick_x_pin = 34; //maybe CHANGE THESE LATER
const int L_stick_y_pin = 35;
const int R_stick_x_pin = 32;
const int R_stick_y_pin = 33;

// const int motor1_fwd = 5; //maybe CHANGE LATER TOO
// const int motor1_rev = 18;
// const int motor2_fwd = 19; //MOTOR CONTROLLERS
// const int motor2_rev = 21;
// const int motor3_fwd = 22; //motor 1 left fwd, 2 right fwd, 3 up/dn
// const int motor3_rev = 23;

const int enable_motors_pin = 25; //switch to enable motors/change state

// variables for control inputs to send to ROV
int motor1_pwr, motor2_pwr, motor3_pwr;
bool lights_on = true;

int motor1_thrust(int joy_x, int joy_y);
int motor2_thrust(int joy_x, int joy_y);
int motor3_thrust(int joy_x, int joy_y);

String controlMsg(int motor1_pwr, int motor2_pwr, int motor3_pwr, bool lights_on);

void off(void);
void run(void);

enum State {
    // likely unnessesary but this could be helpful to be able to switch between control modes
    MOTORS_OFF = 0,
    MAIN = 1
};

State state;

void setup(){
    Serial.begin(115200);

    pinMode(L_stick_x_pin, INPUT);
    pinMode(L_stick_y_pin, INPUT);
    pinMode(R_stick_x_pin, INPUT);
    pinMode(R_stick_y_pin, INPUT);

    // pinMode(motor1_fwd, OUTPUT);
    // pinMode(motor1_rev, OUTPUT);
    // pinMode(motor2_fwd, OUTPUT);
    // pinMode(motor2_rev, OUTPUT);
    // pinMode(motor3_fwd, OUTPUT);
    // pinMode(motor3_rev, OUTPUT);
}

void loop(){
    switch(state){
        case(MOTORS_OFF):
        off();
        break;

        case(MAIN):
        run();
        break;
    }

}

void off(){
    Serial.println("powered off");
    delay(1000);
    if (digitalRead(enable_motors_pin) == HIGH){
        state = MAIN;
    }
}

void run(){
    //read joysticks
    int R_stick_x = analogRead(R_stick_x_pin);
    int R_stick_y = analogRead(R_stick_y_pin);
    int L_stick_x = 0; //maybe just make this 0 if not used?
    int L_stick_y = analogRead(L_stick_y_pin);

    //calculate the power that should go to motors based on stick pos
    motor1_pwr = motor1_thrust(R_stick_x, R_stick_y);
    motor2_pwr = motor2_thrust(R_stick_x, R_stick_y);
    motor3_pwr = motor3_thrust(L_stick_x, L_stick_y);

    String control_msg = controlMsg(motor1_pwr, motor2_pwr, motor3_pwr, lights_on);

    
}

int motor1_thrust(int joy_x, int joy_y){
    // int x = map(joy_x, 0, 1023, -255, 255);
    // int y = map(joy_y, 0, 1023, -255, 255);
    int x = map(joy_x, 0, 1023, 0, 510);
    int y = map(joy_y, 0, 1023, 0, 510); //changed to 0-510 to avoid having to send a negative number over serial

    int motor_thrust = (x + y);

    return motor_thrust; //handle it returning a negative value in main code
}

int motor2_thrust(int joy_x, int joy_y){
    int x = map(joy_x, 0, 1023, 0, 510);
    int y = map(joy_y, 0, 1023, 0, 510);
    
    int motor_thrust = ((-1 * joy_x) + joy_y);

    return motor_thrust;
}

int motor3_thrust(int joy_x, int joy_y){
    int y = map(joy_y, 0, 1023, 0, 510);

    int motor_thrust = y;

    return motor_thrust;
}

String controlMsg(int motor1_pwr, int motor2_pwr, int motor3_pwr, bool lights_on){
    String control_str = "A" + String(motor1_pwr) + "B" + String(motor2_pwr) + "C" + String(motor3_pwr) + "D" + String(lights_on);
    return control_str;
}
