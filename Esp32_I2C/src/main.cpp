#include <Arduino.h>
#include <Wire.h>

#define ARDUINO_PRO_MINI_ADDRESS 0x3C
#define ARDUINO_ADDRESS 0x08

#define SDA 13
#define SCL 14
int i;

String data;

void setup()
{
  Serial.begin(9600);
  Wire1.begin(SDA, SCL);
  Wire1.setClock(400000L);
}

void loop()
{
  data = "Msg" + String(i++);
  Serial.println("\n\nSend: " + data);
  Wire1.beginTransmission(ARDUINO_ADDRESS);
  Wire1.write(data.c_str());
  Serial.print("Arduino: ");
  Wire1.requestFrom(ARDUINO_ADDRESS, 10);
  while (1)
  {
    int num = Wire1.read();
    if (num > 127 || num < 0)
      break;
    Serial.print((char)num);
  }
  Wire1.endTransmission();
  delay(1000);
}
