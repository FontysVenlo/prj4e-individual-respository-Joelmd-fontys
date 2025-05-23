#include <Arduino.h>

#define LED1 25
#define MOTOR 15
#define CW 12
#define CCW 13
#define ENABLE 14
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
const int motChannel = 1;
const int fadeSteps = 100;

// method to check if CPU is active
void heartbeat(void * parameters);
void lightUp(void * parameters);
void fadeToBrightness(int targetBrightness);

void setup(){
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  pinMode(CW, OUTPUT);
  pinMode(CCW, OUTPUT);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(MOTOR, ledChannel);

  xTaskCreate(heartbeat, "heartbeat", 2000, (void *) LED1, 1, NULL);
  xTaskCreate(lightUp, "lightUp", 2000, NULL, 1, NULL);
}

void heartbeat(void * parameter){
  int led;
  led = (int) parameter;
  Serial.println("I'm working");

  for(;;){
    digitalWrite(led, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void lightUp(void * parameter){
  digitalWrite(ENABLE, HIGH);
  // Clockwise
  digitalWrite(CCW, LOW);
  digitalWrite(CW, HIGH);

  while(true){
    // Fade in to 100% brightness
    fadeToBrightness(25);  // Fade to 100% brightness
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Wait for a second
    
    // Fade out to 0% brightness
    fadeToBrightness(0);  // Fade to 0% brightness
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Wait for a second
  }
}

// Function to fade the LED to a target brightness (in percentage)
void fadeToBrightness(int targetBrightness){
  float k = 0.1;       // Steepness of the sigmoid curve
  int targetDutyCycle = (255 * targetBrightness) / 100;
  float midpoint = fadeSteps / 2.0;
  
  int currentDutyCycle = ledcRead(ledChannel);  // Get the current duty cycle
  
  int fadeDirection = (targetDutyCycle > currentDutyCycle) ? 1 : -1; // Determine fade direction
  
  for (int x = currentDutyCycle; (fadeDirection == 1) ? (x <= targetDutyCycle) : (x >= targetDutyCycle); x += fadeDirection) {
    // Calculate the duty cycle using the sigmoid function
    float sigmoid = 1 / (1 + exp(-k * (x - midpoint)));  // Sigmoid function
    int dutyCycle = (int)(255 * sigmoid);
    ledcWrite(ledChannel, dutyCycle);
    vTaskDelay(10 / portTICK_PERIOD_MS);  // Adjust for speed of fade
  }
}

void loop(){
}
