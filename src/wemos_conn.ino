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
  randomSeed(micros());
  Serial.println("");
  Serial.println("\nWiFi Conectada \nIP address: ");
  Serial.println(WiFi.localIP());
}

/************* Connect to MQTT Broker ***********/
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    // Create a random client ID
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
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
  String incommingMessage = "";
  for (int i = 0; i < length; i++) incommingMessage += (char)payload[i];

  Serial.println("Message arrived [" + String(topic) + "]" + incommingMessage);

  //--- check the incomming message
  // Fazer as verificações aqui
  // Se uma mensagem chegar, verificar se é "U", "B", "L", "R" (Up, Back, Left, Right), e realizar uma ação no motor
  if (strcmp(topic, "led_state") == 0) {

    /* if (incommingMessage.equals("1")) {
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
  } else {
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off
  } */
    if (incommingMessage.equals("U")) {
      Serial.println("Movimenta para frente")
    }
    if (incommingMessage.equals("B")) {
      Serial.println("Movimenta para tras")
    }
    if (incommingMessage.equals("L")) {
      Serial.println("Movimenta para esquerda")
    }
    if (incommingMessage.equals("R")) {
      Serial.println("Movimenta para direita")
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) delay(1);
  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) reconnect();  // check if client is connected
  client.loop();
}
