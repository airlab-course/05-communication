void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop()
{
  if (Serial1.available()) {
    char key = Serial1.read();
    Serial.println(key);
  }
}
