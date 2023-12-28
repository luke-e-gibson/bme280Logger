# Simple bme280 logger
An arduino nano based bme280 logger logs all data to an sd card with time form a DS1307 module in csv format.

Parts:
- Arduino nano or other arduino compatable board
- bme280 module
- DS1307 RTC clock
- SD card module

<details>
<summary>Pins</summary>

- BME280
    - VCC 5V
    - GND GND
    - SDA A4
    - SCL A5
- DS1307
    - VCC 5V
    - GND GND
    - SDA A4
    - SCL A5
- SD card module
    - VCC 5V
    - GND GND
    - CS D10
    - SCK D3
    - MOSI D11
    - MOSO D12
</details>

to flash firmware you can clone this repo with git ```git clone https://github.com/luke-e-gibson/bme280Logger``` and build with platfrom IO or flash the precompiled firmware under realses with the arduino IDE.
