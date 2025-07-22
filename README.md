
#  Light Tracker

A simple Arduino-based system that tracks the brightest light source using 4 LDRs.  


---

## 📦 Features

- Tracks sunlight or any bright source in real-time
- Uses 4 LDR sensors to detect brightness in 4 quadrants
- Automatically rotates a platform (servo) to face the brightest direction
- CAD-ready for 3D print or cardboard prototyping

---

## 🛠️ Tech Used

- Arduino Uno
- 4x LDR (Light Dependent Resistors)
- 4x 10kΩ resistors
- 1x Servo motor (SG90 or similar)
- Cardboard or 3D printed frame (Fusion 360)
- Breadboard + Jumper Wires

---

## 📁 Folder Structure

- `/code` → Arduino sketch (`.ino`)
- `/CAD` → 3D files (`.stl`)
- `/diagrams` → Wiring and circuit diagrams

---

## 🚀 How It Works

The 4 LDRs are positioned in a cross pattern. The Arduino reads their analog values, compares light intensity in all 4 directions, and rotates the servo toward the brightest spot. Simple logic, effective results.

---

