#ifndef PCD8544_H
#define PCD8544_H
#include "Arduino.h"

// Display Mode constants
#define BLANK 0x8
#define NORMAL 0xc
#define ALL_SEGMENTS_ON 0x9
#define VIDEO 0xd

// Bias System constants
#define HUNDRED 0x10
#define EIGHTY 0x11
#define SIXTY_FIVE 0x12
#define FORTY_EIGHT 0x13
#define FORTY 0x14
#define TWENTY_FOUR 0x15
#define EIGHTEEN 0x16
#define TEN 0x17

// Command type constants 
#define BASIC 0x20
#define ADVANCED 0x21


class PCD8544 : public Print {

  public:
    PCD8544(uint8_t RST, uint8_t CE, uint8_t DC, uint8_t DIN, uint8_t CLK);

    void setContrast(uint8_t c);
    void setTemperatureCoefficient(uint8_t value);
    void clear();
    void clear(uint8_t inRow, uint8_t fromColumn, uint8_t toColumn);
    void setCursor(uint8_t x, uint8_t y);
    void setDisplayMode(byte mode);
    void setBiasSystem(byte rate);

    virtual size_t write(uint8_t ch); // Overriding Print's write method
    
  private:

    // low level SPI comms with PC8544
    void TransferStart();
    void CommandMode(byte cm);
    void DataMode();
    void WriteByte(byte d);
    void TransferEnd();

    // setup functions    
    void reset();

    // data variables
    uint8_t _RST, _CE, _DC, _DIN, _CLK;
    uint8_t Xcur, Ycur;
};

#endif

