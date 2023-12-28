#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <settings.h>
#include <helpers.h>
#include <drivers/SerialDriver/SerialDriver.h>

class bme280
{
private:
    float Temp, Pres, Hum, Alt;
    Adafruit_BME280 bme;
public:
    bme280();
    void    Update();
    float   readDataTemp();
    float   readDataPres();
    float   readDataHum();
    float   readDataAlt();
    
    
    #ifdef SERIAL_DEBUG_USB
        void    DebugPrint();
    #endif

};


