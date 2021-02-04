#include <Arduino.h>
#include <Wire.h>

String str;

void receiveEvent(int);
void requestEvent();

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Wire.setClock(400000L);
}

void loop()
{
}

void receiveEvent(int howMany)
{
  int i = 0;
  str = "";
  while (Wire.available())
  {
    str += (char)Wire.read();
    i++;
  }

  Serial.println("Esp32: " + str + ", len: " + i  + "\n");
}

void requestEvent()
{
  Wire.write(str.c_str());
}
