#include "Arduino.h"
#include "PCD8544.h"
#include "xFont.h"

PCD8544::PCD8544(uint8_t RST, uint8_t CE, uint8_t DC, uint8_t DIN, uint8_t CLK):
  _RST(RST), _CE(CE), _DC(DC), _DIN(DIN), _CLK(CLK) {

    pinMode(RST, OUTPUT);
    pinMode(CE, OUTPUT);
    pinMode(DC, OUTPUT);
    pinMode(DIN, OUTPUT);
    pinMode(CLK, OUTPUT);

    _cursor = Cursor();
    _mycursor.y = 0;
    _mycursor.x = 0;

    reset();
    clear();
    setDisplayMode(Display_Mode::NORMAL);
    setBiasSystem(Mux_Rate::FORTY);
    setContrast(60);
}

void PCD8544::TransferStart(){
    digitalWrite(_CE, LOW); // CS (Upper score)
}

void PCD8544::CommandMode(){
    digitalWrite(_DC, LOW); // A0 set as LOW
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

void PCD8544::executeCommand(byte c){
    CommandMode();
    WriteByte(c);
}

// contrast c should be between 0x00 and 0x7F inclusive (127 decimal) 
void PCD8544::setContrast(uint8_t c){
    CommandMode();
    WriteByte(0x21);
    WriteByte(byte(0x80 + c));
}

void PCD8544::extendedInstruction(){
    CommandMode();
    WriteByte(0x21);
}

void PCD8544::basicInstruction(){
    CommandMode();
    WriteByte(0x20);
}

/**
 * Temperature Coefficient value could be one of 0, 1, 2 or 3;
 */
void PCD8544::setTemperatureCoefficient(unsigned short value){
    CommandMode();
    WriteByte(0x21);
    WriteByte(byte(0x04 + value));
}

void PCD8544::makeEnoughSpaceForPrinting(unsigned short int newCharacterLength){
    if((newCharacterLength + _cursor.getPosition().x) < 85)
        return;

    _cursor.moveYAxis(1);
    setCursor(_cursor.getPosition().x, _cursor.getPosition().y);
    DataMode();
}

void PCD8544::setCursor(position x, position y){
    _cursor.setCursor(x, y);
    _mycursor.y = 0;
    _mycursor.x = 0;

    CommandMode();
    WriteByte(0x20);
    WriteByte(byte(0x80 + x)); //set x position
    WriteByte(byte(0x40 + y)); //set y position
}

void PCD8544::clear(){
    DataMode();
    for (int i=0; i<504; i++) WriteByte(0x0);

    _mycursor.y = 0;
    _mycursor.x = 0;
    setCursor(0, 0);
}

void PCD8544::clear(position inRow, position fromColumn, position toColumn){
    // toColumn has to be more than from Column, otherwise flip the values :D
    position temp;
    if(fromColumn > toColumn){
        temp       = fromColumn;
        fromColumn = toColumn;
        toColumn   = temp;
    }

    position counter = fromColumn;
    while(counter <= toColumn){
      setCursor(counter, inRow);
      _mycursor.x = counter;
      _mycursor.y = inRow;

        DataMode();
        WriteByte(0x0);
        counter++;
    }

    setCursor(fromColumn, inRow);
    _mycursor.x = fromColumn;
    _mycursor.y = inRow;
}

void PCD8544::setDisplayMode(display_mode value){
    CommandMode();
    WriteByte(0x20);
    WriteByte(value);
}

void PCD8544::setBiasSystem(mux_rate rate){
    CommandMode();
    WriteByte(0x21);
    WriteByte(rate);
}

size_t PCD8544::write(uint8_t ch) {
    if (ch == 0x0a){ // \n for jumping to the beginning of a new line.
        _cursor.moveYAxis(1);
    }
    else {
      setCursor(_cursor.getPosition().x, _cursor.getPosition().y);
      DataMode();
      character fontData = findCorrespondingByte(ch);
      makeEnoughSpaceForPrinting(fontData.definition_total_bytes);
      for(unsigned int i = 0; i < fontData.definition_total_bytes; i++){
          WriteByte(fontData.definition[i]);
      }
      WriteByte(0x0); // add an empty line after each chars
      _cursor.moveXAxis(fontData.definition_total_bytes + 1);
    }
    return 1;
}

