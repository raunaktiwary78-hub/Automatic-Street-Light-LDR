# Automatic-Street-Light-LDR
<h1 align="center">Automatic Street Light using LDR (Arduino)</h1>
<p align="center">Arduino-based automatic street light system that turns ON a lamp when it gets dark using an LDR sensor. Simple, reliable, great for embedded & IoT portfolio.</p>

---

## 📌 Project Summary
- **Hardware:** Arduino UNO (or any compatible board), LDR (photoresistor), 10kΩ resistor, NPN transistor (e.g., 2N2222) or relay module, LED / lamp, jumpers, breadboard.
- **Category:** Embedded Systems / Sensors / Arduino
- **Skill highlights:** Analog sensing, GPIO control, hysteresis (debounce flicker), simple power switching.

---

## 🧰 Components / Bill of Materials
- Arduino UNO (or Nano/Pro Micro) — 1  
- LDR (Photoresistor) — 1  
- 10 kΩ resistor — 1 (pull-down)  
- 2N2222 NPN transistor (or a relay module if switching AC lamp) — 1  
- 1 kΩ resistor (base resistor for NPN) — 1  
- LED (or 12V lamp with proper driver/relay) — 1  
- Breadboard & jumper wires — as needed  
- External power supply if lamp requires >5V

---

## 🔌 Wiring / Circuit (simple & safe for LED demo)
**Use LED demo if you don't have relay / mains wiring.**  
Connections (Arduino pins → component):

- `A0` → LDR voltage divider middle node  
- `5V` → LDR end1  
- `GND` → LDR end2 and Arduino GND  
- `D8` → transistor base (via 1kΩ) or to relay IN pin  
- Transistor emitter → GND  
- Transistor collector → negative of LED (positive of LED → 5V via suitable resistor)  
- If using relay module, connect `VCC` to 5V, `GND` to GND, `IN` to D8

**Voltage divider for LDR:**  
- LDR between `5V` and `A0`  
- 10kΩ resistor between `A0` and `GND`  
(This gives analog reading on `A0`)

---

## 🧾 Code
See `code/AutomaticStreetLight.ino`.

Behavior summary:
- Reads analog value from LDR (A0).
- When ambient light < threshold, turn lamp ON.
- When ambient light > threshold + hysteresis, turn lamp OFF.
- Built-in small delay and averaging to avoid flicker.

---

## ✅ How to test
1. Upload `AutomaticStreetLight.ino` to your Arduino.  
2. Open Serial Monitor (9600 baud) to see sensor values.  
3. Cover LDR with your hand → lamp should turn ON.  
4. Expose LDR to light → lamp should turn OFF.

---

## 🔧 Future improvements
- Add a real-time clock (RTC) to combine darkness + time-of-day logic.  
- Use Wi-Fi (ESP8266/ESP32) to send logs to a dashboard.  
- Add automatic dimming (PWM) instead of binary ON/OFF.  
- Add relay isolation for real mains lamp control with safety precautions.

---

## 📸 Images / Demo

- `photo_setup.jpg` — breadboard + Arduino wiring
- `photo_day_off.jpg` — lamp OFF during day
- `photo_night_on.jpg` — lamp ON during dark



---

## 📄 License
This project is licensed under the MIT License. See `LICENSE`.

---

## 📫 Contact
  
GitHub: https://github.com/raunaktiwary78-hub

