const char keyUp = 'U';
const char keyDown = 'D';
const char keyRight = 'R';
const char keyLeft = 'L';
const char keyNone = 'N';

const byte rowAmount = 4;
const byte colAmount = 4;

char keyMatrix[rowAmount][colAmount] = {
  {keyNone, keyUp,    keyNone,  keyNone},
  {keyLeft, keyNone,  keyRight, keyNone},
  {keyNone, keyDown,  keyNone,  keyNone},
  {keyNone, keyNone,  keyNone,  keyNone}
};

static bool keyDownMatrix[rowAmount][colAmount];

byte rowPins[rowAmount] = { 5, 4, 3, 2 };
byte colPins[colAmount] = { 6, 7, 8, 9 };

void setup()
{
  for (int i = 0; i < rowAmount; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }

  for (int i = 0; i < colAmount; i++) {
    pinMode(colPins[i], INPUT);
    digitalWrite(colPins[i], HIGH);
  }
  Serial1.begin(115200);
}

void loop()
{
  char key = getKey();
  if (key != keyNone) {
    Serial1.write(key);
  }
}

char getKey()
{
  char result = keyNone;
  for (int i = 0; i < rowAmount; i++) {
    for (int j = 0; j < colAmount; j++) {
      bool isDown = isKeyDown(i, j);
      if (!keyDownMatrix[i][j] && isDown) {
        result = keyMatrix[i][j];
      }
      keyDownMatrix[i][j] = isDown;
    } 
  }
  return result;
}

bool isKeyDown(int i, int j)
{
  bool result = false;
  digitalWrite(rowPins[i], LOW);
  if (digitalRead(colPins[j]) == LOW) {
    result = true;
  }
  digitalWrite(rowPins[i], HIGH);
  return result;
}
