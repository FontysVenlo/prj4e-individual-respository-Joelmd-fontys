#include <Arduino.h>
#include <Wire.h>
#include "main.h"

#define LED1 25
#define ADDR 0x20
#define GPB7 0x80  // GPB7 pin (most significant bit)
#define GPB6 0x40  // GPB6 pin
#define GPB5 0x20  // GPB5 pin (red LED)
#define GPB4 0x10  // GPB4 pin (blue LED)
#define GPB3 0x08  // GPB3 pin (yellow LED)
#define IODIRB 0x01
#define GPIOB 0x13

uint8_t startup[] = {ADDR, IODIRB, 0x00, 0};  // everything is output 
uint8_t green[] = {ADDR, GPIOB, GPB7, 1};  // Green LED on GPB7
uint8_t white[] = {ADDR, GPIOB, GPB6, 1};  // White LED on GPB6
uint8_t red[] = {ADDR, GPIOB, GPB5, 1};    // Red LED on GPB5
uint8_t blue[] = {ADDR, GPIOB, GPB4, 1};   // Blue LED on GPB4
uint8_t yellow[] = {ADDR, GPIOB, GPB3, 1}; // Yellow LED on GPB3

void setup(){
  Wire.begin();  
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  xTaskCreate(heartbeat, "heartbeat", 2000, (void *) LED1, 1, NULL);
  xTaskCreate(taskHandler, "taskHandler", 2000, NULL, 1, NULL);
  Serial.println("MCP23017 initialized.");
}

void taskHandler(void * parameter){
  uint8_t *taskParams1 = (uint8_t *)malloc(4 * sizeof(uint8_t));
  uint8_t *taskParams2 = (uint8_t *)malloc(4 * sizeof(uint8_t));
  uint8_t *taskParams3 = (uint8_t *)malloc(4 * sizeof(uint8_t));  // White LED task
  uint8_t *taskParams4 = (uint8_t *)malloc(4 * sizeof(uint8_t));  // Red LED task
  uint8_t *taskParams5 = (uint8_t *)malloc(4 * sizeof(uint8_t));  // Blue LED task
  uint8_t *taskParams6 = (uint8_t *)malloc(4 * sizeof(uint8_t));  // Yellow LED task

  if (taskParams1 == NULL || taskParams2 == NULL || taskParams3 == NULL || taskParams4 == NULL || taskParams5 == NULL || taskParams6 == NULL) {
    Serial.println("Memory allocation failed!");
    return;
  }

  memcpy(taskParams1, startup, 4);  
  memcpy(taskParams2, green, 4);
  memcpy(taskParams3, white, 4);  // Copy white array
  memcpy(taskParams4, red, 4);    // Copy red array
  memcpy(taskParams5, blue, 4);   // Copy blue array
  memcpy(taskParams6, yellow, 4); // Copy yellow array

  // Create tasks for each LED color
  xTaskCreate(transmit, "transmit", 2000, (void *) taskParams1, 1, NULL);
  xTaskCreate(transmit, "transmit", 2000, (void *) taskParams2, 1, NULL);
  xTaskCreate(transmit, "transmit", 2000, (void *) taskParams3, 1, NULL);  // White task
  xTaskCreate(transmit, "transmit", 2000, (void *) taskParams4, 1, NULL);  // Red task
  xTaskCreate(transmit, "transmit", 2000, (void *) taskParams5, 1, NULL);  // Blue task
  xTaskCreate(transmit, "transmit", 2000, (void *) taskParams6, 1, NULL);  // Yellow task
  
  vTaskDelete(NULL);  // Delete taskHandler after creating tasks
}

void heartbeat(void * parameter){
  int led;
  led = (intptr_t) parameter;
  Serial.println("I'm working");

  for(;;){
    digitalWrite(led, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void transmit(void * parameter){
  uint8_t *addresses = (uint8_t *)parameter;
  do
  {
    // Configure pins as output (IODIRB register)
    Wire.beginTransmission(addresses[0]);
    Wire.write(addresses[1]);
    Wire.write(addresses[2]);
    Wire.endTransmission();

    if (addresses[3] == 1){
      // Turn on/off LED based on addresses[3]
      vTaskDelay(250 / portTICK_PERIOD_MS);
      Wire.beginTransmission(addresses[0]);
      Wire.write(addresses[1]);
      Wire.write(0x00); 
      Wire.endTransmission(); 
    
      vTaskDelay(250 / portTICK_PERIOD_MS);
    }
  }
  while(addresses[3] == 1);

  free(addresses);  
  vTaskDelete(NULL);
}

void loop(){}
