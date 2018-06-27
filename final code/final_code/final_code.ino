#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "***************";
char ssid[] = "";
char password[] = "**********";
int ledPin = 4;  // Onboard LED Pin 4 of NodeMCU
int pirPin = 7; 
int pirValue; 


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

