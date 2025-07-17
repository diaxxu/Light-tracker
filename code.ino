#include <Servo.h>

// LDR pins
const int ldrTopLeft = A0;
const int ldrTopRight = A1;
const int ldrBottomLeft = A2;
const int ldrBottomRight = A3;

// Servo pin
const int servoPin = 9;
Servo trackerServo;

int pos = 90; // initial servo position

void setup() {
  Serial.begin(9600);
  trackerServo.attach(servoPin);
  trackerServo.write(pos);
}

void loop() {
  // Read light levels
  int tl = analogRead(ldrTopLeft);
  int tr = analogRead(ldrTopRight);
  int bl = analogRead(ldrBottomLeft);
  int br = analogRead(ldrBottomRight);

  // Average top and bottom
  int top = (tl + tr) / 2;
  int bottom = (bl + br) / 2;

  // Average left and right
  int left = (tl + bl) / 2;
  int right = (tr + br) / 2;

  int verticalDiff = top - bottom;
  int horizontalDiff = left - right;

  // Tune this threshold for stability
  int threshold = 50;

  // Adjust servo based on horizontal light difference
  if (abs(horizontalDiff) > threshold) {
    if (horizontalDiff > 0) {
      pos -= 1;  // Move left
    } else {
      pos += 1;  // Move right
    }

    pos = constrain(pos, 0, 180);
    trackerServo.write(pos);
    delay(15); // Small delay for smooth motion
  }

  Serial.print("LDR TL:");
  Serial.print(tl);
  Serial.print(" TR:");
  Serial.print(tr);
  Serial.print(" BL:");
  Serial.print(bl);
  Serial.print(" BR:");
  Serial.print(br);
  Serial.print(" Pos:");
  Serial.println(pos);

  delay(100);
}
