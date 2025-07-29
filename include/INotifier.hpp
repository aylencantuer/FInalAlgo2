// INotifier.h
// Interface for any notification mechanism.
// This follows the Interface Segregation Principle and Dependency Inversion Principle.
#ifndef INOTIFIER_HPP
#define INOTIFIER_HPP

#include <string>

class INotifier {
public:
    virtual ~INotifier() = default;
    virtual void notify(const std::string& message) = 0;
};

#endif // INOTIFIER_H