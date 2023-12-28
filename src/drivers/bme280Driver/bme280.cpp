#include "bme280.h"

bme280::bme280(/* args */)
{
    unsigned status;
    status = bme.begin(BME_ADDR);

    if(!status)
    {
      PrintCharln("Could not find valid BME280 Sensor");
    }
}
void bme280::Update()
{
  Temp = bme.readTemperature();
  Pres = bme.readPressure() / 100.0;
  Hum = bme.readHumidity(); 
  Alt = bme.readAltitude(SEALEVELPRESSURE_HPA);
}