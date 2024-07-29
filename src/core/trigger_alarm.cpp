#include <Arduino.h>

void triggerAlarm(unsigned int ledsFromRange, unsigned int ledsToRange, unsigned int buzzerPin) {
  for (int i = ledsFromRange; i <= ledsToRange; i++) {
    digitalWrite(i, HIGH);
  }
  tone(buzzerPin, 1000);
};