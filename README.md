# CipherLock: Arduino-Based Keypad Door Unlocking System

**Authors:** Muhammad Ehtesham, Muhammad Asghar  
**Department:** Department of Electrical Engineering  
**Institution:** COMSATS University Islamabad (CUI)  
**Event:** EEECI 2026 / TechForge  

---

## Overview
**CipherLock** is a low-cost, standalone embedded electronic door lock prototype built around an **Arduino Nano**. It replaces physical keys with a secret numeric passcode entered via a **4x4 matrix membrane keypad**, automatically re-locking the door 5 seconds after valid access.

## Hardware Components
* **Microcontroller:** Arduino Nano
* **Input Interface:** 4x4 Matrix Membrane Keypad (`4743#` to unlock, `*` to clear)
* **Switching Stage:** 1-Channel 5V Relay Module
* **Actuator:** Electronic Solenoid Door Lock
* **Power Supply:** 5V USB power for Arduino Nano + dedicated DC battery holder for relay/solenoid circuit (with common ground)

## How It Works
1. The user types the numeric passcode on the 4x4 keypad.
2. Pressing `*` clears any mistyped digits.
3. Pressing `#` submits the code to the Arduino Nano.
4. If the code matches the stored passcode (`4743`), the Arduino triggers the 1-channel relay module ON, supplying battery power to unlock the electronic solenoid lock.
5. After **5 seconds**, the Arduino switches the relay OFF automatically, returning the door to its locked state.

## Software Requirements
* **Arduino IDE**
* **Keypad Library** by Mark Stanley & Alexander Brevig (install via Arduino IDE Library Manager)

## Repository Files
* `CipherLock.ino` — Main Arduino Nano firmware for keypad scanning, passcode verification, and 5-second auto-lock timing.
* `README.md` — Project documentation and hardware overview.
