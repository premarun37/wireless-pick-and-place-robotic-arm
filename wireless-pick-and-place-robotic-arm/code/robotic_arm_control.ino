#include <Servo.h>

Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo gripperServo;

// Initial positions
int basePos = 90;
int shoulderPos = 90;
int elbowPos = 90;
int gripperPos = 90;

const int STEP_SIZE = 3;   // Small step for smooth movement
char command;

void setup() {
  Serial.begin(9600);

  baseServo.attach(9);
  shoulderServo.attach(10);
  elbowServo.attach(11);
  gripperServo.attach(6);

  baseServo.write(basePos);
  shoulderServo.write(shoulderPos);
  elbowServo.write(elbowPos);
  gripperServo.write(gripperPos);
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();

    switch (command) {

      // Base rotation
      case 'A': basePos += STEP_SIZE; break;
      case 'B': basePos -= STEP_SIZE; break;

      // Shoulder
      case 'C': shoulderPos += STEP_SIZE; break;
      case 'D': shoulderPos -= STEP_SIZE; break;

      // Elbow
      case 'E': elbowPos += STEP_SIZE; break;
      case 'F': elbowPos -= STEP_SIZE; break;

      // Gripper
      case 'G': gripperPos += STEP_SIZE; break;
      case 'H': gripperPos -= STEP_SIZE; break;
    }

    // Constrain angles
    basePos = constrain(basePos, 0, 180);
    shoulderPos = constrain(shoulderPos, 0, 180);
    elbowPos = constrain(elbowPos, 0, 180);
    gripperPos = constrain(gripperPos, 0, 180);

    // Apply movement
    baseServo.write(basePos);
    shoulderServo.write(shoulderPos);
    elbowServo.write(elbowPos);
    gripperServo.write(gripperPos);

    delay(20);  // Smooth transition delay
  }
}
