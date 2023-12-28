#include "sal.h"

#include <helpers.h>

Adafruit_BME280 bme;
uRTCLib rtc(RTC_ADDR);

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
uint8_t second, minute, hour, day, month, year;

float Temp, Pres, Hum, Alt;
int Trys = 0;




void BmeInit()
{
    
}
void BmeRead()
{
 
}
void BmePrint()
{
  #ifdef SERIAL_DEBUG_USB
      PrintChar("Temp: ");
      PrintFloatln(Temp);
      PrintChar("Hum: ");
      PrintFloatln(Hum);
      PrintChar("Pres: ");
      PrintFloatln(Pres);
      PrintChar("Alt: ");
      PrintFloatln(Alt);
  #endif
}
void SdInit()
{
  PrintCharln("Init Sd card");
 
   if(!SD.begin(SD_CS_PIN))
   {
    PrintCharln("Could Not Init Sd Card");
    HLT();
   }
  PrintCharln("Init ok");
  PrintCharln("Checking if file existes");
  if(SD.exists(SD_FILE_NAME)){
    PrintCharln("File Exites returing");
    return; 
  }else {
    PrintCharln("File Dose not exstis");
    File file = SD.open(SD_FILE_NAME, FILE_WRITE);
    if(file.availableForWrite())
    {
      file.println("Temp,Pres,Hum,Alt,Time");
    }
    file.close();
    return;
  };

}
void SdLog(){
  File file = SD.open(SD_FILE_NAME, FILE_WRITE);
  String timeFormat;
  timeFormat = String(year) + "-" + String(month) + "-" + String(day) + " " + String(hour) + "-" + String(minute) + "-" + String(second) + "";
  if(file.availableForWrite())
  {
      file.println(String(Temp) + "," + String(Pres) + "," + String(Hum) + "," + String(Alt)+"," + timeFormat);
  }else {
    PrintCharln("Cant Open File");
    HLT();
  }
  file.close();
}
void InitTime(void)
{
  URTCLIB_WIRE.begin();
  #ifdef RTC_SET_TIME
    rtc.set(0, 9, 12, 5, 28, 12, 23);
    PrintCharln("Set time");
  #endif
}
void ReadTime(void)
{
  rtc.refresh();
  second = rtc.second();
  minute = rtc.minute();
  hour = rtc.hour();
  day = rtc.day();
  month = rtc.month();
  year = rtc.year();
  

}
void PrintTime(void)
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