#include <SPI.h>
#include <LoRa.h>
#include <ArduinoJson.h>
#include <Servo.h>
#include "DHT.h"
#include <MQ135.h>


int period = 2000;
unsigned long time_now = 0;

#define ss 10
#define rst 9
#define dio0 8

#define DHTPIN 2
#define DHTTYPE DHT11


  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  
#define Fband 433E6


Servo myservo;
DHT dht(DHTPIN, DHTTYPE);
MQ135 mq135_sensor(A1);

void setup() {
Serial.begin(9600);

 LoRa.setPins(ss, rst, dio0);
  while (!LoRa.begin(Fband)) {
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xF3);
//   myservo.write(0);
   dht.begin();
//   myservo.detach();
//   pinMode(3,OUTPUT);
//   digitalWrite(3,LOW);
//   myservo.detach();
}

void loop() { 

//Serial.print("T:");
//Serial.println(t);
  if (millis() >= time_now + period) {
    time_now += period;
    float h = dht.readHumidity();
float t = dht.readTemperature();
float mq7 = analogRead(A0);
float ppm =mq135_sensor.getCorrectedPPM(t, h);
    StaticJsonDocument<200> doc;
    doc["t"] = t;
    doc["h"] = h;
    doc["m7"] = mq7;
    doc["aq"] = (int)ppm;
    serializeJson(doc, Serial);
    Serial.println("");
    LoRa.beginPacket();
    serializeJson(doc, LoRa);
    LoRa.endPacket();
    }

 int packetSize = LoRa.parsePacket();
  if (packetSize) {
    while (LoRa.available()) {
      String RecData = LoRa.readString();
      if(RecData.indexOf("Release")!= -1){
      Serial.println(RecData);
      release_servo();
      digitalWrite(3,LOW);
      }
    }
  }

     
}

void release_servo(){
  myservo.attach(3);
  int pos = 0;
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2);                       // waits 15 ms for the servo to reach the position
  }
  myservo.detach();
}
