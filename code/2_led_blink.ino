const int HEART_LED = 13;

void setup() {
    pinMode(HEART_LED, OUTPUT);
    Serial.begin(9600);
    Serial.println("Robot heart starting...");
}

void loop() {
    digitalWrite(HEART_LED, HIGH);
    Serial.println("THUMP");
    delay(500);
    digitalWrite(HEART_LED, LOW);
    Serial.println("thump");
    delay(500);
}
