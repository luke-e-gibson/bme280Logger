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
    void sdLog(float Temp, float Pres, float Hum, float Alt, uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);
};

