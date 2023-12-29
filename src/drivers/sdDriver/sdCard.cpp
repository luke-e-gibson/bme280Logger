#include "sdCard.h"

sdCard::sdCard(String csvFormat = "Temp,Pres,Hum,Alt,Time")
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
        file.println(csvFormat);
        }
        file.close();
        return;
  };
}

void sdCard::sdLog(String csvLineToLog){
    File file = SD.open(SD_FILE_NAME, FILE_WRITE);
    String timeFormat;
    if(file.availableForWrite())
    {
        file.println(csvLineToLog);
    }else {
        PrintCharln("Cant Open File");
        HLT();
    }
    file.close();
}
