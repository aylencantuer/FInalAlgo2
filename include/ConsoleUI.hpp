// ConsoleUI.h
#ifndef CONSOLEUI_HPP
#define CONSOLEUI_HPP

#include "DataCenterClimate.hpp"

// This class is responsible for all user interaction.
// It follows the Single Responsibility Principle. Its only job is to
// interact with the user and delegate actions to the DataCenterClimate class.
class ConsoleUI {
private:
    DataCenterClimate* climateControl; // Using a raw pointer because the UI doesn't own the object

    void showMenu() const;
    int getUserChoice() const;
    void processChoice(int choice);

public:
    explicit ConsoleUI(DataCenterClimate* controller);
    void run();
};

#endif // CONSOLEUI_H