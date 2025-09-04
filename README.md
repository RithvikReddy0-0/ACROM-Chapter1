# 🤖 ACROM - Chapter 1: Smart Robot Codes

This repository contains **all Arduino codes** used in the **ACROM Chapter 1: Smart Robot Workshop**.  
Each code corresponds to a specific session activity or the final integrated smart robot project.

---

## 📂 Folder Structure
```
/codes/
├── 01_Blink_LED.ino
├── 02_Button_LED.ino
├── 03_Buzzer.ino
├── 04_RGB_LED.ino
├── 05_IR_Sensor.ino
├── 06_Ultrasonic_Sensor.ino
├── 07_Touch_Sensor.ino
├── 08_Tilt_Sensor.ino
├── 09_Bluetooth_LED.ino
├── 10_Bluetooth_Motor.ino
├── 11_OLED_Display.ino
├── 12_Obstacle_Avoidance.ino
└── 13_Smart_Robot_Final.ino
```
---

## Getting Started

Follow these steps to run the codes:

1. **Install Arduino IDE**  
   Download and install the latest version from the [Arduino Software](https://www.arduino.cc/en/software) page.

2. **Clone this repository**  
   Open your terminal or command prompt and run:

git clone [https://github.com/YOUR-ORG/ACROM-Chapter1.git](https://github.com/RithvikReddy0-0/ACROM-Chapter1)

3. **Open a code file**  
Navigate to the `ACROM-Chapter1/codes/` directory and open any `.ino` file in the Arduino IDE.

4. **Select your board**  
Go to **Tools > Board > Arduino Uno**.

5. **Upload and test**  
- Connect your Arduino Uno to your computer  
- Select the correct **port** under **Tools > Port**  
- Click **Upload** to transfer the code  

---

## Code List and Descriptions

- **01_Blink_LED.ino** → The classic Arduino "Hello World" – blinks an LED.  
- **02_Button_LED.ino** → Turns an LED on/off using a button.  
- **03_Buzzer.ino** → Produces sound with a buzzer.  
- **04_RGB_LED.ino** → Controls the colors of an RGB LED.  
- **05_IR_Sensor.ino** → Detects objects using an IR sensor.  
- **06_Ultrasonic_Sensor.ino** → Measures distance with an HC-SR04 sensor.  
- **07_Touch_Sensor.ino** → Detects human touch input.  
- **08_Tilt_Sensor.ino** → Detects tilt/motion.  
- **09_Bluetooth_LED.ino** → Controls an LED via Bluetooth.  
- **10_Bluetooth_Motor.ino** → Controls motors via Bluetooth.  
- **11_OLED_Display.ino** → Displays text/graphics on OLED.  
- **12_Obstacle_Avoidance.ino** → Simple obstacle avoidance for a robot.  
- **13_Smart_Robot_Final.ino** → The final integrated Smart Robot project.  

---

## 📌 Notes

- All codes are written for the **Arduino Uno** board.  
- For **OLED Display** and **HC-SR04 Ultrasonic Sensor**, ensure you install required libraries:  
Go to **Arduino IDE → Sketch → Include Library → Manage Libraries...**  
- Refer to the **Workshop Manual** for wiring diagrams and hardware setup.  

---

## 🛠Requirements

To follow along, you’ll need:  

- Arduino Uno  
- Breadboard & jumper wires  
- LEDs, buzzer, and sensors (IR, Ultrasonic, Touch, Tilt, etc.)  
- Bluetooth Module (HC-05/06)  
- OLED Display module  
- Arduino IDE (latest version)  

---

## Final Project

The **Smart Robot Final Code (13_Smart_Robot_Final.ino)** integrates:  

- Sensor fusion (IR, Ultrasonic, Touch, Tilt)  
- Obstacle avoidance  
- Bluetooth remote control  
- OLED text display  
- Autonomous smart robot functionality✨  

---

## 🤝 Contributing

Contributions are welcome!  
Feel free to **fork this repository** and open a **pull request** with improvements, bug fixes, or enhancements.

---

