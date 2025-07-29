// EmailNotifier.cpp
#include "EmailNotifier.hpp"
#include <iostream>

void EmailNotifier::notify(const std::string& message) {
    // In a real application, this would use an email library to send an email.
    // For this mock, we just print to the console.
    std::cout << "\n--- MOCK EMAIL ALERT ---" << std::endl;
    std::cout << "To: x@datacenter.com" << std::endl;
    std::cout << "Subject: Data Center Climate Alert" << std::endl;
    std::cout << "Body: " << message << std::endl;
    std::cout << "------------------------\n" << std::endl;
}
