#include "ThreatView.h"
#include <iostream>

// Display individual threat
void ThreatView::displayThreat(const Threat& threat) {
    std::cout << "ID: " << threat.getID() << ", Level: " << threat.getLevel()
        << ", Description: " << threat.getDescription()
        << ", Timestamp: " << threat.getTimestamp() << "\n";
}

// Display a list of threats
void ThreatView::displayThreats(const std::vector<Threat>& threats) {
    std::cout << "Threats:\n";
    for (const auto& threat : threats) {
        displayThreat(threat);
    }
}

// Display messages
void ThreatView::displayMessage(const std::string& message) {
    std::cout << message << "\n";
}

// Prompt for user input
std::string ThreatView::prompt(const std::string& message) {
    std::string input;
    std::cout << message;
    std::cin.ignore();
    std::getline(std::cin, input);
    return input;
}
