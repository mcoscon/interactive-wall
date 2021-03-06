/* This code consists of a TCP client in the ESP32 connected to a TCP server hosted in the RPI openFrameworks */
/* Will need to adjust accordingly for ESP8266 */
#include <Arduino.h>
#include <ESP8266WiFi.h>

/* This will need to change accordingly based on router configuration */
char const* SSID = "Pinstay10-16";
char const* PASSWORD = "ilovepinstay1016";
char const* HOST = "192.168.1.80"; //check ip of raspberry pi
uint16_t PORT = 52233;

int capSensor1 = 14;
int capSensor2 = 12;
int capSensor3 = 13;
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
  pinMode(capSensor2, INPUT);
  pinMode(capSensor3, INPUT);
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
      Serial.println("first");
    }
    else if(digitalRead(capSensor2))
    {
      client.print("second**");
      Serial.println("second");
    }
    
    else if(digitalRead(capSensor3))
    {
      client.print("third**");
      Serial.println("third");
    }
    
    else{
      client.print("nvm**");
    }
    client.stop();
    Serial.println("Waiting 5 seconds before restarting...");
    delay(200);
}
