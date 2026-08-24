# ESP32 Multi-Protocol Wireless Sniffing Platform
![Arduino](https://img.shields.io/badge/Arduino-ESP32-blue)
![Wireless](https://img.shields.io/badge/Wireless-WiFi%2FBLE%2FRC-green)
![Research](https://img.shields.io/badge/Research-Embedded%20Security-orange)
![License](https://img.shields.io/badge/License-MIT-red)

## Overview

This project presents a **custom hardware platform for passive wireless signal sniffing**, built around an ESP32-WROOM-U module with external antenna connectors. The platform is designed to capture , analyze and send 2.4GHz Wi-Fi, Bluetooth Classic (BT), Bluetooth Low Energy (BLE), and RC control signals for research and educational purposes.

The system is purely passive/receive-focused — it listens to and analyzes wireless traffic in its environment rather than transmitting or interfering with it.

> **Disclaimer**
>
> This project is intended for educational and research purposes only. Only capture and analyze traffic on networks/devices you own or have explicit permission to monitor. Passive sniffing of third-party wireless traffic may be restricted or illegal depending on your jurisdiction — check local regulations before use.

---

## Features

- Multi-protocol passive sniffing / sending: Wi-Fi 2.4GHz, Bluetooth Classic, BLE, and RC signals
- External antenna support for improved reception range
- ESP32-WROOM-U module design
- Onboard status LED indicator
- Firmware developed in the Arduino IDE
- Custom-designed PCB for compact, purpose-built hardware

---

## Technologies

- C++ (Arduino IDE / ESP-IDF libraries)
- ESP32 Wi-Fi/Bluetooth stack

---

## Hardware

| Component | Purpose |
|---|---|
| 1x ESP32-WROOM-U module | (external antenna variant) |
| 2x NRF24L01+PA+LNA antennas
| 2x 10µF 63V capacitors | Power supply filtering/decoupling |
| LED + resistor | Status indicator |
| Custom PCB | Integrates all components into a single board |

---

## Project Structure

```
firmware/            # Arduino IDE
pcb/                 # Schematic and layout files
media/               # Board photos, screenshots
```

---

## Getting Started

### Clone the repository

```bash
git clone https://github.com/yourusername/esp32jamm.git
cd esp32jamm
```

### Hardware

Assemble the custom PCB using the schematic and BOM located in the `pcb/` directory.

### Firmware

Open the appropriate firmware project in the Arduino IDE.

Install the required ESP32 board package:

- ESP32 by Espressif Systems

Select the correct COM port and upload the firmware to ESP32-WROOM-U module.

---

## Future Work

- Structured packet logging (CSV/JSON export)
- BLE advertisement decoding and device fingerprinting
- Signal strength mapping over physical space
- Companion dashboard for live visualization of captured traffic

---

## License

MIT License

---

## Author

Nistor Darius

Embedded Systems • Wireless Research • Hardware Design
