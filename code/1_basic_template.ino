int robotEnergy = 100;

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    Serial.println("Robot awakening...");
    Serial.println("Systems initialized!");
}

void loop() {
    robotEnergy--;
    Serial.print("Energy level: ");
    Serial.println(robotEnergy);
    if(robotEnergy <= 0) {
        robotEnergy = 100;
        Serial.println("Recharged!");
    }
    delay(1000);
}
