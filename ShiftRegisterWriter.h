#ifndef ShiftRegisterWriter_h
#define ShiftRegisterWriter_h
#include <Arduino.h>

typedef byte Byte;

class ShiftRegisterWriter {
  private:
    int interval = 1;
    int dataPin, clockPin, confirmPin;
    int bits;
    Byte* binary;

    void setBinary(int value);
    void setBinary(Byte* value);

    void write();
    void clock(int pin);

  public:
    ShiftRegisterWriter(int dataPin=2, int clockPin=8, int confirmPin=9, int bits=8);
    void writeValue(int value);
    void writeBinary(Byte* binary);

    int setBit(int bit, int value);

    int getNumBits();
    int getInterval();
    void setInterval(int value);
};

#endif