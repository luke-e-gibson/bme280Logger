#include <Arduino.h>
#include <uRTCLib.h>
#include <settings.h>
#include "../src/helpers/helpers.h"

class Time
{
private:
    uRTCLib rtc;
    uint8_t second, minute, hour, day, month, year;

public:
    Time();
    void Update();
    uint8_t getSeconds();
    uint8_t getMinutes();
    uint8_t getHours();
    uint8_t getDay();
    uint8_t getMonth();
    uint8_t getYear();

    #ifdef SERIAL_DEBUG_USB
        void DebugPrint();
    #endif
};

