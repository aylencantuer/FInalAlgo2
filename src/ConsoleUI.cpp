// ConsoleUI.cpp
#include "ConsoleUI.hpp"
#include <iostream>
#include <string>
#include <limits>

ConsoleUI::ConsoleUI(DataCenterClimate* controller) : climateControl(controller) {}

void ConsoleUI::showMenu() const {
    std::cout << "\n--- Data Center Climate Control ---" << std::endl;
    std::cout << "1. Increase Temperature" << std::endl;
    std::cout << "2. Decrease Temperature" << std::endl;
    std::cout << "3. Increase Humidity" << std::endl;
    std::cout << "4. Decrease Humidity" << std::endl;
    std::cout << "5. Show Current State" << std::endl;
    std::cout << "6. Show History" << std::endl;
    std::cout << "7. Send Manual Email Alert" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

int ConsoleUI::getUserChoice() const {
    int choice;
    std::cin >> choice;
    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter your choice: ";
        std::cin >> choice;
    }
    // Clear the rest of the line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

void ConsoleUI::processChoice(int choice) {
    switch (choice) {
        case 1:
            climateControl->increaseTemperature();
            std::cout << "Temperature increased." << std::endl;
            break;
        case 2:
            climateControl->decreaseTemperature();
            std::cout << "Temperature decreased." << std::endl;
            break;
        case 3:
            climateControl->increaseHumidity();
            std::cout << "Humidity increased." << std::endl;
            break;
        case 4:
            climateControl->decreaseHumidity();
            std::cout << "Humidity decreased." << std::endl;
            break;
        case 5:
            std::cout << "\n--- Current State ---" << std::endl;
            std::cout << climateControl->getCurrentState() << std::endl;
            break;
        case 6:
            std::cout << "\n--- Climate History ---" << std::endl;
            std::cout << climateControl->getHistory() << std::endl;
            break;
        case 7: {
            std::cout << "Enter an alert message: ";
            std::string message;
            std::getline(std::cin, message);
            climateControl->sendManualAlert(message);
            std::cout << "Manual alert sent." << std::endl;
            break;
        }
        case 8:
            std::cout << "Exiting application." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
    }
}

void ConsoleUI::run() {
    int choice = 0;
    while (choice != 8) {
        showMenu();
        choice = getUserChoice();
        processChoice(choice);
    }
}