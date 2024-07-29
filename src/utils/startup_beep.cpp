#include <Arduino.h>

void invokeStartupBeep(unsigned int buzzerPin) {
    tone(buzzerPin, 400);
    delay(200);
    noTone(buzzerPin);
    delay(200);
    tone(buzzerPin, 400);
    delay(200);
    noTone(buzzerPin);
}