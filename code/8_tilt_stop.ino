const int TILT_PIN = 4;
const int EMERGENCY_LED = 8;
const int BUZZER_PIN = 7;

void setup() {
    Serial.begin(9600);
    pinMode(TILT_PIN, INPUT_PULLUP);
    pinMode(EMERGENCY_LED, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.println("Tilt Emergency Stop System Active!");
}

void loop() {
    bool tiltDetected = !digitalRead(TILT_PIN);
    if (tiltDetected) {
        digitalWrite(EMERGENCY_LED, HIGH);
        tone(BUZZER_PIN, 2500, 200);
        Serial.println("EMERGENCY! Robot tilted - STOP ALL MOTORS!");
        delay(100);
        digitalWrite(EMERGENCY_LED, LOW);
        delay(100);
    } else {
        digitalWrite(EMERGENCY_LED, LOW);
        noTone(BUZZER_PIN);
    }
    delay(50);
}
