// FileHistoryRepository.cpp
#include "FileHistoryRepository.hpp"
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip> // for put_time

// Helper to get current timestamp
std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

FileHistoryRepository::FileHistoryRepository(const std::string& path) : filePath(path) {}

void FileHistoryRepository::write(const std::string& content) {
    // 'app' mode appends to the file. If the file doesn't exist, it's created.
    std::ofstream outFile(filePath, std::ios_base::app);
    if (outFile.is_open()) {
        outFile << content << std::endl;
    }
    else {
        throw std::runtime_error("Could not open file for writing: " + filePath);
    }
}

void FileHistoryRepository::saveState(float temperature, float humidity) {
    std::stringstream ss;
    ss << "[" << getCurrentTimestamp() << "] "
       << "State saved - Temp: " << temperature << "°C, "
       << "Humidity: " << humidity << "%";
    write(ss.str());
}

std::string FileHistoryRepository::getHistory() {
    std::ifstream inFile(filePath);
    if (inFile.is_open()) {
        std::stringstream buffer;
        buffer << inFile.rdbuf();
        return buffer.str();
    }
    return "No history found or file could not be opened.";
}
