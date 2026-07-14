# 🖱️ ESP32 Bluetooth Burst Autoclicker

An ultra-fast physical autoclicker built with an **ESP32-WROOM NodeMCU** and a momentary push button. When you press the physical button once, the ESP32 acts as a wireless Bluetooth (BLE) mouse and sends a rapid burst of $X$ clicks to your computer or mobile device in milliseconds!

This project features a real-time output configuration for the **Arduino IDE Serial Plotter** so you can visually monitor your click bursts (using the `CLIC:1` and `CLIC:0` format).

---

## 🚀 Features
* **Wireless BLE Emulation:** Acts as a standard Bluetooth HID mouse. No extra USB receiver or software needed on the host machine.
* **Burst Click Action:** 1 short physical button press = $X$ high-speed virtual clicks (fully adjustable via `CLICKS_PER_PRESS`).
* **Hardware Debouncing:** Safe state-change detection to prevent accidental double-clicks from button switch bounce.
* **Serial Plotter Support:** Generates clean square wave pulses labeled `CLIC` in the Arduino IDE Serial Plotter for easy debugging.

---

## 🛠️ Hardware Requirements
* **ESP32-WROOM-32 NodeMCU** development board
* **Momentary Push Button** (Tactile switch)
* **Jumper wires** & Breadboard (or soldering iron)
* **Micro-USB cable** (for uploading the code)

---

## 🔌 Wiring Diagram

We use the ESP32's internal `INPUT_PULLUP` resistor, so **no external resistors are required!**

```text
       +-----------------------+
       |   ESP32 NodeMCU       |
       |                       |
       |  [GND]  [D4]          |
       +---|-------|-----------+
           |       |
           |       |
         /=== =======\
        |  [Pin1]   [Pin2] |  <-- Momentary Push Button
         \___________/
