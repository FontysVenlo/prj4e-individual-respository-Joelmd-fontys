// ---------------------------------------------------------
// BOTH SEND AND RECVIEVE CODE IN 1 FILE FOR EASIER OVERVIEW
// ---------------------------------------------------------

//LORA SEND 
#include <Arduino.h>
#include <LoRa.h>

// Define LoRa SPI and control pins based on your pinout
#define LORA_SCK  5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_CS   18  // NSS
#define LORA_RST  23
#define LORA_DIO0 26

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Initializing LoRa...");

  // Manually initialize SPI with your pins
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_CS);

  // Tell LoRa to use your SPI bus
  LoRa.setSPI(SPI);

  // Set LoRa control pins
  LoRa.setPins(LORA_CS, LORA_RST, LORA_DIO0);

  if (!LoRa.begin(868E6)) {
    Serial.println("LoRa init failed. Check connections or frequency.");
    while (true) {
      Serial.println("failure");
      delay(1000);
    }
  }

  Serial.println("LoRa Sender Ready");
}

void loop() {
  unsigned long timestamp = millis();  // Get the current timestamp

  Serial.println("Sending packet...");

  LoRa.beginPacket();
  LoRa.print("Timestamp: ");           // Add a label to the message
  LoRa.print(timestamp);              // Add the timestamp
  LoRa.print(" | Message: Hello!");   // The message you want to send
  LoRa.endPacket();

  delay(2000);  // Wait 2 seconds before sending another packet
}
//--------------
//LORA RECIEVE
#include <Arduino.h>
#include <LoRa.h>
#include <SPI.h>

// Define LoRa SPI and control pins based on your pinout
#define LORA_SCK  5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_CS   18  // NSS
#define LORA_RST  23
#define LORA_DIO0 26

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Initializing LoRa Receiver...");

  // Manually initialize SPI with your pins
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_CS);

  // Tell LoRa to use your SPI bus
  LoRa.setSPI(SPI);

  // Set LoRa control pins
  LoRa.setPins(LORA_CS, LORA_RST, LORA_DIO0);

  if (!LoRa.begin(868E6)) {
    Serial.println("LoRa init failed. Check connections or frequency.");
    while (true) {
      Serial.println("failure");
      delay(1000);
    }
  }

  Serial.println("LoRa Receiver Ready");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet: ");
    
    // Read and print the message byte by byte
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    
    Serial.println();
  }
}