#include <Arduino.h>
#include <utils/time_to_length.h>
#include <utils/startup_beep.h>
#include <core/trigger_alarm.h>

#define SENSOR_TRIG_PIN 3
#define SENSOR_ECHO_PIN 2
#define BUZZER_PIN 7
#define TRIGGER_DISTANCE 50
#define LEDS_FROM_RANGE 9
#define LEDS_TO_RANGE 12

void setup() {
  for (int i = LEDS_FROM_RANGE; i <= LEDS_TO_RANGE; i++) {
    pinMode(i, OUTPUT);
  }
  
  pinMode(BUZZER_PIN, OUTPUT);

  invokeStartupBeep(BUZZER_PIN);

  Serial.begin (9600);

  pinMode(SENSOR_TRIG_PIN, OUTPUT);
  pinMode(SENSOR_ECHO_PIN, INPUT);
}

int duration, distance;

void loop() {
  
  digitalWrite(SENSOR_TRIG_PIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(SENSOR_TRIG_PIN, HIGH);
  delayMicroseconds(10); 
  digitalWrite(SENSOR_TRIG_PIN, LOW); 

  duration = pulseIn(SENSOR_ECHO_PIN, HIGH); 
  distance = convertTimeToLength(duration);

  Serial.print(distance); 
  Serial.println(" cm"); 
 
  if (distance > 0 && distance < TRIGGER_DISTANCE) {
    triggerAlarm(LEDS_FROM_RANGE, LEDS_TO_RANGE, BUZZER_PIN);
  }
  delay(5);
}