![image](https://github.com/user-attachments/assets/a4e9add5-544f-4fd8-aa17-e033e71dd8f4)# line-tracking-robot
A basic line tracking bot that utilizes a strict rule based controller. 
Materials used: 
• 2 motors
• 2 wheels
• L298N motor driver board
• ARDUINO UNO
• 3 TCRT5000 infrared tubs
• 1 LEDS
• 1 resistors
• 1 mini protoboard
• 4 1.5V Lithium ion batteries
• Cables, screws and bolts

The code works by utilizing 3 IR sensors. Through each void loop() function, it will check if the sensor at the edge detected the black line: if there was a detection, it will recorrect itself by giving more power to the opposing wheel's motor, this is done until the center sensor detects the black line. The main objective of the car is to have the center wheels on the black line
![image](https://github.com/user-attachments/assets/7b94dd88-ace6-4a20-bbbc-b9bc874d4d37)
![image](https://github.com/user-attachments/assets/059233ab-ee6d-4fd1-b56b-c810effe6f4b)
![image](https://github.com/user-attachments/assets/0d39f86f-7573-4465-8d79-c2facff17a39)
