#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void updateDisplay(String status, float distance, int speed) {
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("=== SMART ROBOT ===");
    display.print("Status: ");
    display.println(status);
    display.print("Distance: ");
    display.print(distance);
    display.println(" cm");
    display.print("Speed: ");
    display.print(speed);
    display.println("/255");
    display.print("Battery: ");
    display.println("3.7V OK");
    display.display();
}

void setup() {
    Serial.begin(9600);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("OLED display failed!");
        return;
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Smart Robot v1.0");
    display.println("Status: Ready");
    display.println("Battery: 3.7V");
    display.display();
    Serial.println("OLED Display Ready!");
}

void loop() {
    updateDisplay("Idle", 42.0, 150);
    delay(1000);
}
