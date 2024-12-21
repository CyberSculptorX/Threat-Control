#include "Threat.h"

// Constructor
Threat::Threat(const std::string& id, const std::string& level, const std::string& description, const std::string& timestamp)
    : id(id), level(level), description(description), timestamp(timestamp) {
}

// Getters
std::string Threat::getID() const { return id; }
std::string Threat::getLevel() const { return level; }
std::string Threat::getDescription() const { return description; }
std::string Threat::getTimestamp() const { return timestamp; }

// Setters
void Threat::setLevel(const std::string& newLevel) { level = newLevel; }
void Threat::setDescription(const std::string& newDescription) { description = newDescription; }
