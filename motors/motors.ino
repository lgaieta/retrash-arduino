#include <Servo.h>
#include <Stepper.h>

// Servo params
Servo servo;
const int servoPin = 10;
const int defaultStateServoDegrees = 0;
const int activeStateServoDegrees = 45;

// Stepper params
const int stepsPerRevolution = 200;
Stepper stepper = Stepper(stepsPerRevolution, 2, 3, 4, 5);

void setup() {
  servo.attach(servoPin);
  stepper.setSpeed(60);
  Serial.begin(9600);
}

void loop()
{
  // Servo test
  servo.write(defaultStateServoDegrees);
  delay(4000);
  servo.write(activeStateServoDegrees);
  delay(1000);

  // Stepper test
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}