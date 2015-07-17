#include "ariettaTalks.h"

#include "test_HID.h"
#include <Arduino.h>
#include "Wire.h"

int incomingByte = 0;
int charCount = 0;
char command[MAX_COMMAND_LENGTH + 1]; // leave space for \0
bool locked = false;
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  Serial2.begin(9600);
}

void loop() {
  if (Serial2.available()) {
    incomingByte = Serial2.read();

    if ((char)incomingByte == resetByte) {
      locked = false;
      charCount = 0;
      return;
    }

    if (locked) {
      Serial2.println("@");
      return;
    }

    if ((char)incomingByte != stopByte) {
      if (charCount > MAX_COMMAND_LENGTH - 1) {
        Serial2.println("@");
        locked = true;
        return;
      }
      else {
        command[charCount] = (char)incomingByte;
        charCount++;
      }
    }
    else {
      command[charCount] = '\0';
      charCount = 0;
      if (strcmp(commandLEDOn, command) == 0) {
        digitalWrite(led, HIGH);
        Serial2.println(replyOK);
      }
      else if (strcmp(commandLEDOff, command) == 0) {
        digitalWrite(led, LOW);
        Serial2.println(replyOK);
      }
    }
  }
}
