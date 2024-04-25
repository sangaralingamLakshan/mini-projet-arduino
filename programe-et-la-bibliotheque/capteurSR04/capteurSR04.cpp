#include <Arduino.h>
#include "capteurSR04.hpp"
int init2(int TRIGGER_PIN, int ECHO_PIN){
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); 
  pinMode(ECHO_PIN, INPUT);
}
int declencheImpulsion (int TRIGGER_PIN){
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}
int mesureTemps (int ECHO_PIN){
  const unsigned long MEASURE_TIMEOUT = 25000UL;
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
  return measure;
}
int calculDist (long measure){
  const float SOUND_SPEED = 340.0 / 1000;
  float distance_mm = measure / 2.0 * SOUND_SPEED;
  return  distance_mm;
}
void afficher (int distance_mm) {
  Serial.print(F("Distance: "));
  Serial.print(distance_mm);
  Serial.print(F("mm ("));
  Serial.print(distance_mm / 10.0, 2);
  Serial.print(F("cm, "));
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println(F("m)"));
   
}
