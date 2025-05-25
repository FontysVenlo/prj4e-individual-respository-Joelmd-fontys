#include <TMCStepper.h>

#define DIR_PIN     5    // Direction pin
#define STEP_PIN    18   // Step pin
#define R_SENSE     0.11f  // Sense resistor (Ohms)
#define DRIVER_ADDRESS 0b00  // MS1 & MS2 both low = address 0

TMC2209Stepper driver(&Serial2, R_SENSE, DRIVER_ADDRESS);

void setup() {
  // Setup control pins
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  // Start UART for TMC2209 (adjust RX/TX pins if needed)
  Serial2.begin(115200, SERIAL_8N1, 16, 17); // RX=16, TX=17

  // Initialize driver
  driver.begin();
  driver.toff(3);                     // Enable driver (required)
  driver.rms_current(600);           // Set motor current (in mA)
  driver.microsteps(16);             // Set microsteps
  driver.en_spreadCycle(false);      // Enable stealthChop
  driver.pdn_disable(true);          // Use UART instead of PDN
  driver.I_scale_analog(false);      // Use digital scaling
}

void loop() {
  // Step forward
  digitalWrite(DIR_PIN, HIGH);
  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }

  delay(1000);

  // Step backward
  digitalWrite(DIR_PIN, LOW);
  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }

  delay(1000);
}
