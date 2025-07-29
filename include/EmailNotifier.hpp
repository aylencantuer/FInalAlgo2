// EmailNotifier.h
#ifndef EMAILNOTIFIER_HPP
#define EMAILNOTIFIER_HPP

#include "INotifier.hpp"
#include <iostream>

// Concrete implementation for sending email notifications (mocked).
class EmailNotifier : public INotifier {
public:
    void notify(const std::string& message) override;
};

#endif // EMAILNOTIFIER_H
