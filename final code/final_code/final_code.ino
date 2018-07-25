#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "**********56a266";

// WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Roo";
char pass[] = "**********";
#define led D7  // LED on Pin D7 of NodeMCU
#define pir D1 // Input for HC-S501
int pirop; // Place to store PIR input
BlynkTimer timer;

void setup()
{
  // Debug console
  Serial.begin(115200); 
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  digitalWrite(led, LOW);
  timer.setInterval(250L, motionDetected);
}

void  motionDetected()
{ 
  pirop = digitalRead(pir);
  if (!pirop){     // If no motion is detcted LED stays at 50% brightness
    Serial.println("no motion detcted");
    analogWrite(led, 75);
  }
  
  else if (pirop){ // If any motion is detected LED switches to full brightness for 20 seconds
   Serial.println("motion detcted");
   digitalWrite(led, HIGH);
  }
}

int pinValue;
BLYNK_WRITE(V5){
    pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
}

void loop()
{
  Blynk.run();
  if(pinValue) // if Button sends 1
    {      
     timer.run(); // start the function
    }
}



