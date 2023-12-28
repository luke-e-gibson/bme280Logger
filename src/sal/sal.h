#include <settings.h>


#ifdef SERIAL_DEBUG_BLE
    #include <SoftwareSerial.h>
#endif


void InitLed(void); 
void HLT(void);
void InitTime(void);
void ReadTime(void);
void PrintTime(void);
void BmeInit(void);
void BmeRead(void);
void BmePrint(void);
void SdInit(void);
void SdLog(void);
