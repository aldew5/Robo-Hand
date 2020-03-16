#include <Servo.h>

Servo myservo;
int buttonApin = 9;
int buttonBpin = 8;

void setup() {
  // Initialize the button as an output
  pinMode(buttonApin, INPUT_PULLUP);
  // Set the data rate in bits per second
  Serial.begin(9600);
  // attach the servo on pin 9 to the servo object
  myservo.attach(7);
  pinMode(buttonBpin, INPUT_PULLUP);

  int pos = 0;
}

void loop() {
  // if the button A is pressed
  if (digitalRead(buttonApin) == LOW){
    // the servo should rotate 180 degrees
    int pos = 0;
    for (pos = 0; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
  }
  // if button B is pressed move 180 degrees the other was
  int pos = 180;
  if (digitalRead(buttonBpin) == LOW) {
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}
