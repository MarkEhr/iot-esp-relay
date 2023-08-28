#include <WebSocketsClient.h>
#include "config.h"
#include "relayControl.h"

WebSocketsClient webSocket;
static Relay* relayInstance = nullptr;

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.println("[WSc] Disconnected!");
            break;
        
        case WStype_CONNECTED:
            Serial.printf("[WSc] Connected to server: %s\n", payload);
            webSocket.sendTXT("Connected");
            break;
        case WStype_TEXT:
            Serial.printf("[WSc] Received text: %s\n", payload);
            if (String((char *)payload) == "ON") {
                relayInstance->toggle(true);
            } else if (String((char *)payload) == "OFF") {
                relayInstance->toggle(false);
            }
            break;

        case WStype_BIN:
            Serial.println("[WSc] Received binary data");
            // Handle binary data if needed
            break;

        case WStype_PING:
            Serial.println("[WSc] Received ping");
            break;

        case WStype_PONG:
            Serial.println("[WSc] Received pong");
            break;

        default:
            Serial.printf("[WSc] Unhandled event type: %d\n", type);
            break;
    }
}


void setupWebSocketClient(Relay& relay) {
    relayInstance = &relay;

    // Set the server IP, port, URL, and protocol
    webSocket.begin(configuration.getWebSocketServerIP(), configuration.getWebSocketServerPort(), "/ws");
    webSocket.setReconnectInterval(5000); // Try to reconnect every 5 seconds if connection is lost

    
    uint32_t chipId = ESP.getChipId();
    char chipIdStr[10];
    sprintf(chipIdStr, "%08X", chipId); // Convert to a hex string

    String headers = 
    "X-Device-Id: " + String(chipIdStr) + "\r\n" +
    "X-Api-Key: " + configuration.getServerAPIKey();

    Serial.println("Connecting with headers: " + headers);

    webSocket.setExtraHeaders(headers.c_str());



    // Assign event handler
    webSocket.onEvent(webSocketEvent);

     // If using SSL, you might need something like:
    // webSocket.setCACert(rootCA);
}

void handleWebSocketClient() {
    webSocket.loop();
}
