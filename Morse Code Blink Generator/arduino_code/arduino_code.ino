void setup() {
  pinMode(13, OUTPUT);  // Pin for both dots and dashes (Morse signals)
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);  // Pin for indicating end of Morse code for a character
}

String s = "pallob";
int n = s.length();
int i = 0;
int dotTime = 500, dashTime = 800, setTime = 200;

int morse_code[26][4] = {
  { 0, 1, -1, -1 },   // A (.-)
  { 1, 0, 0, 0 },     // B (-...)
  { 1, 0, 1, 0 },     // C (-.-.)
  { 1, 0, 0, -1 },    // D (-..)
  { 0, -1, -1, -1 },  // E (.)
  { 0, 0, 1, 0 },     // F (..-.)
  { 1, 1, 0, -1 },    // G (--.)
  { 0, 0, 0, 0 },     // H (....)
  { 0, 0, -1, -1 },   // I (..)
  { 0, 1, 1, 1 },     // J (.---)
  { 1, 0, 1, -1 },    // K (-.-)
  { 0, 1, 0, 0 },     // L (.-..)
  { 1, 1, -1, -1 },   // M (--)
  { 1, 0, -1, -1 },   // N (-.)
  { 1, 1, 1, -1 },    // O (---)
  { 0, 1, 1, 0 },     // P (.--.)
  { 1, 1, 0, 1 },     // Q (--.-)
  { 0, 1, 0, -1 },    // R (.-.)
  { 0, 0, 0, -1 },    // S (...)
  { 1, -1, -1, -1 },  // T (-)
  { 0, 0, 1, -1 },    // U (..-)
  { 0, 0, 0, 1 },     // V (...-)
  { 0, 1, 1, -1 },    // W (.--)
  { 1, 0, 0, 1 },     // X (-..-)
  { 1, 0, 1, 1 },     // Y (-.-)
  { 1, 1, 0, 0 }      // Z (--..)
};

void lightStatus(int* seq) {
  for (int x = 0; x < 4; x++) {
    if (seq[x] == -1)
      continue;

    if (seq[x] == 0) {
      // Dot: short blink
      digitalWrite(13, HIGH);
      delay(dotTime);
      digitalWrite(13, LOW);
    } else {
      // Dash: long blink
      digitalWrite(12, HIGH);
      delay(dashTime);
      digitalWrite(12, LOW);
    }

    // Gap between parts of a character (200 ms)
    delay(setTime);
  }
}

void endLight() {
  // Blink to indicate end of character (1 sec pause)
  digitalWrite(11, HIGH);
  delay(1000);  // Long pause between letters
  digitalWrite(11, LOW);
  delay(500);  // Additional pause to indicate new character
}

void loop() {
  if (i >= n) {
    i = 0;  // Reset to the beginning of the string
  }

  // Access the Morse code for the current letter
  char currentChar = s[i];
  if (currentChar >= 'a' && currentChar <= 'z') {
    lightStatus(morse_code[currentChar - 'a']);
    endLight();  // End the Morse sequence for this character
  }

  i++;
}
