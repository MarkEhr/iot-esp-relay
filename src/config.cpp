#include "config.h"


Config::Config() {
    // For now, these are hardcoded. Later, you might read them from EEPROM or another storage.
    relayPin = D0;
    wifiSSID = "tide";
    wifiPassword = "eltideano";
    webSocketServerIP = "72.167.222.190";
    webSocketServerPort = 44000;
    serverAPIKey = "+d!k~XB9yp-crxAn=cCGr$-n";
}

// Getters
uint8_t Config::getRelayPin() const {
    return relayPin;
}

String Config::getWifiSSID() const {
    return wifiSSID;
}

String Config::getWifiPassword() const {
    return wifiPassword;
}

String Config::getWebSocketServerIP() const {
    return webSocketServerIP;
}

uint16_t Config::getWebSocketServerPort() const {
    return webSocketServerPort;
}

String Config::getServerAPIKey() const {
    return serverAPIKey;
}

// Setters
void Config::setRelayPin(uint8_t relayPin) {
    // Placeholder logic.
}
void Config::setWifiSSID(const String& ssid) {
    // For now, this is a placeholder.
    // Later, you can implement logic to save the new SSID to EEPROM or other storage.
}

void Config::setWifiPassword(const String& password) {
    // Placeholder logic.
}

void Config::setWebSocketServerIP(const String& ip) {
    // Placeholder logic.
}

void Config::setWebSocketServerPort(uint16_t port) {
    // Placeholder logic.
}

void Config::setServerAPIKey(const String& apiKey) {
    // Placeholder logic.
}

Config configuration = Config();