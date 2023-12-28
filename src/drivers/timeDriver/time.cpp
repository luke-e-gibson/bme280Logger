#include "time.h"

Time::Time(/* args */)
{   
    rtc = uRTCLib(RTC_ADDR);
    URTCLIB_WIRE.begin();
    #ifdef RTC_SET_TIME
        rtc.set(0, 9, 12, 5, 28, 12, 23);
        PrintCharln("Set time");
    #endif
}

void Time::Update()
{
    rtc.refresh();
    second = rtc.second();
    minute = rtc.minute();
    hour = rtc.hour();
    day = rtc.day();
    month = rtc.month();
    year = rtc.year();
}

uint8_t Time::getSeconds()
{
    return second;
};
uint8_t Time::getMinutes()
{
    return minute;
};
uint8_t Time::getHours()
{
    return hour;
};
uint8_t Time::getDay()
{
    return day;
};
uint8_t Time::getMonth()
{
    return month;
};
uint8_t Time::getYear()
{
    return year;
};

#ifdef SERIAL_DEBUG_USB
    void Time::DebugPrint()
    {
          #ifdef SERIAL_DEBUG_USB
                Serial.print("Current Date & Time: ");
                Serial.print(rtc.year());
                Serial.print('/');
                Serial.print(rtc.month());
                Serial.print('/');
                Serial.print(rtc.day());

                Serial.print(rtc.hour());
                Serial.print(':');
                Serial.print(rtc.minute());
                Serial.print(':');
                Serial.println(rtc.second());
  #endif
    }
#endif