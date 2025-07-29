// IHistoryRepository.h
// Interface for any history persistence mechanism.
#ifndef IHISTORYREPOSITORY_HPP
#define IHISTORYREPOSITORY_HPP

#include <string>

class IHistoryRepository {
public:
    virtual ~IHistoryRepository() = default;
    virtual void saveState(float temperature, float humidity) = 0;
    virtual std::string getHistory() = 0;
};

#endif // IHISTORYREPOSITORY_H

