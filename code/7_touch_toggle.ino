const int TOUCH_PIN = 5;
const int LED_PIN = 8;
const int BUZZER_PIN = 7;

bool systemActive = false;

void setup() {
    Serial.begin(9600);
    pinMode(TOUCH_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.println("Touch Control System Ready!");
    Serial.println("Touch sensor to toggle robot state");
}

void loop() {
    static bool lastTouchState = false;
    bool currentTouchState = digitalRead(TOUCH_PIN);
    if (currentTouchState && !lastTouchState) {
        systemActive = !systemActive;
        if (systemActive) {
            digitalWrite(LED_PIN, HIGH);
            tone(BUZZER_PIN, 1000, 200);
            Serial.println("System ACTIVATED!");
        } else {
            digitalWrite(LED_PIN, LOW);
            tone(BUZZER_PIN, 500, 200);
            Serial.println("System DEACTIVATED!");
        }
        delay(200);
    }
    lastTouchState = currentTouchState;
    delay(50);
}
