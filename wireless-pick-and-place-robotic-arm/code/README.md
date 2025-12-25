# Arduino Control Code – Robotic Arm

This directory contains the Arduino source code used to control the
wireless pick-and-place robotic arm.

---

## File Description
- `robotic_arm_control.ino`  
  Main Arduino program for controlling servo motors using Bluetooth commands.

---

## Hardware Pin Mapping

| Component | Arduino Pin |
|--------|-------------|
| Base Servo | D9 |
| Shoulder Servo | D10 |
| Elbow Servo | D11 |
| Gripper Servo | D6 |
| HC-05 TX | D0 (RX) |
| HC-05 RX | D1 (TX) |

---

## Control Strategy
- Servo motors are controlled using incremental step-based motion.
- Each Bluetooth command increases or decreases the servo angle by a small step.
- Servo angles are constrained between 0° and 180°.

---

## Bluetooth Command Mapping

| Command | Action |
|------|------|
| A | Rotate base clockwise |
| B | Rotate base counter-clockwise |
| C | Shoulder up |
| D | Shoulder down |
| E | Elbow up |
| F | Elbow down |
| G | Gripper open |
| H | Gripper close |

---

## Upload Instructions
1. Disconnect HC-05 RX/TX pins.
2. Upload the `.ino` file using Arduino IDE.
3. Reconnect HC-05 module.
4. Pair Bluetooth module with mobile device.
5. Send commands using a Bluetooth controller app.
