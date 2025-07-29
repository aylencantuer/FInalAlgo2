// Sensor.cpp
#include "Sensor.hpp"

Sensor::Sensor(float initialTemp, float initialHumidity)
    : temperature(initialTemp), humidity(initialHumidity) {}

float Sensor::getTemperature() const {
    return temperature;
}

float Sensor::getHumidity() const {
    return humidity;
}

void Sensor::increaseTemperature() {
    temperature += 1.0f;
}

void Sensor::decreaseTemperature() {
    temperature -= 1.0f;
}

void Sensor::increaseHumidity() {
    humidity += 1.0f;
}

void Sensor::decreaseHumidity() {
    humidity -= 1.0f;
}

