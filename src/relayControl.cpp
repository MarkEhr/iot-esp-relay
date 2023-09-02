#include "relayControl.h"
#include <Arduino.h>

Relay::Relay(int pin) : pin_(pin), isOn_(false), activatedTime_(0) {}

byte ON_STATE = HIGH;

void Relay::setup() {
    pinMode(pin_, OUTPUT);
    digitalWrite(pin_, !ON_STATE);  // Initial state
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);  // Initial state
}

void Relay::toggle(bool state) {
    digitalWrite(pin_, state ? ON_STATE : !ON_STATE);
    digitalWrite(LED_BUILTIN, state ? LOW : HIGH);
    if (state) {
        activatedTime_ = millis();
        isOn_ = true;
    } else {
        isOn_ = false;
    }
}

void Relay::loop() {
    if (isOn_ && (millis() - activatedTime_ > duration_)) {
        Serial.printf("Turning off relay on pin %d\n", pin_); // Debug
        toggle(false); // Turn off after duration
    }
}
