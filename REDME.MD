# Voice-Controlled Wireless Notice Board

This project allows text messages to be displayed on a P10 LED display using **voice commands**. An Android phone converts speech to text and sends the message to an **Arduino Uno** through a **Bluetooth (HC-05)** module. The message is then shown on both a **20x4 LCD** for preview and the **P10 LED display** for public viewing.

---

## Features
- Update notices using voice commands
- Wireless data transfer via Bluetooth
- Real-time scrolling display on P10 LED module
- Local preview on LCD display
- Low power consumption and low maintenance

---

## Components Used

| Component | Description |
|----------|-------------|
| Arduino Uno | Main microcontroller to process data |
| HC-05 Bluetooth Module | Receives message wirelessly from phone |
| P10 LED Display | Main notice board display |
| 20x4 I2C LCD | Message preview on board |
| Jumper Wires | Connections |
| 5V DC Adapter (2A) | Power supply for P10 display |
| USB Cable | Upload code to Arduino |

---

## Circuit Connections

### HC-05 → Arduino
| HC-05 | Arduino |
|------|---------|
| VCC | 5V |
| GND | GND |
| TX | D2 |
| RX | D3 |

### P10 Display (DMD Library Default Pins)
| P10 Pin | Arduino Pin |
|--------|-------------|
| CLK | D13 |
| OE | D9 |
| STB | D8 |
| A | D6 |
| B | D7 |
| R | D11 |
| GND + 5V | External 5V supply |

**Note:** The P10 display must be powered with a **separate 5V 2A adapter** (not from Arduino).

---

## Software Requirements
- Arduino IDE
- MIT App Inventor (for Android app)

### Arduino Libraries to Install:


Install using:  
**Arduino IDE → Sketch → Include Library → Manage Libraries**

---

## Working Principle
1. User speaks into the mobile app.
2. The app converts speech to text.
3. Text is sent over Bluetooth to Arduino.
4. Arduino updates:
   - **LCD** (preview)
   - **P10 LED display** (scrolling message)

---

## Android App (MIT App Inventor)
- Performs **Speech to Text**
- Sends message via **Bluetooth**
- Simple one-button send interface

If you need the **.aia App project**, ask: **"Send App File"**

---

## Applications
- Schools and colleges
- Hospitals
- Government offices
- Public announcements
- Events and conferences
- Smart information display boards

---

## Advantages
- No manual printing or updates
- Real-time communication
- Easy to use
- Cost-effective and scalable

---

## Limitations
- Accuracy depends on speech recognition
- Requires stable power for P10 display
- Bluetooth range limited (~10 meters)

---

## Future Enhancements
- Wi-Fi / Cloud based control
- Multi-language voice support
- Web dashboard for remote updates

---

## Author
Project: **Voice-Controlled Wireless Notice Board**  
Platform: **Arduino + Android (MIT App Inventor)**

