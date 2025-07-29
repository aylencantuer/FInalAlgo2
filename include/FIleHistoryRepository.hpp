// FileHistoryRepository.h
#ifndef FILEHISTORYREPOSITORY_HPP
#define FILEHISTORYREPOSITORY_HPP

#include "IHistoryRepository.hpp"
#include <string>

// Concrete implementation for saving history to a file.
class FileHistoryRepository : public IHistoryRepository {
private:
    std::string filePath;
    void write(const std::string& content);

public:
    explicit FileHistoryRepository(const std::string& path);
    void saveState(float temperature, float humidity) override;
    std::string getHistory() override;
};

#endif // FILEHISTORYREPOSITORY_H
