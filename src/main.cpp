#include <settings.h>
#include "sal/sal.h"


void setup() 
{
  InitLed();
  SerialInit();
  BmeInit();
  InitTime();
  SdInit();
}
void loop() 
{
  BmeRead();
  ReadTime();
  PrintTime();            // only prints in setting SERIAL_DEBUG_USB if true
  BmePrint();             // only prints in setting SERIAL_DEBUG_USB if true
  SdLog();
  delay(MS_TILE_NEXT_LOG);
}

