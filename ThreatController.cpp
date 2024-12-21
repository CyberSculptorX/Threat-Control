#include "ThreatController.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

// Constructor
ThreatController::ThreatController() {}

// Helper: Find the index of a threat by ID
int ThreatController::findThreatIndexByID(const std::string& id) {
    for (size_t i = 0; i < threats.size(); ++i) {
        if (threats[i].getID() == id) return i;
    }
    return -1;
}

// Log a new threat
void ThreatController::logThreat() {
    std::string id = view.prompt("Enter Threat ID: ");
    std::string level = view.prompt("Enter Threat Level (Low, Medium, High, Critical): ");
    std::string description = view.prompt("Enter Threat Description: ");

    // Generate timestamp
    time_t now = time(nullptr);
    char buffer[26]; // Buffer to store the timestamp
    ctime_s(buffer, sizeof(buffer), &now); // Safe alternative to ctime
    std::string timestamp(buffer);
    timestamp.pop_back(); // Remove newline character

    threats.emplace_back(id, level, description, timestamp);
    view.displayMessage("Threat logged successfully.");
}

// View all threats
void ThreatController::viewAllThreats() {
    view.displayThreats(threats);
}

// Filter threats by level
void ThreatController::filterThreats() {
    std::string level = view.prompt("Enter Threat Level to filter by: ");
    std::vector<Threat> filtered;

    for (const auto& threat : threats) {
        if (threat.getLevel() == level) {
            filtered.push_back(threat);
        }
    }

    view.displayThreats(filtered);
}

// Update a threat
void ThreatController::updateThreat() {
    std::string id = view.prompt("Enter Threat ID to update: ");
    int index = findThreatIndexByID(id);

    if (index == -1) {
        view.displayMessage("Threat not found.");
        return;
    }

    std::string newLevel = view.prompt("Enter new Threat Level: ");
    std::string newDescription = view.prompt("Enter new Threat Description: ");

    threats[index].setLevel(newLevel);
    threats[index].setDescription(newDescription);

    view.displayMessage("Threat updated successfully.");
}

// Remove a threat
void ThreatController::removeThreat() {
    std::string id = view.prompt("Enter Threat ID to remove: ");
    int index = findThreatIndexByID(id);

    if (index == -1) {
        view.displayMessage("Threat not found.");
        return;
    }

    threats.erase(threats.begin() + index);
    view.displayMessage("Threat removed successfully.");
}

// Save threats to a file
void ThreatController::saveThreatsToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        view.displayMessage("Error saving threats to file.");
        return;
    }

    for (const auto& threat : threats) {
        file << threat.getID() << "," << threat.getLevel() << ","
            << threat.getDescription() << "," << threat.getTimestamp() << "\n";
    }

    view.displayMessage("Threats saved successfully.");
}

// Load threats from a file
void ThreatController::loadThreatsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        view.displayMessage("Error loading threats from file.");
        return;
    }

    threats.clear();
    std::string line, id, level, description, timestamp;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, id, ',');
        std::getline(ss, level, ',');
        std::getline(ss, description, ',');
        std::getline(ss, timestamp, ',');

        threats.emplace_back(id, level, description, timestamp);
    }

    view.displayMessage("Threats loaded successfully.");
}
