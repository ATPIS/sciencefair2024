const int fsrPin = A0;  // FSR analog input pin
const int sensorPin = A1;
const int led1Pin = 2;
const int led2Pin = 3;
const int led3Pin = 4;
const int led4Pin = 5;
const int led5Pin = 6;
const int led6Pin = 7;

void setup() {
  pinMode(fsrPin, INPUT);   // FSR pin as input
  pinMode(sensorPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(led6Pin, OUTPUT);
}

void loop() {
  int fsrValue = analogRead(fsrPin);  // Read FSR value

  // Adjust this threshold based on your FSR sensitivity
  int threshold = 500;  // Example threshold value

  if (fsrValue > threshold) {
    // Apply pressure detected, turn on all three LEDs
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
  } else {
    // No pressure, turn off all LEDs
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  }

  int lightLevel = analogRead(sensorPin); // Read light level from sensor

  if (lightLevel < threshold) {
    digitalWrite(led4Pin, HIGH);  // Turn on first LED
    digitalWrite(led5Pin, HIGH);  // Turn on second LED
    digitalWrite(led6Pin, HIGH);  // Turn on third LED
  } else {
    digitalWrite(led4Pin, LOW);   // Turn off first LED
    digitalWrite(led5Pin, LOW);   // Turn off second LED
    digitalWrite(led6Pin, LOW);   // Turn off third LED
  }


  // Optional delay to prevent rapid readings
  delay(100);
}
