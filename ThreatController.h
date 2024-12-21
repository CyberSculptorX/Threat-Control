#pragma once
#pragma once
#include <vector>
#include "Threat.h"
#include "ThreatView.h"

class ThreatController {
private:
    std::vector<Threat> threats;
    ThreatView view;

    int findThreatIndexByID(const std::string& id);

public:
    ThreatController();

    void logThreat();
    void viewAllThreats();
    void filterThreats();
    void updateThreat();
    void removeThreat();
    void saveThreatsToFile(const std::string& filename);
    void loadThreatsFromFile(const std::string& filename);
};
