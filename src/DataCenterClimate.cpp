// DataCenterClimate.cpp
#include "DataCenterClimate.hpp"
#include <sstream>

DataCenterClimate::DataCenterClimate(std::unique_ptr<INotifier> notifier,
                                     std::unique_ptr<IHistoryRepository> historyRepo,
                                     std::shared_ptr<Sensor> sensor)
    : notifier(std::move(notifier)),
      historyRepository(std::move(historyRepo)),
      sensor(sensor) {
    // Save the initial state when the system starts
    historyRepository->saveState(sensor->getTemperature(), sensor->getHumidity());
}

void DataCenterClimate::saveAndCheckAlerts() {
    float currentTemp = sensor->getTemperature();
    float currentHumidity = sensor->getHumidity();

    //Save state automatically after any change
    historyRepository->saveState(currentTemp, currentHumidity);

    //Check for alerts
    std::stringstream alertMessage;
    bool alert = false;

    if (currentTemp > maxTemp) {
        alertMessage << "HIGH TEMPERATURE! Current: " << currentTemp << "°C. Limit: " << maxTemp << "°C. ";
        alert = true;
    } else if (currentTemp < minTemp) {
        alertMessage << "LOW TEMPERATURE! Current: " << currentTemp << "°C. Limit: " << minTemp << "°C. ";
        alert = true;
    }

    if (currentHumidity > maxHumidity) {
        alertMessage << "HIGH HUMIDITY! Current: " << currentHumidity << "%. Limit: " << maxHumidity << "%. ";
        alert = true;
    } else if (currentHumidity < minHumidity) {
        alertMessage << "LOW HUMIDITY! Current: " << currentHumidity << "%. Limit: " << minHumidity << "%. ";
        alert = true;
    }

    if (alert) {
        notifier->notify(alertMessage.str());
    }
}

void DataCenterClimate::increaseTemperature() {
    sensor->increaseTemperature();
    saveAndCheckAlerts();
}

void DataCenterClimate::decreaseTemperature() {
    sensor->decreaseTemperature();
    saveAndCheckAlerts();
}

void DataCenterClimate::increaseHumidity() {
    sensor->increaseHumidity();
    saveAndCheckAlerts();
}

void DataCenterClimate::decreaseHumidity() {
    sensor->decreaseHumidity();
    saveAndCheckAlerts();
}

std::string DataCenterClimate::getCurrentState() const {
    std::stringstream ss;
    ss << "Current Temperature: " << sensor->getTemperature() << "°C\n"
       << "Current Humidity: " << sensor->getHumidity() << "%";
    return ss.str();
}//como funciona este ss?

std::string DataCenterClimate::getHistory() const {
    return historyRepository->getHistory();
}

void DataCenterClimate::sendManualAlert(const std::string& customMessage) {
    notifier->notify(customMessage);
}