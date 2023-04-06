/////////////////////////////////
//  CODE BY AUTOAGRO PROJECT   //
// THIS CODE MAKE A ESP SERVER //
// AND GET COMANDS BY HTTP UDP //
/////////////////////////////////

#include <motors.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;
String req; //String que armazena os dados recebidos pela rede.

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
void drift(){
    digitalWrite(ma1, LOW); 
    digitalWrite(ma2, HIGH); 
    digitalWrite(mb1, HIGH); 
    digitalWrite(mb2, LOW);
}

void setup()
{
    // Motors PINOUT
    pinMode(ma1, OUTPUT);
    pinMode(ma2, OUTPUT);
    pinMode(mb1, OUTPUT);
    pinMode(mb2, OUTPUT);

    // Cria Acess Point
    Serial.begin(115200);
    WiFi.mode(WIFI_AP); // Define o ESP como Acess Point.
    WiFi.softAP("AutoAgro", "admin2023");
    delay(2000);
    udp.begin(555); // Porta 555
    
    // Mostra IP do ESP
    Serial.println("");
    Serial.println("CONECTED...");
    Serial.print("IP: ");
    Serial.println(WiFi.softAPIP());
}

void loop()
{
    // Escuta Pacotes(dados) Recebidos
    if (udp.parsePacket() > 0)
    {
        req = "";
        while (udp.available() > 0)
        {
            char z = udp.read();
            req += z;
        }

        Serial.println(req);

        if (req == "GO"){go();}
        else if (req == "BACK"){back();}
        else if (req == "DRIFT"){drift();}
        else if (req == "STOP"){stop()};
        else if (req == "RIGHT"){right();}
        else if (req == "LEFT"){left();}
        else {stop();}
    }
}
