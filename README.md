# Analog Input and Interrupts – Arduino Project

This project demonstrates how to use analog input from a light sensor and external interrupts from a button to control an LED and buzzer on an Arduino Uno using the Grove system.


## 🎯 Objective

Utilize an analog light sensor to control an LED based on ambient light levels, and use a button press to trigger an interrupt that activates a buzzer for 5 seconds, regardless of further input.

## 🧰 Components Required

- Arduino Uno  
- Arduino Base Shield  
- Grove Light Sensor (Analog Port)  
- Grove Button (Digital Port)  
- Grove Buzzer (Digital Port)  
- LED (Connected via digital pin)  
- Grove Cables  
- Arduino IDE

## ⚙️ System Behavior

### 1. **Light Sensor LED Control**
- Define a threshold value (e.g., 500).
- If light level is **above** the threshold → **LED turns ON**.
- If light level is **below** the threshold → **LED turns OFF**.

### 2. **Interrupt with Button**
- When button is pressed:
  - An **external interrupt** is triggered.
  - The **buzzer rings for 5 seconds**, regardless of whether the button is held or released.
- After the buzzer finishes, normal light sensor–based LED control resumes.

## 💾 How It Works (Flow)

```plaintext
Setup:
 - Initialize I/O pins
 - Attach interrupt to button pin
 - Set threshold for light sensor

Loop:
 - Continuously read light level from sensor
 - Turn LED on/off based on threshold

Interrupt Service Routine (ISR):
 - Triggered on button press
 - Activate buzzer for 5 seconds
