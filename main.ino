#include "config.h"        // Pin definitions and threshold values
#include "motor_control.h" // Motor control functions
#include "sensor_control.h" // Sensor reading functions

void setup() {
    setupMotors();  // Initialize motor pins
    setupSensors(); // Initialize sensor pins
    Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
    // Read sensor values
    int value_fleft = readSensor(fleft_ang, threshold_fleft);
    int value_fright = readSensor(fright_ang, threshold_fright);
    int value_left = readSensor(left_ang, threshold_left);
    int value_right = readSensor(right_ang, threshold_right);

    // 90-degree left turn
    if (value_fright == 1 && value_fleft == 0) {
        brake();
        while (readSensor(left_ang, threshold_left) == 0) {
            changeSpeed(75, 80);
            setupMotors(0, 1); // Turn left
            Serial.println("Going left");
        }
        brake();
    }

    // 90-degree right turn
    if (value_fleft == 1 && value_fright == 0) {
        brake();
        while (readSensor(right_ang, threshold_right) == 0) {
            changeSpeed(70, 80);
            setupMotors(1, 0); // Turn right
            Serial.println("Going right");
        }
        brake();
    }

    // Stop if both sensors detect the line
    if (value_left == 1 && value_right == 1) {
        brake();
    }

    // Move forward if no sensors detect the line
    if (value_left == 0 && value_right == 0 && value_fright == 0 && value_fleft == 0) {
        changeSpeed(80, 80);
        setupMotors(1, 1); // Move forward
        Serial.println("Going Forward");
    }

    // Minor left correction
    if (value_right == 1 && value_left == 0 && value_fright == 0) {
        brake();
        changeSpeed(75, 80);
        setupMotors(0, 1); // Slight left turn
        Serial.println("Correcting left");
    }

    // Minor right correction
    if (value_left == 1 && value_right == 0 && value_fleft == 0) {
        brake();
        changeSpeed(70, 80);
        setupMotors(1, 0); // Slight right turn
        Serial.println("Correcting right");
    }
}
