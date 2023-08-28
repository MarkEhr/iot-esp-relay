#pragma once

class Relay {
public:
    Relay(int pin);
    void setup();
    void toggle(bool state);
    void loop(); // This method will handle auto-off after a certain duration
private:
    int pin_;
    bool isOn_;
    unsigned long activatedTime_;
    const unsigned long duration_ = 5000; // 5 seconds
};

