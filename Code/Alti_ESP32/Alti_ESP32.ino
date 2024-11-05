#include <Nokia_5110.h>

#include "MS5637.h"

// Nokia 5772 - PCD8544 driver chip
// 1 - VCC (3v3)
// 2 - GND
// 3 - SCE (CE)
// 4 - RST
// 5 - D/C (DC)
// 6 - DN<MOSI> (DIN)
// 7 - SCLK (CLK)
// 8 - LED 
#define RST 16
#define CE 4
#define DC 17
#define DIN 5
#define CLK 18

Nokia_5110 lcd = Nokia_5110(RST, CE, DC, DIN, CLK);

// An instance of the MS5637 called BARO is created
// The module is I2C and has just 4 pins:
// 1 GND - connect to ground pin on micro (ESP-WROOM-32here)
// 2 SDA - connect to SDA pin on micro (also called G21)
// 3 SCL - connect to SCL pin on micro (also called G22)
// 4 VCC - connect to 3V3 pin on micro
MS5637 BARO;



// global variables
uint32_t chipId = 0;
float temp, pressure, altBase, altRel;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 17; i = i + 8) {
    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }
  Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("This chip has %d cores\n", ESP.getChipCores());
  Serial.print("Chip ID: ");
  Serial.print(chipId);
  Serial.println("\n");

 /**
     * Note: if instead of text being shown on the display, all the segments are on, you may need to decrease contrast value.
     */
    //lcd.setContrast(60); // 60 is the default value set by the driver
    
    lcd.print("Please Wait ...");
    delay(1000);
    lcd.clear();

    lcd.print("Hi there");
    lcd.println(":D");

    lcd.setCursor(0, 5);
    lcd.println("1 2 3 ...");

  // setup MS5637 sensor (An instance of the MS5637 object BARO has been constructed above)
  BARO.begin();
  BARO.dumpDebugOutput();
  BARO.getTempAndPressure(&temp, &pressure);
  altBase = BARO.pressure2altitude(pressure);
  //altBase = 0.0;
  Serial.println(altBase);  
}


void loop() {
  for (int i = 0; i < 17; i = i + 8) {
    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }

  Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("This chip has %d cores\n", ESP.getChipCores());
  Serial.print("Chip ID: ");
  Serial.print(chipId);
  Serial.println("\n");

  if (!BARO.isOK()) {
    // Try to reinitialise the sensor if we can and measure temperature and pressure
    BARO.begin();
    BARO.getTempAndPressure(&temp, &pressure);
  }
  else { // just normal measurements on each loop
    BARO.getTempAndPressure(&temp, &pressure);
  }

  // Calculate altitude relative to where the altimeter was turned on
  altRel = BARO.pressure2altitude(pressure) - altBase;

  Serial.print(temp);
  Serial.print(" ");
  Serial.println(altRel);

  delay(500);
}
