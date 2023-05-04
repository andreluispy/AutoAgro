/////////////////////////////////
//  CODE BY AUTOAGRO PROJECT   //
// THIS CODE MAKE A ESP SERVER //
// AND GET COMANDS BY HTTP UDP //
/////////////////////////////////

#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

int ma1 = D4;
int ma2 = D5;
int mb1 = D6;
int mb2 = D7;

void go(){
  digitalWrite(ma1, HIGH);
  digitalWrite(ma2, LOW);
  digitalWrite(mb1, HIGH);
  digitalWrite(mb2, LOW);
}

void back(){
  digitalWrite(ma1, LOW);
  digitalWrite(ma2, HIGH);
  digitalWrite(mb1, LOW);
  digitalWrite(mb2, HIGH);
}

void stop(){
  digitalWrite(ma1, LOW);
  digitalWrite(ma2, LOW);
  digitalWrite(mb1, LOW);
  digitalWrite(mb2, LOW);
}

void right(){
  digitalWrite(ma1, HIGH);
  digitalWrite(ma2, LOW);
  digitalWrite(mb1, LOW);
  digitalWrite(mb2, LOW);
}

void left(){
  digitalWrite(ma1, LOW);
  digitalWrite(ma2, LOW);
  digitalWrite(mb1, HIGH);
  digitalWrite(mb2, LOW);
}

// Credenciais WIFI
const char* ssid = "Adminstrativo LIMS";
const char* password = "lims2023@";

#define FIREBASE_HOST "https://autoagro-70665-default-rtdb.firebaseio.com/GPS"
#define FIREBASE_AUTH "5Gc42Z2rgXY5qVdaV6DdGA8O0VckpKfsBmkJCgeu"


// INICIALIZAR CLIENTES
WiFiClient espClient;
FirebaseData dir;
FirebaseData firebaseData;

void setup_wifi(){
  delay(10);
  Serial.println("Conectando na WIFI");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWifi Conectado!");
  Serial.print("IP:");
  Serial.println(WiFi.localIP());
}

void setup(){
  Serial.begin(9600);
  setup_wifi();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  pinMode(ma1, OUTPUT);
  pinMode(ma2, OUTPUT);
  pinMode(mb1, OUTPUT);
  pinMode(mb2, OUTPUT);
}

void loop(){
  if (Firebase.getString(dir, "/dir")){
    Serial.println(dir.stringData());

    if (dir.stringData() == "0"){
      stop();
    }
    else if (dir.stringData() == "1"){
      go();
    }
    else if (dir.stringData() == "2"){
      back();
    }
    else if (dir.stringData() == "3"){
      left();
    }
    else if (dir.stringData() == "4"){
      right();
    }
  }
}
