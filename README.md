# SSSL
Smart solar LED street light network.

The aim of this project is to design a Smart solar LED street light network that is fully automated and consumes minimal power.
In many cities the street lights are still controlled manually and have no additional control over brightness and state of the LED light's health.
This leads to waste of time, energy and resources. In this project a smart solar-powered street light network is developed. PIR and Daylight sensors are used to turn ON/OFF the connected lights when needed. Also a PWM signal is used to control the brightness of the light. An Android/iOS application is developed to enable remote control to the user.

The ESP8266 based NodeMCU is used to realise the above mentioned features in the designed system. This microcontroller is connected to the cloud using the Firebase real-time database services and sends data on the LED health and battery health information to the users mobile application. If an LED goes dead or the battery need servicing the system sends a notification to the mobile application. 

The Android/iOS application was developed using the Thunkable cross-platform application builder. Each user is authenticated using the Furebase Authentication service ensuring the security of the user's data. 


