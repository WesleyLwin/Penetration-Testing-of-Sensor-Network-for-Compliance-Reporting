# Penetration-Testing-of-Sensor-Network-for-Compliance-Reporting
Capstone project simulating various cyberattacks (Jamming, Sinkhole, DoS, Blackhole, Spoofing) on Contiki OS-based IoT sensor networks using Cooja and C programming.


# 🛡️ IoT Network Attack Simulations – Capstone Project

This capstone project explores the implementation and analysis of multiple cyberattacks on IoT sensor networks using the Contiki operating system and Cooja simulator. It simulates real-world adversarial behavior in wireless sensor networks (WSNs) to understand vulnerabilities and test mitigation strategies.

---

## 📁 Attack Scenarios Implemented

| Attack Type      | Description |
|------------------|-------------|
| **Jamming**       | Disrupts network communication by flooding the channel with noise. |
| **Sinkhole**      | Creates a malicious node that advertises fake optimal routes to intercept traffic. |
| **Blackhole**     | Captures and drops all incoming packets, simulating data loss and denial. |
| **Spoofing**      | Mimics legitimate nodes to manipulate network topology. |
| **DoS**           | Overwhelms nodes or services to render them unavailable. |

---

## 🔧 Technologies Used

- **Contiki OS**
- **Cooja Simulator**
- **C Language**
- **.csc Simulation Files**

---

## 🧪 Files and Scripts

.
├── jammer.c # Jamming attack implementation
├── sky-sinkhole.c # Sinkhole attack on Sky motes
├── dos_attack.c # Denial-of-Service logic
├── blackhole_attack.c # Packet dropper (Blackhole)
├── spoofing_attack.c # Identity spoofing demo
├── cooja_test1.csc # Simulation file (Cooja)

