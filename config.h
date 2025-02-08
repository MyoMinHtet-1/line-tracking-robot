#ifndef CONFIG_H
#define CONFIG_H

// Motor control pins
const int motor1pin1 = 2;
const int motor1pin2 = 3;
const int motor2pin1 = 4;
const int motor2pin2 = 5;

// Motor speed control pins
const int pin_ena = 9;
const int pin_enb = 10;

// Sensor pins
const int fleft_ang = A0;
const int fright_ang = A1;
const int left_ang = A2;
const int right_ang = A4;

// Sensor threshold values
const int threshold_fleft = 400;
const int threshold_fright = 200;
const int threshold_left = 150;
const int threshold_right = 150;

#endif // CONFIG_H
