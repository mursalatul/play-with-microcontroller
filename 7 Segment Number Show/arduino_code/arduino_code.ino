void setup() {
  // put your setup code here, to run once:
  setupPins();
}

void setupPins() {
  for (int i = 1; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void allLow() {
  for (int i = 1; i < 8; i++) {
    digitalWrite(i, LOW);
  }
}

void showNumber(int num[]) {
  allLow();
  for (int i = 0; i < 7; i++) {
    if (num[i] < 0) continue;
    digitalWrite(num[i], HIGH);
  }
}

int numbers[10][7] = {
  { 1, 2, 3, 4, 5, 6, -7 },      // 0
  { -1, 2, 3, -4, -5, -6, -7 },  // 1
  { 1, 2, -3, 4, 5, -6, 7 },     // 2
  { 1, 2, 3, 4, -5, -6, 7 },     // 3
  { -1, 2, 3, -4, -5, 6, 7 },    // 4
  { 1, -2, 3, 4, -5, 6, 7 },     // 5
  { 1, -2, 3, 4, 5, 6, 7 },      // 6
  { 1, 2, 3, -4, -5, -6, -7 },   // 7
  { 1, 2, 3, 4, 5, 6, 7 },       // 8
  { 1, 2, 3, -4, -5, 6, 7 }      // 9
};

int j = 0;

void loop() {
  if (j > 9)
    j = 0;
  showNumber(numbers[j]);
  delay(500);
  j++;
}
