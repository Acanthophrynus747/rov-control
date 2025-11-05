#include <Arduino.h>

int motor1_thrust(int joy_x, int joy_y){
    int x = map(joy_x, 0, 1023, -255, 255);
    int y = map(joy_y, 0, 1023, -255, 255);

    int motor_thrust = (x + y);

    return motor_thrust; //handle it returning a negative value in main code
}

int motor2_thrust(int joy_x, int joy_y){
    int x = map(joy_x, 0, 1023, -255, 255);
    int y = map(joy_y, 0, 1023, -255, 255);
    
    int motor_thrust = ((-1 * joy_x) + joy_y);

    return motor_thrust;
}

int motor3_thrust(int joy_x, int joy_y){
    int y = map(joy_x, 0, 1023, -255, 255);

    int motor_thrust = y;

    return motor_thrust;
}