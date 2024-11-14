#include "MS5637.h"
#include "PCD8544.h"


// Nokia 5772 - PCD8544 driver chip
// 1 - VCC (3v3)
// 2 - GND
// 3 - SCE (CE)
// 4 - RST (RST)
// 5 - D/C (DC)
// 6 - DN<MOSI> (DIN)
// 7 - SCLK (CLK)
// 8 - LED 
#define RST 16
#define CE 4
#define DC 17
#define DIN 5
#define CLK 18

//PCD8544::PCD8544(unsigned short RST, unsigned short CE, unsigned short DC, unsigned short DIN, unsigned short CLK){

// An instance called LCD of the PCD8544 class is created
// The module uses an enhanced bit-bashed 3-Wire SPI communications protcol
// The specified pins are: CLK, MOS, RES, DC, CS.
PCD8544 lcd{RST, CE, DC, DIN, CLK};


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

    lcd.setDisplayMode(VIDEO);

    lcd.print("Hi there bb");
    lcd.print(":D");

    lcd.setCursor(0, 1);
    lcd.print("11111 2 3 ...");

    lcd.setCursor(0, 2);
    lcd.print("0123456789a");

  
    delay(2000);

   
    lcd.setCursor(0, 4);
    lcd.print("abcdefghijklmno123456\n78901");


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
