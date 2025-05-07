// Define motor pins
#define motorA1 5
#define motorA2 6
#define motorB1 9
#define motorB2 10

// Define sensor pins
#define sensorLeft A0
#define sensorRight A1

void setup() {
  // Set motor pins as outputs
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  // Set sensor pins as inputs
  pinMode(sensorLeft, INPUT);
  pinMode(sensorRight, INPUT);
}

void loop() {
  // Read sensor values
  int leftValue = analogRead(sensorLeft);
  int rightValue = analogRead(sensorRight);

  // Threshold value for detecting line
  int threshold = 500;

  // Check sensor values and control motors
  if (leftValue < threshold && rightValue < threshold) {
    // Both sensors on line, move forward
    moveForward();
  } else if (leftValue < threshold) {
    // Left sensor on line, turn left
    turnLeft();
  } else if (rightValue < threshold) {
    // Right sensor on line, turn right
    turnRight();
  } else {
    // No sensors on line, stop
    stop();
  }
}

void moveForward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnLeft() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnRight() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void stop() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}