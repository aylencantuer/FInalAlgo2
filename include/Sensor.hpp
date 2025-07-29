// Sensor.h
#ifndef SENSOR_HPP
#define SENSOR_HPP

class Sensor {
private:
    float temperature;
    float humidity;

public:
    Sensor(float initialTemp, float initialHumidity);

    float getTemperature() const;
    float getHumidity() const;

    void increaseTemperature();
    void decreaseTemperature();
    void increaseHumidity();
    void decreaseHumidity();
};

#endif // SENSOR_H
