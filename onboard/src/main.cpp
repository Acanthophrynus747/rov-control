// ideas: possibly add check of tether connection so motors can be shut off if control connection is broken

#include <Arduino.h>
#include <HardwareSerial.h>

const int TXD2 = 17;
const int RXD2 = 16;

const int motor1_fwd = 5; //maybe CHANGE LATER
const int motor1_rev = 18;
const int motor2_fwd = 19; //MOTOR CONTROLLERS
const int motor2_rev = 21;
const int motor3_fwd = 22; //motor 1 left fwd, 2 right fwd, 3 up/dn
const int motor3_rev = 23;

const int light_relay = 24; //prob change later

const int enable_motors_pin = 25; // motor enable pins on motor driver (maybe wire to +5V)

void off(void);
void run(void);
void controlOutput(int motor1_thrust, int motor2_thrust, int motor3_thrust, int lights_on);

enum State {
    // likely unnessesary but this could be helpful to be able to switch between control modes
    MOTORS_OFF = 0,
    MAIN = 1
};

State state;

HardwareSerial TetherSerial(2);

void setup() {
    Serial.begin(115200);
    TetherSerial.begin(1000);

    pinMode(motor1_fwd, OUTPUT);
    pinMode(motor1_rev, OUTPUT);
    pinMode(motor2_fwd, OUTPUT);
    pinMode(motor2_rev, OUTPUT);
    pinMode(motor3_fwd, OUTPUT);
    pinMode(motor3_rev, OUTPUT);
    //possibly other pins, sensors, controls, etc...

    digitalWrite(enable_motors_pin, HIGH);
}

void loop() {
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
    //logic to turn on
    state = MAIN; // do not keep it like this
}

void run(){
    String command = "";
    char input;

    if (TetherSerial.available()){
        char input = TetherSerial.read();
    }

    if (input == 'Z'){
        // start of new control message,
        input = TetherSerial.read();
        while (input != 'X'){
            if (TetherSerial.available()){
                command += input; //check the logic here, there might be problems
            }
        }
    }
    Serial.println(command); //for debugging

    int A_index = command.indexOf('A');
    int B_index = command.indexOf('B');
    int C_index = command.indexOf('C');
    int D_index = command.indexOf('D');

    String A_val = command.substring(A_index, A_index + 3);
    String B_val = command.substring(B_index, B_index + 3);
    String C_val = command.substring(C_index, C_index + 3);
    String D_val = command.substring(D_index, D_index + 1);

    // debugging
    Serial.print("A: ");
    Serial.println(A_val);
    Serial.print("B: ");
    Serial.println(B_val);
    Serial.print("C: ");
    Serial.println(C_val);
    Serial.print("D: ");
    Serial.println(D_val);

    int motor1_thrust = A_val.toInt() - 255; // will this error if there's a letter in there? maybe add something to handle that
    int motor2_thrust = B_val.toInt() - 255; // the values are offset by 255 to not have to send a negative 
    int motor3_thrust = C_val.toInt() - 255; // these repetitive lines could all probably be a for loop
    int lights_on = D_val.toInt();

    controlOutput(motor1_thrust, motor2_thrust, motor3_thrust, lights_on);
}

void controlOutput(int motor1_thrust, int motor2_thrust, int motor3_thrust, int lights_on){
    if (motor1_thrust < 0){
        analogWrite(motor1_rev, motor1_thrust * -1); // change to positive. I think it needs to be positive
    }
    else{
        analogWrite(motor1_fwd, motor1_thrust);
    }

    if (motor2_thrust < 0){
        analogWrite(motor2_rev, motor2_thrust * -1);
    }
    else{
        analogWrite(motor2_fwd, motor2_thrust);
    }

    if (motor3_thrust < 0){
        analogWrite(motor3_rev, motor3_thrust * -1);
    }
    else{
        analogWrite(motor3_fwd, motor3_thrust);
    }

    if (lights_on == 0){
        digitalWrite(light_relay, HIGH); // high is off, I think this could make if fail lights on which I think is better
    }
    else{
        digitalWrite(light_relay, LOW); // is this neccessary?
    }
}
