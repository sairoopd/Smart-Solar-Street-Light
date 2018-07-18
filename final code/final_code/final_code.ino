#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
<<<<<<< HEAD
char auth[] = "***************";
char ssid[] = "";
char password[] = "**********";
int ledPin = 4;  // Onboard LED Pin 4 of NodeMCU
int pirPin = 7; 
int pirValue; 
=======

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
>>>>>>> cc3dfc817a9baa56ff325114532203eed16d9a0d


void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

  digitalWrite(ledPin, LOW);

}

void loop()
{
  motionDetected();
  Blynk.run();
  
}
void  motionDetected (void)
{
  pirValue = digitalRead(pirPin);
  if (!pirValue){     // If no motion is detcted LED stays at 50% brightness
   analogWrite(ledpin, 512);
  }
  
  while (pirValue){ // If any motion is detected LED switches to full brightness for 20 seconds
   digitalWrite(ledPin, 1023);
  }
}

