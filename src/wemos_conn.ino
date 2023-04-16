#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>

// Credenciais da Wifi
const char* ssid = "***";
const char* password = "***";

// Credenciais do broker
const char* mqtt_server = "***";
const char* mqtt_username = "***";
const char* mqtt_password = "***";
const int mqtt_port = 8883;

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {
  delay(10);
  // WiFi
  // Aguardar conexão
  Serial.println("Conectando na WiFi!!!");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("\nWiFi Conectada \nIP address: ");
  Serial.println(WiFi.localIP());
}

/************* Connect to MQTT Broker ***********/
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("led_state");  // subscribe the topics here
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");  // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

/***** Call back Method for Receiving MQTT messages and Switching LED ****/

void callback(char* topic, byte* payload, unsigned int length) {
  String payloadStr = "";
  for (int i = 0; i < length; i++) {
    payloadStr += (char)payload[i];
  }
  //--- check the incomming message
  // Fazer as verificações aqui
  // Se uma mensagem chegar, verificar se é "U", "B", "L", "R" (Up, Back, Left, Right), e realizar uma ação no motor
  if (String(topic).equals("auto_agro/led")) {
    if (payloadStr.equals("1")) {
      Serial.println("Ligar");
      digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
    } else if (payloadStr.equals("0")){
      Serial.println("DesLigar");
      digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off
    } else {
      Serial.println("INVALID OPTION");
    }
  }
    // if (payloadStr.equals("U")) {
    //   Serial.println("Movimenta para frente")
    // }
    // if (payloadStr.equals("B")) {
    //   Serial.println("Movimenta para tras")
    // }
    // if (payloadStr.equals("L")) {
    //   Serial.println("Movimenta para esquerda")
    // }
    // if (payloadStr.equals("R")) {
    //   Serial.println("Movimenta para direita")
    // }
}


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
