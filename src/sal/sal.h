#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <uRTCLib.h>
#include <SPI.h>
#include <SD.h>
#include <settings.h>


void InitLed(void); 
void HLT(void);
void SerialInit(void);
void PrintFloatln(float toPrint);
void PrintCharln(const char* toPrint);
void PrintChar(const char* toPrint);
void InitTime(void);
void ReadTime(void);
void PrintTime(void);
void BmeInit(void);
void BmeRead(void);
void BmePrint(void);
void SdInit(void);
void SdLog(void);
