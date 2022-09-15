#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "certificate.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

#define CERT mqtt_broker_cert
#define MSG_BUFFER_SIZE (50)

const char* ssid = "WIFINAME";
const char* password = "WIFI_PASS";

const char* mqtt_server = "SERVER_IP";
const char* mqttUser = "user";
const char* mqttPassword = "pass";
const char* mqttTopicIn = "in";
const char* mqttTopicOut = "out";

WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup_wifi(bool skip_verfiy_cert) {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  timeClient.begin();

  if (skip_verfiy_cert){
     wifiClient.setInsecure();
  } else {
    X509List cert(CERT);
    wifiClient.setTrustAnchors(&cert);
  }
  
  Serial.println("WiFi connected");
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [topic:");
  Serial.print(topic);
  Serial.print("] ");
  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  String myCurrentTime = timeClient.getFormattedTime();
  mqttClient.publish(mqttTopicOut,myCurrentTime.c_str());
}

void reconnect() {
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    String mqttClientId = "ESP8266-mqtt-node";
    if (mqttClient.connect(mqttClientId.c_str(), mqttUser, mqttPassword)) {
      Serial.println("connected");
      mqttClient.subscribe(mqttTopicIn);
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println("will try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi(true);
  mqttClient.setServer(mqtt_server, 1883);
  mqttClient.setCallback(callback);
}

void loop() {

  if (!mqttClient.connected()) {
    reconnect();
  }
  
  mqttClient.loop();
  timeClient.update();

}