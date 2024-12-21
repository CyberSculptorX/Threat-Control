#include <iostream>
#include "ThreatController.h"

void displayMenu() {
    std::cout << "\nThreat Management System\n";
    std::cout << "1. Log New Threat\n";
    std::cout << "2. View All Threats\n";
    std::cout << "3. Filter Threats by Level\n";
    std::cout << "4. Update Threat Information\n";
    std::cout << "5. Remove a Threat\n";
    std::cout << "6. Save Threats to File\n";
    std::cout << "7. Load Threats from File\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    ThreatController controller;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: controller.logThreat(); break;
        case 2: controller.viewAllThreats(); break;
        case 3: controller.filterThreats(); break;
        case 4: controller.updateThreat(); break;
        case 5: controller.removeThreat(); break;
        case 6: controller.saveThreatsToFile("threats.txt"); break;
        case 7: controller.loadThreatsFromFile("threats.txt"); break;
        case 8: std::cout << "Exiting program.\n"; break;
        default: std::cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 8);

    return 0;
}
