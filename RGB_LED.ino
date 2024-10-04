/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"
//#define BLYNK_AUTH_TOKEN            "YourAuthToken"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

#define LED 18
#define RED 2
#define GREEN 3
#define BLUE 4


BLYNK_WRITE(V1) {int buttonState = param.asInt(); digitalWrite(LED, buttonState); }
BLYNK_WRITE(V0) {int buttonState = param.asInt(); digitalWrite(RED, buttonState); }
BLYNK_WRITE(V2) {int buttonState = param.asInt(); digitalWrite(GREEN, buttonState); }
BLYNK_WRITE(V3) {int buttonState = param.asInt(); digitalWrite(BLUE, buttonState); }


void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode (LED ,  OUTPUT);
  pinMode (RED ,  OUTPUT);
  pinMode (GREEN ,  OUTPUT);
  pinMode (BLUE ,  OUTPUT);
}

void loop()
{
  Blynk.run();
}

