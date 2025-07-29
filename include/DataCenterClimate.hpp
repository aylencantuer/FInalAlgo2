// DataCenterClimate.h
#ifndef DATACENTERCLIMATE_HPP
#define DATACENTERCLIMATE_HPP

#include "INotifier.hpp"
#include "IHistoryRepository.hpp"
#include "Sensor.hpp"
#include <string>
#include <memory>

// This is the main orchestrator class. It doesn't know about files or emails,
// only about the interfaces. This makes it highly decoupled.
class DataCenterClimate {
private:
    const float maxTemp = 27.0f;
    const float minTemp = 16.0f;
    const float maxHumidity = 60.0f;
    const float minHumidity = 40.0f;

    std::unique_ptr<INotifier> notifier;
    std::unique_ptr<IHistoryRepository> historyRepository;
    std::shared_ptr<Sensor> sensor;

    void saveAndCheckAlerts();

public:
    DataCenterClimate(std::unique_ptr<INotifier> notifier,
                      std::unique_ptr<IHistoryRepository> historyRepo,
                      std::shared_ptr<Sensor> sensor);

    void increaseTemperature();
    void decreaseTemperature();
    void increaseHumidity();
    void decreaseHumidity();
    
    std::string getCurrentState() const;
    std::string getHistory() const;
    void sendManualAlert(const std::string& customMessage);
};

#endif // DATACENTERCLIMATE_H