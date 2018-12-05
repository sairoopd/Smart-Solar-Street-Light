#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> 
#define FIREBASE_HOST "********.firebaseio.com"                     //the Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "************************"       //Firebase Database Secret
#define WIFI_SSID "*****"
#define WIFI_PASSWORD "********"
#define led D7  // LED on Pin D7/GPIO 13 of NodeMCU
#define switch1 D1 // switch connected to D1 on nodemcu
int pirop; // Place to store power-saver mode input
int x1;
int y;
int b;
int switchstat;

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(switch1, INPUT); 
  Serial.println("setup");
  switchstat = digitalRead(switch1);
  if (!switchstat){
    Serial.println("switch ON");
    digitalWrite(led, HIGH);}
  WiFiManager wifiManager;
  wifiManager.autoConnect("SSL");
  IPAddress ip = WiFi.localIP();
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH); //connect to firebase cloud
  Firebase.setInt("S1",0);                     //Set initializing values in firebase variables
  Firebase.setInt("S2",0);
  Firebase.setInt("S3",1); 
}

void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
}
 
void loop() 
{
  Serial.println("started");
  switchstat = digitalRead(switch1);// when switch on board the system is ON
  if (!switchstat){
    Serial.println("switch ON");
    digitalWrite(led, HIGH);}
    delay(2000);
  if (switchstat)     //when switch on board the system is OFF, switch system control to mobile application
  {
    if (Firebase.failed()) 
      {
        Serial.print("setting number failed:");
        Serial.println(Firebase.error());
        firebasereconnect();    //If connection to firebase fails reconnect
        return;
      } 
    else {
    
    x1 = Firebase.getInt("S1");//get firebase variable S1 value and store it in x1
    b = Firebase.getInt("S3");//get firebase variable S3 value and store it in b
    pirop = Firebase.getInt("S2");//get firebase variable S2 value and store it in pirop
    
    if(x1==1 && pirop==0)//If power ON button pressed and 
    { 
      //digitalWrite(led, HIGH);
      Serial.println("LED ON");
      if (b)
      {
        analogWrite(led, b);
        Serial.println("brightness set to");
        Serial.print(b);
      }
    }
      else if (x1==0)
     {
      digitalWrite(led, LOW);
      Serial.println("LED OFF");
      //ESP.deepSleep(10000, WAKE_RF_DEFAULT);    
     }
    
    if (pirop == 1)
    {
        analogWrite(led, 500);
        Serial.println("power saver mode");
    }
    else {
      Serial.println("Power saver mode off");
      }
   }
 }
}
  
