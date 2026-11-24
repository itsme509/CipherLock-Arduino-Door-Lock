/*
 * CipherLock: Arduino-Based Keypad Door Unlocking System
 * Authors: Muhammad Ehtesham & Muhammad Asghar
 * Department of Electrical Engineering, COMSATS University Islamabad (CUI)
 */

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Update these pin numbers to match your Arduino Nano wiring
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int RELAY_PIN = 10;               // Pin connected to 1-Channel Relay IN
const bool RELAY_ACTIVE_LOW = true;     // Change to false if relay triggers on HIGH
const unsigned long UNLOCK_TIME = 5000; // 5-second auto-lock delay

const String MASTER_PASSCODE = "4743";  // Passcode (4743# to enter, * to clear)
String enteredCode = "";

void setLockState(bool unlock) {
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(RELAY_PIN, unlock ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_PIN, unlock ? HIGH : LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  setLockState(false); // Start locked
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '*') {
      enteredCode = ""; // Clear input
    } 
    else if (key == '#') {
      if (enteredCode == MASTER_PASSCODE) {
        setLockState(true);   // Unlock relay
        delay(UNLOCK_TIME);   // Wait 5 seconds
        setLockState(false);  // Auto-lock again
      }
      enteredCode = "";
    } 
    else {
      if (enteredCode.length() < 8) {
        enteredCode += key;
      }
    }
  }
}
