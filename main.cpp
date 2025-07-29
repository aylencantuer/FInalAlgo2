#include <iostream>
#include <memory>
#include "ConsoleUI.hpp"
#include "DataCenterClimate.hpp"
#include "EmailNotifier.hpp"
#include "FileHistoryRepository.hpp"
#include "Sensor.hpp"

int main() {
    // Here we create the concrete instances that our application will use.
    // This is the power of the Dependency Inversion Principle. because we can easily swap out implementations.
    // For example, we could use a different notifier or history repository without changing the main logic of the application.


    auto sensor = std::make_shared<Sensor>(22.0f, 45.0f); // Initial state
    auto notifier = std::make_unique<EmailNotifier>();
    auto historyRepository = std::make_unique<FileHistoryRepository>("climate_history.log");

    // The main controller class receives the dependencies through its constructor.
    auto climateControl = std::make_unique<DataCenterClimate>(
        std::move(notifier),
        std::move(historyRepository),//move?
        sensor
    );

    // The UI class gets a reference to the controller to interact with it.
    ConsoleUI ui(climateControl.get());

    // Start the main application loop.
    ui.run();

    return 0;
}