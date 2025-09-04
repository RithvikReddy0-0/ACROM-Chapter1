void setup() {
    Serial.begin(9600);
    Serial.println("Hi! I'm your Arduino robot!");
    Serial.println("Type something and I'll echo it back:");
}

void loop() {
    if (Serial.available() > 0) {
        String message = Serial.readString();
        message.trim();
        Serial.print("You said: '");
        Serial.print(message);
        Serial.println("' - Got it!");
        if (message == "hello") {
            Serial.println("Hello there!");
        } else if (message == "dance") {
            Serial.println("*robot dancing intensifies*");
        }
    }
}
