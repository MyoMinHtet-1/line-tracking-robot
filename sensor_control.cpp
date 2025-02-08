#include "sensor_control.h"
#include "config.h"
#include <Arduino.h>

// Initialize sensor pins
void setupSensors() {
    pinMode(left_ang, INPUT);
    pinMode(right_ang, INPUT);
    pinMode(fleft_ang, INPUT);
    pinMode(fright_ang, INPUT);
}

// Read sensor value and compare it with a threshold
int readSensor(int pin, int threshold) {
    int sensorValue = analogRead(pin);
    return (sensorValue >= threshold) ? 1 : 0;
}
