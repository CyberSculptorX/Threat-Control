#pragma once
#include <string>

class Threat {
private:
    std::string id;
    std::string level;
    std::string description;
    std::string timestamp;

public:
    // Constructor
    Threat(const std::string& id, const std::string& level, const std::string& description, const std::string& timestamp);

    // Getters
    std::string getID() const;
    std::string getLevel() const;
    std::string getDescription() const;
    std::string getTimestamp() const;

    // Setters
    void setLevel(const std::string& newLevel);
    void setDescription(const std::string& newDescription);
};
