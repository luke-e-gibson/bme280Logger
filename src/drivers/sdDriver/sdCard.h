#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <settings.h>
#include "../src/helpers/helpers.h"
#include <drivers/SerialDriver/SerialDriver.h>

class sdCard
{
private:
    int failedTrys = 0;
public:
    sdCard(String csvFormat = "Temp,Pres,Hum,Alt,Time");
    void sdLog(String csvLineToLog);
};

