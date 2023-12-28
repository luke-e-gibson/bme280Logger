#include "sdCard.h"

sdCard::sdCard()
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

void sdCard::sdLog(float Temp, float Pres, float Hum, float Alt, uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second){
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
