#include <Arduino.h>
#include <Wire.h>

// ==== MCP23017 Constants ====
#define ADDR    0x20
#define IODIRB  0x01  // Set input/output directions
#define GPIOB   0x13  // Read input values
#define OLATB   0x15  // Write output values

// ==== Bitmask Definitions for GPB pins ====
#define GPB2 0x04  // Manual Producer Button
#define GPB3 0x08  // Manual Consumer Button
#define GPB4 0x10  // LED 1
#define GPB5 0x20  // LED 2
#define GPB6 0x40  // LED 3
#define GPB7 0x80  // LED 4

#define LED1 25    // Heartbeat LED

QueueHandle_t activityQueue;

uint8_t buttonStates = 0;  // Stores input state from GPIOB

// ==== Setup MCP23017 (I2C Expander) ====
void setupMCP() {
  Wire.begin();
  // GPB2 + GPB3 as inputs; GPB4–GPB7 as outputs
  // 0b00001100 = 0x0C → inputs on GPB2/3
  Wire.beginTransmission(ADDR);
  Wire.write(IODIRB);
  Wire.write(0x0C);
  Wire.endTransmission();

  // Turn off all LEDs (GPB4–7)
  Wire.beginTransmission(ADDR);
  Wire.write(OLATB);
  Wire.write(0x00);
  Wire.endTransmission();

  Serial.println("MCP23017 initialized: GPB2, GPB3 as inputs; GPB4–GPB7 as outputs.");
}

// ==== Update Activity LEDs Based on Queue Count ====
void updateActivityLEDs() {
  uint8_t ledOutput = 0x00;
  UBaseType_t count = uxQueueMessagesWaiting(activityQueue);
  Serial.print("Activity Queue Size: ");
  Serial.println(count);

  if (count >= 5) {
    ledOutput = GPB4 | GPB5 | GPB6 | GPB7;
  } else {
    if (count >= 1) ledOutput |= GPB4;
    if (count >= 2) ledOutput |= GPB5;
    if (count >= 3) ledOutput |= GPB6;
    if (count >= 4) ledOutput |= GPB7;
  }

  // Preserve input bits
  Wire.beginTransmission(ADDR);
  Wire.write(OLATB);
  Wire.write(ledOutput);
  Wire.endTransmission();
}

// ==== Heartbeat Task ====
void heartbeat(void *parameter) {
  int led = (intptr_t) parameter;
  while (true) {
    digitalWrite(led, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

// ==== Manual Producer Task ====
void manualProducer(void *parameter) {
  bool lastPressed = false;
  while (true) {
    // Read GPIOB
    Wire.beginTransmission(ADDR);
    Wire.write(GPIOB);
    Wire.endTransmission();
    Wire.requestFrom(ADDR, 1);
    buttonStates = Wire.read();

    bool pressed = !(buttonStates & GPB2); // active-low
    if (pressed && !lastPressed) {
      int task = 1;
      xQueueSend(activityQueue, &task, 0);
      Serial.println("🟩 Button GPB2 pressed → Produced 1 activity.");
      updateActivityLEDs();
    }
    lastPressed = pressed;
    vTaskDelay(50 / portTICK_PERIOD_MS);  // debounce
  }
}

// ==== Manual Consumer Task ====
void manualConsumer(void *parameter) {
  bool lastPressed = false;
  int activity;
  while (true) {
    // Read GPIOB
    Wire.beginTransmission(ADDR);
    Wire.write(GPIOB);
    Wire.endTransmission();
    Wire.requestFrom(ADDR, 1);
    buttonStates = Wire.read();

    bool pressed = !(buttonStates & GPB3); // active-low
    if (pressed && !lastPressed) {
      if (xQueueReceive(activityQueue, &activity, 0)) {
        Serial.println("🟥 Button GPB3 pressed → Consumed 1 activity.");
        updateActivityLEDs();
      } else {
        Serial.println("🟥 Button GPB3 pressed → No activity to consume.");
      }
    }
    lastPressed = pressed;
    vTaskDelay(50 / portTICK_PERIOD_MS);  // debounce
  }
}

// ==== Setup ====
void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);

  setupMCP();

  activityQueue = xQueueCreate(10, sizeof(int));

  xTaskCreate(heartbeat, "Heartbeat", 1024, (void *) LED1, 1, NULL);
  xTaskCreate(manualProducer, "ManualProducer", 2048, NULL, 1, NULL);
  xTaskCreate(manualConsumer, "ManualConsumer", 2048, NULL, 1, NULL);

  Serial.println("System setup complete.");
}

// ==== Loop ====
void loop() {
  // All logic is handled in tasks
}
