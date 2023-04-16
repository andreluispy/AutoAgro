#include <WiFiNINA.h>
#include <PubSubClient.h>

// WiFi settings
char ssid[] = "***";
char ssid_password[] = "***";
int wifi_status = WL_IDLE_STATUS;
const char* server = "xxx.s1.eu.hivemq.cloud";

WiFiClient network;
PubSubClient mqttClient(network);

void setup() {
  while (wifi_status != WL_CONNECTED) {
    Serial.print(".");
    wifi_status = WiFi.begin(ssid, ssid_password);
    delay(2500);
  }
}

void init_mqtt() {
  mqttClient.setServer(server, 8883);

  if (mqttClient.connect("Arduino", "xxx", "xxx")) {
    Serial.println("Connected");
  } else {
    Serial.print("Connection failed: ");
    Serial.println(mqttClient.state());
  }
}