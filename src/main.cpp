#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "config.h"
#include "relayControl.h"
#include "webSocketClient.h"

const char* WIFI_SSID = "TIDE";
const char* WIFI_PASSWORD = "eltideano";

Relay* doorRelay;

void setup() {
    Serial.begin(115200);

    doorRelay = new Relay(configuration.getRelayPin());

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi!");

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    doorRelay->setup();
    setupWebSocketClient(*doorRelay);
}

void loop() {

  handleWebSocketClient();
  doorRelay->loop();

}
