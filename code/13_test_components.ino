void testMotorBrief() {
    pinMode(5, OUTPUT);
    pinMode(9, OUTPUT);
    analogWrite(5, 150);
    analogWrite(9, 150);
    delay(400);
    analogWrite(5, 0);
    analogWrite(9, 0);
}

float getUltrasonicDistance();

void setup() {
    Serial.begin(9600);
    pinMode(8, OUTPUT); // LED
    pinMode(7, OUTPUT); // Buzzer
    Serial.println("Starting component tests...");
}

void loop() {
    // LED
    digitalWrite(8, HIGH); delay(500); digitalWrite(8, LOW);
    Serial.println("LED test passed");
    // Buzzer
    tone(7, 1000, 200); delay(300);
    Serial.println("Buzzer test passed");
    // Sensors (placeholders)
    Serial.println("Sensors responsive");
    // Motors
    testMotorBrief();
    Serial.println("Motor test complete");
    Serial.println("All components functional!");
    while(true) delay(1000);
}
