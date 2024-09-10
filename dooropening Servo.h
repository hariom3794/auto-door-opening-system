#include <Servo.h>

Servo myServo;  // Create servo object

// Define pin numbers
const int trigPin = 9;
const int echoPin = 8;
const int servoPin = 3;

void setup() {
  myServo.attach(servoPin);  // Attach servo motor to pin 3
  pinMode(trigPin, OUTPUT);  // Set trig pin as output
  pinMode(echoPin, INPUT);   // Set echo pin as input
  myServo.write(0);          // Close door (servo at 0 degrees)
}

void loop() {
  int distance = getDistance();  // Measure distance

  if (distance < 50) {           // If object is closer than 50 cm
    myServo.write(90);           // Open door (rotate servo to 90 degrees)
    delay(3000);                 // Wait for 3 seconds
    myServo.write(0);            // Close door (rotate servo back to 0 degrees)
    delay(1000);                 // Wait before next measurement
  }
}

int getDistance() {
  // Send a trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo pulse duration
  long duration = pulseIn(echoPin, HIGH);

  // Convert duration to distance (cm)
  int distance = duration * 0.034 / 2;
  return distance;
}
