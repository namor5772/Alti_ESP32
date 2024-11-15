#include "Arduino.h"
#include "PCD8544.h"
#include "Font.h"

PCD8544::PCD8544(uint8_t RST, uint8_t CE, uint8_t DC, uint8_t DIN, uint8_t CLK):
  _RST(RST), _CE(CE), _DC(DC), _DIN(DIN), _CLK(CLK) {

    pinMode(RST, OUTPUT);
    pinMode(CE, OUTPUT);
    pinMode(DC, OUTPUT);
    pinMode(DIN, OUTPUT);
    pinMode(CLK, OUTPUT);

    Xcur = 0; Ycur = 0;

    reset();
    clear();
    setDisplayMode(NORMAL);
    setBiasSystem(FORTY);
    setContrast(60);
}

// contrast c should be between 0x00 and 0x7F inclusive (127 decimal) 
void PCD8544::setContrast(uint8_t c){
    digitalWrite(_CE, LOW); // CS (Upper score)
    digitalWrite(_DC, LOW); // select Command Mode - A0 set as LOW
    shiftOut(_DIN, _CLK, MSBFIRST, ADVANCED); // use extended instruction set
    shiftOut(_DIN, _CLK, MSBFIRST, byte(0x80 + c));
    digitalWrite(_CE, HIGH);
}

// Temperature Coefficient value could be one of 0, 1, 2 or 3;
void PCD8544::setTemperatureCoefficient(uint8_t value){
    digitalWrite(_CE, LOW); // CS (Upper score)
    digitalWrite(_DC, LOW); // select Command Mode - A0 set as LOW
    shiftOut(_DIN, _CLK, MSBFIRST, ADVANCED); // use extended instruction set
    shiftOut(_DIN, _CLK, MSBFIRST, byte(0x04 + value));
    digitalWrite(_CE, HIGH);
}

void PCD8544::setCursor(uint8_t x, uint8_t y){
    Xcur = x; Ycur = y;
    digitalWrite(_CE, LOW); // CS (Upper score)
    digitalWrite(_DC, LOW); // select Command Mode - A0 set as LOW
    shiftOut(_DIN, _CLK, MSBFIRST, BASIC); // use basic instruction set
    shiftOut(_DIN, _CLK, MSBFIRST, byte(0x80 + x)); //set x position
    shiftOut(_DIN, _CLK, MSBFIRST, byte(0x40 + y)); //set y position
    digitalWrite(_CE, HIGH);
}

void PCD8544::clear(){
    Xcur = 0; Ycur = 0;
    digitalWrite(_CE, LOW); // CS (Upper score)
    digitalWrite(_DC, LOW); // select Command Mode - A0 set as LOW
    shiftOut(_DIN, _CLK, MSBFIRST, BASIC); // use basic instruction set
    shiftOut(_DIN, _CLK, MSBFIRST, byte(0x80)); //set x position to 0
    shiftOut(_DIN, _CLK, MSBFIRST, byte(0x40)); //set y position to 0
    digitalWrite(_DC, HIGH); // select Data Mode - A0 set to HIGH
    for (int i=0; i<504; i++) shiftOut(_DIN, _CLK, MSBFIRST, 0x00);
    digitalWrite(_CE, HIGH);
    // at this point cursor has cycled back to (0,0)
}

void PCD8544::setDisplayMode(byte value){
    digitalWrite(_CE, LOW); // CS (Upper score)
    digitalWrite(_DC, LOW); // select Command Mode - A0 set as LOW
    shiftOut(_DIN, _CLK, MSBFIRST, BASIC); // use basic instruction set
    shiftOut(_DIN, _CLK, MSBFIRST, value); // set display configuration
    digitalWrite(_CE, HIGH);
}

void PCD8544::setBiasSystem(byte rate){
    digitalWrite(_CE, LOW); // CS (Upper score)
    digitalWrite(_DC, LOW); // select Command Mode - A0 set as LOW
    shiftOut(_DIN, _CLK, MSBFIRST, ADVANCED); // use extended instruction set
    shiftOut(_DIN, _CLK, MSBFIRST, rate); // set bias system
    digitalWrite(_CE, HIGH);
}

size_t PCD8544::write(uint8_t ch) {
  if (ch == 0x0a){ // \n for jumping to the beginning of a new line.
    Xcur = 0; Ycur++; if(Ycur > 5) Ycur = 0;
  }
  else {
    if((8 + Xcur) >= 85) {Xcur = 0; Ycur++; if(Ycur > 5) Ycur = 0;}    
    digitalWrite(_CE, LOW); // CS (Upper score)
    digitalWrite(_DC, LOW); // select Command Mode - A0 set as LOW
    shiftOut(_DIN, _CLK, MSBFIRST, BASIC); // use basic instruction set
    shiftOut(_DIN, _CLK, MSBFIRST, byte(0x80 + Xcur)); //set x position
    shiftOut(_DIN, _CLK, MSBFIRST, byte(0x40 + Ycur)); //set y position
    digitalWrite(_DC, HIGH); // Datamode - A0 set to HIGH
      for (uint8_t i = 0; i < 8; i++) shiftOut(_DIN, _CLK, MSBFIRST, pgm_read_byte(&(Font8x8_[ch][i])));
    digitalWrite(_CE, HIGH);
    Xcur = Xcur + 8; if (Xcur > 83) {Xcur = 0; Ycur++; if(Ycur > 5) Ycur = 0;}
  }
  return 1;
}

void PCD8544::TransferStart(){
    digitalWrite(_CE, LOW); // CS (Upper score)
}

void PCD8544::CommandMode(byte cm){
    digitalWrite(_CE, LOW); // CS (Upper score)
    digitalWrite(_DC, LOW); // select Command Mode - A0 set as LOW
    shiftOut(_DIN, _CLK, MSBFIRST, cm); // select command mode cm
    digitalWrite(_CE, HIGH);
}

void PCD8544::DataMode(){
    digitalWrite(_DC, HIGH); // A0 set to HIGH
}

void PCD8544::WriteByte(byte d){
    digitalWrite(_CE, LOW); // CS (Upper score)
    shiftOut(_DIN, _CLK, MSBFIRST, d);
    digitalWrite(_CE, HIGH);
}

void PCD8544::TransferEnd(){
    digitalWrite(_CE, HIGH);
}

void PCD8544::reset(){
    digitalWrite(_RST, LOW);
    digitalWrite(_RST, HIGH);
}
