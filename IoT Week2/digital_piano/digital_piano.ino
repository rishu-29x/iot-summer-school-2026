/*
 * ============================================
 * Q15: Digital Piano using Buzzer
 * ============================================
 * Student  : Rishu Jaiswal
 * ============================================
 * Features:
 *   - 4 buttons play Do, Re, Mi, Fa
 *   - Button release silences the buzzer
 *   - Two buttons pressed together play Sol (chord substitute)
 *   - 5th button toggles between Major and Minor scale
 * ============================================
 * Pin Connections:
 *   BTN1 (Do)        -> Pin 2
 *   BTN2 (Re)        -> Pin 3
 *   BTN3 (Mi)        -> Pin 4
 *   BTN4 (Fa)        -> Pin 5
 *   BTN_MODE (Toggle)-> Pin 6
 *   Buzzer (+)       -> Pin 9
 *   Buzzer (-)       -> GND
 * ============================================
 */

const int BTN1 = 2;      // Do
const int BTN2 = 3;      // Re
const int BTN3 = 4;      // Mi
const int BTN4 = 5;      // Fa
const int BTN_MODE = 6;  // Mode toggle
const int BUZZER = 9;

// Major scale frequencies (Hz)
const int majorFreqs[4] = {262, 294, 330, 349};  // Do, Re, Mi, Fa

// Minor scale frequencies (Hz)
const int minorFreqs[4] = {262, 277, 311, 349};  // Do, Re♭, Mi♭, Fa

bool isMajor = true;          // Start in Major mode
bool lastModeState = LOW;     // For mode button debounce

void setup() {
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);
  pinMode(BTN_MODE, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Digital Piano Ready ===");
  Serial.println("Current Mode: Major");
}

void loop() {
  bool b1 = digitalRead(BTN1);
  bool b2 = digitalRead(BTN2);
  bool b3 = digitalRead(BTN3);
  bool b4 = digitalRead(BTN4);
  bool bMode = digitalRead(BTN_MODE);

  // Mode toggle - only triggers once per press
  if (bMode == HIGH && lastModeState == LOW) {
    isMajor = !isMajor;
    Serial.print("Mode switched to: ");
    Serial.println(isMajor ? "Major" : "Minor");
    delay(200);  // debounce
  }
  lastModeState = bMode;

  // Pick frequency array based on current mode
  const int* freqs = isMajor ? majorFreqs : minorFreqs;

  int pressedCount = b1 + b2 + b3 + b4;

  if (pressedCount >= 2) {
    tone(BUZZER, 392);  // Sol - chord substitute
    Serial.println("Chord: Sol (392Hz)");
  }
  else if (b1) {
    tone(BUZZER, freqs[0]);
    Serial.print("Playing Do: "); Serial.println(freqs[0]);
  }
  else if (b2) {
    tone(BUZZER, freqs[1]);
    Serial.print("Playing Re: "); Serial.println(freqs[1]);
  }
  else if (b3) {
    tone(BUZZER, freqs[2]);
    Serial.print("Playing Mi: "); Serial.println(freqs[2]);
  }
  else if (b4) {
    tone(BUZZER, freqs[3]);
    Serial.print("Playing Fa: "); Serial.println(freqs[3]);
  }
  else {
    noTone(BUZZER);  // silence when no button pressed
  }

  delay(10);
}
