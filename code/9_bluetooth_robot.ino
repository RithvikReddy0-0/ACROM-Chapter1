#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);

// L298N pins
const int MOTOR_A_SPEED = 5;
const int MOTOR_A_DIR1 = 6;
const int MOTOR_A_DIR2 = 7;
const int MOTOR_B_SPEED = 9;
const int MOTOR_B_DIR1 = 10;
const int MOTOR_B_DIR2 = 11;

// Sensors
const int TRIG_PIN = 12;
const int ECHO_PIN = 13;
const int IR_PIN = 4;
const int BUZZER_PIN = 8;

// Control variables
int currentSpeed = 150;
String currentAction = "Stopped";
bool obstacleAvoidance = true;

float getUltrasonicDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH, 30000);
    return duration ? (duration * 0.034) / 2 : 999;
}

bool detectObstacle() {
    float distance = getUltrasonicDistance();
    bool irBlock = !digitalRead(IR_PIN);
    return (distance < 20 || irBlock);
}

void checkObstacles() {
    if (detectObstacle()) {
        stopMotors();
        bluetooth.println("Auto-stop: Obstacle detected!");
        tone(BUZZER_PIN, 2000, 200);
    }
}

void moveForward() {
    currentAction = "Forward";
    analogWrite(MOTOR_A_SPEED, currentSpeed);
    analogWrite(MOTOR_B_SPEED, currentSpeed);
    digitalWrite(MOTOR_A_DIR1, HIGH);
    digitalWrite(MOTOR_A_DIR2, LOW);
    digitalWrite(MOTOR_B_DIR1, HIGH);
    digitalWrite(MOTOR_B_DIR2, LOW);
}

void moveBackward() {
    currentAction = "Backward";
    analogWrite(MOTOR_A_SPEED, currentSpeed);
    analogWrite(MOTOR_B_SPEED, currentSpeed);
    digitalWrite(MOTOR_A_DIR1, LOW);
    digitalWrite(MOTOR_A_DIR2, HIGH);
    digitalWrite(MOTOR_B_DIR1, LOW);
    digitalWrite(MOTOR_B_DIR2, HIGH);
}

void turnLeft() {
    currentAction = "Left Turn";
    analogWrite(MOTOR_A_SPEED, currentSpeed);
    analogWrite(MOTOR_B_SPEED, currentSpeed);
    digitalWrite(MOTOR_A_DIR1, LOW);
    digitalWrite(MOTOR_A_DIR2, HIGH);
    digitalWrite(MOTOR_B_DIR1, HIGH);
    digitalWrite(MOTOR_B_DIR2, LOW);
}

void turnRight() {
    currentAction = "Right Turn";
    analogWrite(MOTOR_A_SPEED, currentSpeed);
    analogWrite(MOTOR_B_SPEED, currentSpeed);
    digitalWrite(MOTOR_A_DIR1, HIGH);
    digitalWrite(MOTOR_A_DIR2, LOW);
    digitalWrite(MOTOR_B_DIR1, LOW);
    digitalWrite(MOTOR_B_DIR2, HIGH);
}

void stopMotors() {
    currentAction = "Stopped";
    analogWrite(MOTOR_A_SPEED, 0);
    analogWrite(MOTOR_B_SPEED, 0);
}

void setSpeed(int newSpeed) {
    if (newSpeed >= 50 && newSpeed <= 255) {
        currentSpeed = newSpeed;
        bluetooth.print("Speed set to: ");
        bluetooth.println(currentSpeed);
        if (currentSpeed < 100) {
            bluetooth.println("Slow mode");
        } else if (currentSpeed < 180) {
            bluetooth.println("Normal speed");
        } else {
            bluetooth.println("High speed");
        }
    } else {
        bluetooth.println("Invalid speed! Use 50-255");
    }
}

void sendStatus() {
    bluetooth.println("=== ROBOT STATUS ===");
    bluetooth.print("Speed: ");
    bluetooth.print(currentSpeed);
    bluetooth.println("/255");
    bluetooth.print("Action: ");
    bluetooth.println(currentAction);
    bluetooth.print("Safety: ");
    bluetooth.println(obstacleAvoidance ? "ON" : "OFF");
    bluetooth.print("Front distance: ");
    bluetooth.print(getUltrasonicDistance());
    bluetooth.println(" cm");
    bluetooth.print("Uptime: ");
    bluetooth.print(millis() / 1000);
    bluetooth.println(" s");
}

void processCommand(String cmd) {
    Serial.print("Received: ");
    Serial.println(cmd);
    if (cmd.length() == 1) {
        char c = cmd.charAt(0);
        switch(c) {
            case 'F': case 'f':
                if (obstacleAvoidance && detectObstacle()) {
                    bluetooth.println("Path blocked! Cannot move forward.");
                    tone(BUZZER_PIN, 1500, 300);
                } else {
                    moveForward();
                    bluetooth.println("Moving Forward");
                }
                break;
            case 'B': case 'b':
                moveBackward();
                bluetooth.println("Moving Backward");
                break;
            case 'L': case 'l':
                turnLeft();
                bluetooth.println("Turning Left");
                break;
            case 'R': case 'r':
                turnRight();
                bluetooth.println("Turning Right");
                break;
            case 'S': case 's':
                stopMotors();
                bluetooth.println("Stopped");
                break;
            case 'A': case 'a':
                obstacleAvoidance = !obstacleAvoidance;
                bluetooth.print("Obstacle avoidance: ");
                bluetooth.println(obstacleAvoidance ? "ON" : "OFF");
                break;
            case '?':
                sendStatus();
                break;
        }
    } else if (cmd.startsWith("V") || cmd.startsWith("v")) {
        int newSpeed = cmd.substring(1).toInt();
        setSpeed(newSpeed);
    }
}

void setup() {
    Serial.begin(9600);
    bluetooth.begin(9600);
    pinMode(MOTOR_A_SPEED, OUTPUT);
    pinMode(MOTOR_A_DIR1, OUTPUT);
    pinMode(MOTOR_A_DIR2, OUTPUT);
    pinMode(MOTOR_B_SPEED, OUTPUT);
    pinMode(MOTOR_B_DIR1, OUTPUT);
    pinMode(MOTOR_B_DIR2, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(IR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    stopMotors();
    tone(BUZZER_PIN, 1000, 200);
    bluetooth.println("Connected to Smart Robot");
    bluetooth.println("Commands: F,B,L,R,S,V###,A,?");
}

void loop() {
    if (bluetooth.available()) {
        String command = bluetooth.readStringUntil('\\n');
        command.trim();
        processCommand(command);
    }
    if (obstacleAvoidance && currentAction == "Forward") {
        checkObstacles();
    }
    delay(50);
}
