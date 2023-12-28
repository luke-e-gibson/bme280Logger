//Debug Settings used of debugging only
//#define SERIAL_DEBUG                              // comment out when putting outside make the firmware a bit smaller


//Log Time
#define MS_IN_MIN 60000                             // constant dont need to change.
#define MS_TILE_NEXT_LOG  MS_IN_MIN * 5             // Used to wait for the next log change the five to how many minutes you want to the next log


//RTC Settings
//#define RTC_SET_TIME                              // Used to run rtc.set() in sal.cpp (Software abstraction layer. used to move all function and include in to there for a clean main.cpp) 
#define RTC_ADDR 0x68                               // Address of the rtc clock


//SD card Settings
#define SD_CS_PIN 10                                // SD card Chip select pin
#define SD_FILE_NAME "data.csv"                     // File that the firmware will write to
#define SD_MAX_TRYS 100                             // Max Times that a an sd card can not open a file

//BME SETTINGS
#define BME_ADDR 0x76                               // Address of the bme sensor 
#define SEALEVELPRESSURE_HPA (1013.25)              // Used for Alt calculation provided by adafruit bme280 example
