#ifndef PCD8544_H
#define PCD8544_H

#include "Arduino.h"
#include "xDisplay_Mode.h"
#include "xMux_Rate.h"
#include "xCursor.h"

typedef unsigned short int position;

struct MyCursor {
    position x;
    position y;
};

class PCD8544 : public Print {

  public:
    PCD8544(uint8_t RST, uint8_t CE, uint8_t DC, uint8_t DIN, uint8_t CLK);

    void setContrast(uint8_t c);

    void setTemperatureCoefficient(unsigned short value);
    void clear();
    void clear(position inRow, position fromColumn, position toColumn);
    void setCursor(position x, position y);
    void setDisplayMode(display_mode mode);
    void setBiasSystem(mux_rate rate);

    virtual size_t write(uint8_t ch); // Overriding Print's write method
    
  private:

    // low level SPI comms with PC8544
    void TransferStart();
    void CommandMode();
    void DataMode();
    void WriteByte(byte d);
    void TransferEnd();

    // setup functions    
    void reset();
    
    void executeCommand(byte c);

    void extendedInstruction();
    void basicInstruction();
    void makeEnoughSpaceForPrinting(unsigned short int newCharacterLength);

    uint8_t _RST, _CE, _DC, _DIN, _CLK;
    MyCursor _mycursor;
    Cursor _cursor;
};

#endif

