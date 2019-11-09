#include <Wire.h>

const char keyNone = 'N';
char lastKey = keyNone;

const int keypadAdderss = 10;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
}

void loop()
{
  Wire.requestFrom(keypadAdderss, 1);
  while (Wire.available()) {
    char key = Wire.read();
    if (key != keyNone && key != lastKey) {
      Serial.println(key);
    }
    lastKey = key;
  }
}
