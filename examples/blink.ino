#include <Arduino_BuiltIn.h>;

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Piscando");
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Apagando");
    delay(1000);
}