#include "helpers.h"
#include <Arduino.h>
#include <settings.h>

void HLT(void)
{
  blinkLed();
  HLT();
}
void InitLed(void){
  pinMode(LED_BUILTIN, OUTPUT);
}
void blinkLed(int ms = 1000){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(ms);
  digitalWrite(LED_BUILTIN, LOW);
  delay(ms);
}