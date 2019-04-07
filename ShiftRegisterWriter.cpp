#include "ShiftRegisterWriter.h"

ShiftRegisterWriter::ShiftRegisterWriter(int dataPin, int clockPin, int confirmPin, int bits) {
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(confirmPin, OUTPUT);

    this->dataPin = dataPin;
    this->clockPin = clockPin;
    this->confirmPin = confirmPin;
    this->bits = bits;

    this->binary = (Byte*)malloc(bits * sizeof(Byte));
    setBinary(0);
}

void ShiftRegisterWriter::writeValue(int value) {
    setBinary(value);
    write();
}

void ShiftRegisterWriter::writeBinary(Byte* binary) {
    setBinary(binary);
    write();
}

int ShiftRegisterWriter::setBit(int bit, int value) {
    if (bit >= bits || bit < 0) return -1;
    binary[bit] = (value > 0) ? 1 : 0;
    write();
    return 0;
}

int ShiftRegisterWriter::getNumBits() {
    return bits;
}

int ShiftRegisterWriter::getInterval() {
    return interval;
}

void ShiftRegisterWriter::setInterval(int value) {
    interval = value;
}

// private methods

void ShiftRegisterWriter::clock(int pin) {
    delay(interval);
    digitalWrite(pin, HIGH);
    delay(interval);
    digitalWrite(pin, LOW);
}

void ShiftRegisterWriter::setBinary(int value) {
    for (int i = 0; i < bits; i++) {
        binary[i] = value % 2;
        value = value / 2;
    }
}

void ShiftRegisterWriter::setBinary(Byte* value) {
    binary = value;
}

void ShiftRegisterWriter::write() {
    for (int i = 0; i < bits; i++) {
        digitalWrite(dataPin, (binary[i] > 0) ? HIGH : LOW);
        clock(clockPin);
    }
    clock(confirmPin);
}