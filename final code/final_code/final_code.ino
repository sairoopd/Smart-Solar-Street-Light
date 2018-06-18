#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "************398156a266";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Roo";
char pass[] = "*********";
int ledPin = 4;  // LED on Pin 13 of Arduino
int pirPin = 7; // Input for HC-S501
int pirValue; // Place to store read PIR Value


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

  digitalWrite(ledPin, LOW);

}

void loop()
{
  Blynk.run();
  while(pirValue = LOW){
   pirValue = digitalRead(pirPin);
   analogWrite(ledpin, 512);
  }
  //Serial.println(pirValue);
  if (pirValue = HIGH){
   digitalWrite(ledPin, pirValue);
  }
}

