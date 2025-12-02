                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // AutomaticStreetLight.ino
// Arduino UNO - LDR automatic street light with hysteresis and averaging
// Pinout:
//   A0 -> LDR-VoltageDivider midpoint
//   D8 -> Lamp control (transistor base or relay input)

const int LDR_PIN = A0;
const int LAMP_PIN = 8;

const int NUM_SAMPLES = 8;    // for smoothing
const int DARK_THRESHOLD = 300; // tuning value (0..1023). Lower = darker required
const int HYSTERESIS = 40;    // prevents rapid on/off around threshold

int lastState = LOW; // LOW means lamp OFF, HIGH means ON

void setup() {
  pinMode(LAMP_PIN, OUTPUT);
  digitalWrite(LAMP_PIN, LOW); // lamp off  
  Serial.begin(9600);
}

int readLDRAverage() {
  long sum = 0;
  for (int i = 0; i < NUM_SAMPLES; ++i) {
    sum += analogRead(LDR_PIN);
    delay(10);
  }
  return (int)(sum / NUM_SAMPLES);
}

void loop() {
  int ldrValue = readLDRAverage();
  Serial.print("LDR: ");
  Serial.println(ldrValue);

  if (lastState == LOW) {
    // Currently OFF: turn ON if really dark
    if (ldrValue < DARK_THRESHOLD) {
      digitalWrite(LAMP_PIN, HIGH);
      lastState = HIGH;
      Serial.println("Lamp: ON");
    }
  } else {
    // Currently ON: turn OFF only when sufficiently bright (threshold + hysteresis)
    if (ldrValue > (DARK_THRESHOLD + HYSTERESIS)) {
      digitalWrite(LAMP_PIN, LOW);
      lastState = LOW;
      Serial.println("Lamp: OFF");
    }
  }

  delay(300); // adjust responsiveness
}


