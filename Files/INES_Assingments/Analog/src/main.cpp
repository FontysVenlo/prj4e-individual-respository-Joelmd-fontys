#include <Arduino.h>

// Pin definitions for analog input
#define ANALOG_PIN 36  // Pin number where you want to read analog values from (example pin 34)
#define LED1 25

void heartbeat(void * parameter);

// Variable to store the analog value
int analogValue = 0;

void setup() {
  // Start Serial communication
  Serial.begin(115200);
  
  // Set up analog pin (usually done automatically, but let's set it as input for clarity)
  pinMode(ANALOG_PIN, INPUT);
  pinMode(LED1, OUTPUT);

  xTaskCreate(heartbeat, "heartbeat", 2000, (void *) LED1, 1, NULL);
}

void loop() {
  // Read analog value from the specified pin
  analogValue = analogRead(ANALOG_PIN);

  // Print the analog value to the serial monitor
  Serial.print("Analog Value: ");
  Serial.println(analogValue);

  // Add a delay for readability
  delay(500);  // Delay 500ms between readings
}

void heartbeat(void * parameter) {
  int led = (intptr_t) parameter;
  Serial.println("Heartbeat task is running");

  for (;;) {
    digitalWrite(led, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
