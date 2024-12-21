#pragma once
#include <vector>
#include <string>
#include "Threat.h"

class ThreatView {
public:
    void displayThreat(const Threat& threat);
    void displayThreats(const std::vector<Threat>& threats);
    void displayMessage(const std::string& message);
    std::string prompt(const std::string& message);
};
