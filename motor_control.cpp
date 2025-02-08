#include "motor_control.h"
#include "config.h"
#include <Arduino.h>

// Initialize motor control pins
void setupMotors() {
    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);
    pinMode(pin_ena, OUTPUT);
    pinMode(pin_enb, OUTPUT);
}

// Set motor directions
void setupMotors(int forward_a, int forward_b) {
    // Control left motor
    if (forward_a == 1) {
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);
    } else {
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);
    }

    // Control right motor
    if (forward_b == 1) {
        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);
    } else {
        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);
    }
}

// Adjust motor speeds using PWM
void changeSpeed(int speed_a, int speed_b) {
    analogWrite(pin_ena, speed_a);
    analogWrite(pin_enb, speed_b);
}

// Stop both motors
void brake() {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
}
