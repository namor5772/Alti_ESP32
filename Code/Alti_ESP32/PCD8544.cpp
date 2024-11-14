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

void PCD8544::TransferStart(){
    digitalWrite(_CE, LOW); // CS (Upper score)
}

void PCD8544::CommandMode(byte cm){
    digitalWrite(_DC, LOW); // A0 set as LOW
    WriteByte(cm);
}

void PCD8544::DataMode(){
    digitalWrite(_DC, HIGH); // A0 set to HIGH
}

void PCD8544::WriteByte(byte d){
    TransferStart();
    shiftOut(_DIN, _CLK, MSBFIRST, d);
    TransferEnd();
}

void PCD8544::TransferEnd(){
    digitalWrite(_CE, HIGH);
}

void PCD8544::reset(){
    digitalWrite(_RST, LOW);
    digitalWrite(_RST, HIGH);
}

// contrast c should be between 0x00 and 0x7F inclusive (127 decimal) 
void PCD8544::setContrast(uint8_t c){
    CommandMode(ADVANCED);
    WriteByte(byte(0x80 + c));
}

// Temperature Coefficient value could be one of 0, 1, 2 or 3;
void PCD8544::setTemperatureCoefficient(uint8_t value){
    CommandMode(ADVANCED);
    WriteByte(byte(0x04 + value));
}

void PCD8544::setCursor(uint8_t x, uint8_t y){
    Xcur = x; Ycur = y;
    CommandMode(BASIC);
    WriteByte(byte(0x80 + x)); //set x position
    WriteByte(byte(0x40 + y)); //set y position
}

void PCD8544::clear(){
    DataMode();
    for (int i=0; i<504; i++) WriteByte(0x0);
    setCursor(0, 0);
}

void PCD8544::clear(uint8_t inRow, uint8_t fromColumn, uint8_t toColumn){
    // toColumn has to be more than from Column, otherwise flip the values :D
    uint8_t temp;
    if(fromColumn > toColumn){
        temp       = fromColumn;
        fromColumn = toColumn;
        toColumn   = temp;
    }
    uint8_t counter = fromColumn;
    while(counter <= toColumn){
      setCursor(counter, inRow);
      DataMode();
      WriteByte(0x00);
      counter++;
    }
    setCursor(fromColumn, inRow);
}

void PCD8544::setDisplayMode(byte value){
    CommandMode(BASIC);
    WriteByte(value);
}

void PCD8544::setBiasSystem(byte rate){
    CommandMode(ADVANCED);
    WriteByte(rate);
}

size_t PCD8544::write(uint8_t ch) {
  if (ch == 0x0a){ // \n for jumping to the beginning of a new line.
    Xcur = 0; Ycur++; if(Ycur > 5) Ycur = 0;
  }
  else {
    if((8 + Xcur) >= 85) {Xcur = 0; Ycur++; if(Ycur > 5) Ycur = 0;}    
    setCursor(Xcur, Ycur);
    DataMode();
    for (uint8_t i = 0; i < 8; i++) {
      WriteByte(pgm_read_byte(&(Font8x8_[ch][i])));
    }
    Xcur = Xcur + 8;
    if (Xcur > 83) {Xcur = 0; Ycur++; if(Ycur > 5) Ycur = 0;}
  }
  return 1;
}
