# SmokeGuard — Arduino Smoke & Gas Detector

> A simple yet effective smoke and gas detection system simulated using Arduino Uno on Wokwi.

---

## Project Overview

SmokeGuard is an Arduino-based smoke and gas detector that continuously monitors air quality using an analog sensor. When smoke or gas levels exceed a safe threshold, it immediately triggers a buzzer alarm and lights up a red LED to alert the user.

This project is simulated in [Wokwi](https://wokwi.com) using a potentiometer to replicate the analog output of an MQ2 gas sensor.

---

## Components Used

| Component | Purpose |
|---|---|
| Arduino Uno | Microcontroller / Brain |
| Potentiometer | Simulates MQ2 Gas Sensor analog output |
| Red LED | Visual smoke alert |
| 220 Ohm Resistor | Current limiter for LED |
| Piezo Buzzer | Audio smoke alarm |

---

## Circuit Connections

| Component Pin | Arduino Pin |
|---|---|
| Potentiometer VCC | 5V |
| Potentiometer GND | GND |
| Potentiometer SIG | A0 |
| LED Anode (+) | Resistor -> Pin 8 |
| LED Cathode (-) | GND |
| Buzzer (+) | Pin 9 |
| Buzzer (-) | GND |

---

## How It Works

1. The potentiometer (simulating MQ2) outputs an analog value between **0 and 1023** to pin A0
2. Arduino reads this value every **300ms**
3. If the value is **above 550** -> smoke detected -> LED ON + Buzzer ON
4. If the value is **below 550** -> air is clear -> LED OFF + Buzzer OFF
5. All readings are printed to the **Serial Monitor** in real time

---

## Code Summary

```cpp
#define SENSOR_PIN       A0
#define LED_PIN           8
#define BUZZER_PIN        9
#define SMOKE_THRESHOLD  550

void loop() {
  int val = analogRead(SENSOR_PIN);
  if (val > SMOKE_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }
  delay(300);
}
```

---

## How to Run (Wokwi Simulation)

1. Open [Wokwi](https://wokwi.com) and create a new **Arduino Uno** project
2. Paste the `diagram.json` into the diagram editor
3. Paste the code into `sketch.ino`
4. Press Play to start the simulation
5. **Turn the potentiometer knob:**
   - Left (low value) -> Air is Clear -> Silent
   - Right (high value) -> SMOKE DETECTED -> Buzzer + LED alarm

---

## Threshold Tuning

| Sensor Value | Status | System Response |
|---|---|---|
| 0 - 549 | Clear Air | LED OFF, Buzzer silent |
| 550 - 1023 | Smoke Detected | LED ON, Buzzer beeping |

> To make it more or less sensitive, change `SMOKE_THRESHOLD` in the code.
> - **Higher value** (e.g. 700) = Less sensitive
> - **Lower value** (e.g. 350) = More sensitive

---

## Project Files

```
SmokeGuard/
├── sketch.ino       → Arduino source code
├── diagram.json     → Wokwi circuit diagram
└── README.md        → Project documentation
```

---

## Future Improvements

- [ ] Add an LCD display to show live PPM readings
- [ ] Add a green LED for "safe" status
- [ ] Integrate real MQ2 sensor on physical hardware
- [ ] Add WiFi alert using ESP32 instead of Arduino Uno
- [ ] Add a reset button to silence the alarm

---

## Author

**Task 03 — Smoke & Gas Detector**
Simulated on Wokwi | Built with Arduino Uno

---

## License

This project is open-source and free to use for educational purposes.