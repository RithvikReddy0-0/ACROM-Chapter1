const int IR_PIN = 6;
const int BUZZER_PIN = 7;
const int STATUS_LED = 8;

void setup() {
    Serial.begin(9600);
    pinMode(IR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(STATUS_LED, OUTPUT);
    Serial.println("IR Proximity sensor active!");
}

void loop() {
    bool objectDetected = !digitalRead(IR_PIN);
    if (objectDetected) {
        digitalWrite(STATUS_LED, HIGH);
        tone(BUZZER_PIN, 1500, 100);
        Serial.println("IR: Object detected nearby!");
        delay(200);
    } else {
        digitalWrite(STATUS_LED, LOW);
        noTone(BUZZER_PIN);
        Serial.println("IR: Path is clear");
        delay(500);
    }
}
