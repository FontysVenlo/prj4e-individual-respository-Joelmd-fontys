#include <Arduino.h>

#define RED 14
#define YELLOW 12
#define GREEN 13
#define led1 25

//method to check if CPU is active
void heartbeat(void * parameters);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RED, OUTPUT); 
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(led1, OUTPUT);

  xTaskCreate(heartbeat, "heartbeat", 2000, (void *) led1, 1, NULL);
}

void heartbeat(void * parameter){
  int led;
  led = (int) parameter;
  Serial.println("Im working");

  for(;;){
    digitalWrite(led, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED, HIGH);
  Serial.println("RED is on");
  delay(3000);
  Serial.println("RED is turning off");
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  Serial.println("YELLOW is on");
  delay(3000);
  Serial.println("YELLOW is turning off");
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  Serial.println("GREEN is on");
  delay(3000);
  Serial.println("GREEN is turning off");
  digitalWrite(GREEN, LOW);
}