// Define the pins for the shift register
#define DATA_PIN 13
#define CLOCK_PIN 14
#define LATCH_PIN 15

// Define the motor step sequence
const uint8_t STEPS[4] = {
  B10000001, B01000010, B00100100, B00011000
};

// Initialize the motor position
int motorPos = 0;

void setup() {
  // Set the shift register pins as outputs
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
}

void loop() {
  // Shift out the motor step data
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, STEPS[motorPos]);
  digitalWrite(LATCH_PIN, HIGH);
  
  // Move to the next motor step
  motorPos = (motorPos + 1) % 4;
  
  // Delay to control motor speed
  delay(3);
}
