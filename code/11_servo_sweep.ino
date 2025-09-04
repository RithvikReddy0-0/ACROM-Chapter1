#include <Servo.h>
Servo panServo;
const int SERVO_PIN = A0;

float getUltrasonicDistance(); // declare if reused

void setup() {
    Serial.begin(9600);
    panServo.attach(SERVO_PIN);
    panServo.write(90);
    Serial.println("Servo motor ready!");
}

void sweepScan() {
    Serial.println("Performing 180-degree scan...");
    for(int angle = 0; angle <= 180; angle += 30) {
        panServo.write(angle);
        delay(500);
        float distance = 0; // replace with getUltrasonicDistance() if available
        Serial.print("Angle ");
        Serial.print(angle);
        Serial.print(" deg: ");
        Serial.print(distance);
        Serial.println(" cm");
    }
    panServo.write(90);
    Serial.println("Scan complete!");
}

void loop() {
    sweepScan();
    delay(3000);
}
