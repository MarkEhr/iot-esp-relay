#pragma once

#include <Arduino.h>

class Config {
public:
    Config();

    // Getters
    uint8_t getRelayPin() const;
    String getWifiSSID() const;
    String getWifiPassword() const;
    String getWebSocketServerIP() const;
    uint16_t getWebSocketServerPort() const;
    String getServerAPIKey() const;

    // Setters
    void setRelayPin(uint8_t pin);
    void setWifiSSID(const String& ssid);
    void setWifiPassword(const String& password);
    void setWebSocketServerIP(const String& ip);
    void setWebSocketServerPort(uint16_t port);
    void setServerAPIKey(const String& apiKey);


private:
    uint8_t relayPin;
    String wifiSSID;
    String wifiPassword;
    String webSocketServerIP;
    uint16_t webSocketServerPort;
    String serverAPIKey;
};

extern Config configuration;
