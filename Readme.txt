1. Temperature-Controlled PWM Motor Speed

🎯 Overview

This project, built with an Arduino Uno, monitors ambient temperature using an LM35 sensor. It automatically adjusts the speed of a DC motor by generating a PWM signal, with the motor's speed being directly proportional to the temperature. The current temperature (in Celsius) and motor speed (as a percentage) are displayed in real-time on a 16x2 I2C LCD.

✨ Key Features

Reads real-time temperature from an LM35 analog sensor.

Displays the current temperature (°C) and motor speed (%) on a 16x2 I2C LCD.

Generates a PWM signal to control the speed of a DC motor using an L298N driver.

Motor speed is linearly mapped to a specific temperature range (off below 20°C, full speed above 50°C).

🛠️ Tech Stack & Components

Microcontroller: Arduino Uno

Sensor: DHT11 sensor Analog Temperature Sensor

Display: 16x2 I2C LCD

Actuator: L298N Motor Driver Module

Motor: 5V-12V DC Motor

Power: External 9V/12V Power Supply (for L298N)

Software: C++ (Arduino IDE)

📸 Demo & Schematics

Here are the visuals for the project.

Circuit Diagram:
This diagram shows all the connections for the project.

Project Photo:
Added

Video Demo:
Added

We have used an LED to show the duty cycle instead of a DC Motor. But the dc motor will produce the same result as it is for output purpose only.
Used DHT11 as LM35 was not available on local market

🔧 How It Works

The logic is straightforward:

Read Sensor: The LM35 sensor outputs an analog voltage (10mV per degree Celsius). This voltage is read by one of the Arduino's analog-to-digital converter (ADC) pins.

Calculate Temp: The code converts the raw ADC value (0-1023) into a floating-point temperature value in degrees Celsius.

Map Speed: This temperature value is then mapped to a PWM duty cycle value (0-255). Based on the code, this mapping is:

MIN_TEMP (20°C) = 0 speed (0% duty cycle)

MAX_TEMP (50°C) = 255 speed (100% duty cycle)

Control Motor: The analogWrite() function sends this PWM signal to the ENA (Enable) pin of the L298N motor driver, which in turn delivers the correct amount of power to the motor.

Display: Simultaneously, the calculated temperature and speed percentage are sent to the I2C LCD for real-time monitoring.



clc;
clear;
close all;
a_deg = 120;
a = 1 * exp(1j * deg2rad(a_deg));
Va = 10 * exp(1j * deg2rad(90));  
Vb = 5  * exp(1j * deg2rad(30));  
Vc = 10 * exp(1j * deg2rad(210)); 
a2 = a^2;
Va0 = (1/3) * (Va + Vb + Vc);       
Va1 = (1/3) * (Va + a*Vb + a2*Vc);         
Va2 = (1/3) * (Va + a2*Vb + a*Vc);         

Vb0 = Va0;
Vb1 = a2 * Va1;
Vb2 = a * Va2;

Vc0 = Va0;
Vc1 = a * Va1;
Vc2 = a2 * Va2;
figure; 
sgtitle('Symmetrical Component Analysis of Unbalanced Voltages');

subplot(2, 2, 2);
compass([Va0, Vb0, Vc0], 'k');
title('Zero-Sequence Components');
legend('Va0', 'Vb0', 'Vc0', 'Location', 'northeast');

subplot(2, 2, 1);
compass([Va, Vb, Vc], 'b');
title('Original Unbalanced Phasors');
legend('Va', 'Vb', 'Vc', 'Location', 'northeast');

subplot(2, 2, 3);
compass([Va1, Vb1, Vc1], 'r');
title('Positive-Sequence Components (ABC)');
legend('Va1', 'Vb1', 'Vc1', 'Location', 'northeast');

subplot(2, 2, 4);
compass([Va2, Vb2, Vc2], 'm');
title('Negative-Sequence Components (ACB)');
legend('Va2', 'Vb2', 'Vc2', 'Location', 'northeast');
