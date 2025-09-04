int robotSpeed = 100;

void setup() {
    Serial.begin(9600);
    Serial.println("Speed Control Demo");
    Serial.println("Send a number (0-255) to change speed:");
}

void loop() {
    if (Serial.available() > 0) {
        int newSpeed = Serial.parseInt();
        if (newSpeed >= 0 && newSpeed <= 255) {
            robotSpeed = newSpeed;
            Serial.print("Speed updated to: ");
            Serial.println(robotSpeed);
            if (robotSpeed > 200) {
                Serial.println("TURBO MODE!");
            } else if (robotSpeed > 100) {
                Serial.println("Normal speed");
            } else if (robotSpeed > 0) {
                Serial.println("Slow and steady");
            } else {
                Serial.println("STOPPED");
            }
        } else {
            Serial.println("Invalid speed! Use 0-255");
        }
    }
}
