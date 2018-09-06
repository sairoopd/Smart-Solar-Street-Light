# SSSL
Smart solar LED street light network.

The aim of this project is to design a Smart solar LED street light network that is fully automated and consumes minimal power.
In many cities the street lights are still controlled manually and have no additional control over brightness and state of light's health.
This leads to a huge wastage of time, energy and resources. In this project I am developing a street light network that uses PIR and Daylight sensors to turn ON/OFF connected lights when needed. I am also using a PWM signal to control the brightness of the light.

An ESP8266 based NodeMCU is used to enable above mentioned features in the designed system. This microcontroller is connected to the cloud and sends data like the LED health and battery health information over the internet. When an LED goes dead the system sends a notification to the cloud. An Android application is developed to enable remote control to the user. Data can be  sent to and fro from the system to the operator over the cloud using this Android application.


