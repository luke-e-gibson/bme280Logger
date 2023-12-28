#include <Arduino.h>
#include <drivers/bme280Driver/bme280.h>
#include <drivers/sdDriver/sdCard.h>
#include <drivers/timeDriver/time.h>

bme280 bme;
sdCard sd;
Time time;


void setup() 
{
  
}


void loop() 
{
 bme.Update();
 time.Update();

  sd.sdLog(bme.readDataTemp(), bme.readDataPres(), bme.readDataHum(),
      bme.readDataAlt(), time.getYear(), time.getMonth(), time.getDay(), time.getHours(), time.getMinutes(), time.getSeconds());


 #ifdef SERIAL_DEBUG_USB
  bme.DebugPrint();
  time.DebugPrint();
 #endif
}

