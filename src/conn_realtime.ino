#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Credenciais da Wifi
const char* ssid = "";
const char* password = "";

// Credenciais do firebase

#define FIREBASE_HOST "" // URL do realtime database
#define  FIREBASE_AUTH "" // configurações do projeto > contas de serviço > chaves secretas do banco de dados
//#define FIREBASE_PROJECT_ID ;

// INICIALIZAR OS CLIENTES
WiFiClient espClient;
FirebaseData ledData;
FirebaseData firebaseData;


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


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  setup_wifi();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {

  if(Firebase.getString(ledData, "/dir")){
    Serial.println(ledData.stringData());
    if(ledData.stringData() == "1"){
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(ledData.stringData() == "0"){
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
