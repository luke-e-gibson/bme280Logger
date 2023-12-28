#include "sal.h"

uRTCLib rtc(RTC_ADDR);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
Adafruit_BME280 bme;
float Temp, Pres, Hum, Alt;
uint8_t second, minute, hour, day, month, year;

int Trys = 0;

void HLT()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  HLT();

}
void InitLed(void){
  pinMode(LED_BUILTIN, OUTPUT);
}
void SerialInit(void)
{
  #ifdef SERIAL_DEBUG
    Serial.begin(9600);
  #endif
}
void PrintFloatln(float toPrint)
{
    #ifdef SERIAL_DEBUG
        Serial.println(toPrint);
    #endif
}
void PrintCharln(const char* toPrint)
{
    #ifdef SERIAL_DEBUG
        Serial.println(toPrint);
    #endif
}
void PrintChar(const char* toPrint)
{
    #ifdef SERIAL_DEBUG
        Serial.print(toPrint);
    #endif
}
void BmeInit()
{
    unsigned status;
    status = bme.begin(BME_ADDR);

    if(!status)
    {
      PrintCharln("Could not find valid BME280 Sensor");
    }
}
void BmeRead()
{
  Temp = bme.readTemperature();
  Pres = bme.readPressure() / 100.0;
  Hum = bme.readHumidity(); 
  Alt = bme.readAltitude(SEALEVELPRESSURE_HPA);
}
void BmePrint()
{
  #ifdef SERIAL_DEBUG
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
  #ifdef SERIAL_DEBUG
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