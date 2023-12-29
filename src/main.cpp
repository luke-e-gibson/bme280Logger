#include <Arduino.h>
#include <drivers/bme280Driver/bme280.h>
#include <drivers/sdDriver/sdCard.h>
#include <drivers/timeDriver/time.h>
#include <drivers/SerialDriver/SerialDriver.h>

void setup() 
{
  SerialInit();
  bme280 bme;
  sdCard sd;
  Time time;
  
  //Hack (This is the way it is because my driver class halts if there is a problem even before serial initalized so we initalize the classes in setup scoop then run the loop in setup if the while stops it is sent back to setup from the loop)
  while(1){
    bme.Update();
    time.Update();

    String timeFormat = String(time.getYear()) + "-" + String(time.getMonth()) + "-" + String(time.getDay()) + " " + String(time.getHours()) + "-" + String(time.getMinutes()) + "-" + String(time.getSeconds()) + "";
    String weatherFromat = String(bme.readDataTemp()) + ","+ String(bme.readDataPres()) + "," + String(bme.readDataHum()) + "," + String(bme.readDataAlt()); 
    String toLog = weatherFromat + "," + timeFormat;
    Serial.println(toLog);
    sd.sdLog(toLog);


    #ifdef SERIAL_DEBUG_USB
      bme.DebugPrint();
      time.DebugPrint();
    #endif
    delay(MS_TILE_NEXT_LOG);
  }    
    
}


void loop() 
{
  setup(); // if main loop in setup escapes
}

