const int LIMIT_PIN = A1;
const int BUZZER_PIN = 7;

void setup() {
    Serial.begin(9600);
    pinMode(LIMIT_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.println("Limit switch active!");
}

void loop() {
    static bool lastLimitState = true;
    bool currentLimitState = digitalRead(LIMIT_PIN);
    if (!currentLimitState && lastLimitState) {
        tone(BUZZER_PIN, 3000, 500);
        Serial.println("LIMIT SWITCH TRIGGERED - Emergency stop!");
        delay(200);
    }
    lastLimitState = currentLimitState;
    delay(20);
}
