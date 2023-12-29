#include "bme280.h"

bme280::bme280(/* args */)
{
    unsigned status;
    status = bme.begin(BME_ADDR);

    if(!status)
    {
      PrintCharln("Could not find valid BME280 Sensor");
      HLT();
    }
}
void bme280::Update()
{
  Temp = bme.readTemperature();
  Pres = bme.readPressure() / 100.0;
  Hum = bme.readHumidity(); 
  Alt = bme.readAltitude(SEALEVELPRESSURE_HPA);
}
float bme280::readDataTemp()
{
  return Temp;
}
float bme280::readDataPres()
{
  return Pres;
};
float bme280::readDataHum()
{
  return Hum;
}
float bme280::readDataAlt()
{
  return Alt;
};

#ifdef SERIAL_DEBUG_USB
    void bme280::DebugPrint()
    {
      PrintChar("Temp: ");
      PrintFloatln(Temp);
      PrintChar("Hum: ");
      PrintFloatln(Hum);
      PrintChar("Pres: ");
      PrintFloatln(Pres);
      PrintChar("Alt: ");
      PrintFloatln(Alt);
    }
#endif


