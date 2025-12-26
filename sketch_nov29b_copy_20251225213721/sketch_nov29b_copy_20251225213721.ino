#include <deneyap.h>
#include "BluetoothSerial.h"
#include <ESP32Servo.h>

BluetoothSerial SerialBT;

const int sagileri = D15;
const int saggeri  = D14;
const int solileri = D13;
const int solgeri  = D12;

const int tabanPin  = A0;
const int kolPin    = A1;
const int kiskacPin = A2;

Servo taban;
Servo kol;
Servo kiskac;

int deger;

void setup() {
  SerialBT.begin("Girl Power");

  pinMode(sagileri, OUTPUT);
  pinMode(saggeri, OUTPUT);
  pinMode(solileri, OUTPUT);
  pinMode(solgeri, OUTPUT);

  taban.setPeriodHertz(50);
  kol.setPeriodHertz(50);
  kiskac.setPeriodHertz(50);

  taban.attach(tabanPin, 500, 2400);
  kol.attach(kolPin, 500, 2400);
  kiskac.attach(kiskacPin, 500, 2400);

  taban.write(70);
  kol.write(60);
  kiskac.write(90);
}

void loop() {
  if (SerialBT.available()) {
    deger = SerialBT.read();

    if (deger == 'F') {
      digitalWrite(sagileri, HIGH);
      digitalWrite(saggeri, LOW);
      digitalWrite(solileri, HIGH);
      digitalWrite(solgeri, LOW);
    }
    else if (deger == 'B') {
      digitalWrite(sagileri, LOW);
      digitalWrite(saggeri, HIGH);
      digitalWrite(solileri, LOW);
      digitalWrite(solgeri, HIGH);
    }
    else if (deger == 'L') {
      digitalWrite(sagileri, HIGH);
      digitalWrite(saggeri, LOW);
      digitalWrite(solileri, LOW);
      digitalWrite(solgeri, HIGH);
    }
    else if (deger == 'R') {
      digitalWrite(sagileri, LOW);
      digitalWrite(saggeri, HIGH);
      digitalWrite(solileri, HIGH);
      digitalWrite(solgeri, LOW);
    }
    else if (deger == 'S') {
      digitalWrite(sagileri, LOW);
      digitalWrite(saggeri, LOW);
      digitalWrite(solileri, LOW);
      digitalWrite(solgeri, LOW);
    }
    else if (deger == 'T') {
      taban.write(110);
    }
    else if (deger == 'G') {
      taban.write(70);
    }
    else if (deger == 'U') {
      kol.write(120);
    }
    else if (deger == 'D') {
      kol.write(60);
    }
    else if (deger == 'O') {
      kiskac.write(40);
    }
    else if (deger == 'C') {
      kiskac.write(100);
    }
  }
}
