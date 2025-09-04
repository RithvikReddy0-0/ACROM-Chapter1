const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int DANGER_LED = 8;
const int BUZZER_PIN = 7;

float getUltrasonicDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH, 30000);
    if (duration == 0) return 999;
    return (duration * 0.034) / 2;
}

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(DANGER_LED, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.println("Robot vision system online...");
    Serial.println("Scanning for obstacles...");
}

void loop() {
    float distance = getUltrasonicDistance();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm - ");
    if (distance < 10) {
        Serial.println("DANGER! OBSTACLE VERY CLOSE!");
        digitalWrite(DANGER_LED, HIGH);
        tone(BUZZER_PIN, 2000, 200);
        delay(100);
        digitalWrite(DANGER_LED, LOW);
        delay(100);
    } else if (distance < 25) {
        Serial.println("Caution - Object nearby");
        digitalWrite(DANGER_LED, HIGH);
        tone(BUZZER_PIN, 1000, 100);
        delay(200);
        digitalWrite(DANGER_LED, LOW);
        delay(200);
    } else if (distance < 50) {
        Serial.println("Safe distance");
        digitalWrite(DANGER_LED, LOW);
        noTone(BUZZER_PIN);
    } else {
        Serial.println("All clear - open space");
        digitalWrite(DANGER_LED, LOW);
        noTone(BUZZER_PIN);
    }
    delay(300);
}
