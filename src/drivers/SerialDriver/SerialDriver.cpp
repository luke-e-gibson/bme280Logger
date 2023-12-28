#include <Arduino.h>
#include <settings.h>

#include "SerialDriver.h"

void SerialInit(void)
{
  #ifdef SERIAL_DEBUG_USB
    Serial.begin(9600);
  #endif


}
void PrintFloatln(float toPrint)
{
    #ifdef SERIAL_DEBUG_USB
        Serial.println(toPrint);
    #endif

}
void PrintCharln(const char* toPrint)
{
    #ifdef SERIAL_DEBUG_USB
        Serial.println(toPrint);
    #endif

}
void PrintChar(const char* toPrint)
{
    #ifdef SERIAL_DEBUG_USB
        Serial.print(toPrint);
    #endif
}
