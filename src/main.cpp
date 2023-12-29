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
 

    sd.sdLog(bme.readDataTemp(), bme.readDataPres(), bme.readDataHum(),
        bme.readDataAlt(), time.getYear(), time.getMonth(), time.getDay(), time.getHours(), time.getMinutes(), time.getSeconds());


    #ifdef SERIAL_DEBUG_USB
      bme.DebugPrint();
      time.DebugPrint();
    #endif
  }    
    
}


void loop() 
{
  setup(); // if main loop in setup escapes
}

