#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <LoRa.h>

#define ss 10
#define rst 9
#define dio0 8

void setup() {
 Serial.begin(9600);
 LoRa.setPins(ss, rst, dio0);
   //replace the LoRa.begin(---E-) argument with your location's frequency
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(433E6)) {
//    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xF3);
//  Serial.println("LoRa Initializing OK!");
  pinMode(A0,INPUT);
}

void loop() {
 int packetSize = LoRa.parsePacket();
  if (packetSize) {
    DynamicJsonDocument doc(1024);
    while (LoRa.available()) {
      String RecData = LoRa.readString();
//      Serial.println(RecData);
      DeserializationError error = deserializeJson(doc, RecData);
      if (error) {
//        Serial.println(F("Failed to read file, using default configuration"));
//    serializeJson(doc, Serial);
//    Serial.println("");
;
        ;
      }
      else {
    serializeJson(doc, Serial);
    Serial.println("");
      }
}
  }
  if(digitalRead(A0) == 0){
    LoRa.beginPacket();
    LoRa.print("Release");
    LoRa.endPacket();
    delay(300);
  }
}
