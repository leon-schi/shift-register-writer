#include <ShiftRegisterWriter.h>

// binary counter from 0 to 255 (8 bits)

ShiftRegisterWriter writer;
int value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int v = value;
  writer.writeValue(v);
  value++;

  delay(1000);
}