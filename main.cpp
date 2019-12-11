/* This code consists of a TCP client in the ESP32 connected to a TCP server hosted in the RPI openFrameworks */
/* Will need to adjust accordingly for ESP8266 */
#include <Arduino.h>
#include "WiFi.h" 

/* This will need to change accordingly based on router configuration */
char const* SSID = "9184@unifi";
char const* PASSWORD = "patreck1";
char const* HOST = "192.168.0.104"; //check ip of raspberry pi
uint16_t PORT = 52232;

int capSensor1 = 23;
/*Comment for now */
/*
int capSensor2 = 24;
int capSensor3 = 25;
*/
void setup() {
 	Serial.begin(115200);
	delay(20);
  
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(capSensor1, INPUT);
  /*
  pinMode(capSensor2, INPUT);
  pinMode(capSensor3, INPUT);
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;

    if (!client.connect(HOST, PORT)) {
        Serial.println("Connection failed.");
        Serial.println("Waiting 5 seconds before retrying...");
        delay(5000);
        return;
    }
    if(digitalRead(capSensor1))
    {
      client.print("first**");
    }
    /*
    else if(digitalRead(capSensor2))
    {
       client.print("second**");
    }
    else if((digitalRead(capSensor3))
    {
      client.print("third**");
    }
    */
    else{
      client.print("nvm**");
    }
    client.stop();
    Serial.println("Waiting 5 seconds before restarting...");
    delay(100);
}