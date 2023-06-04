#include "Controller.h"
#include <iostream>
#include <limits>

int main() {
    Controller controller("data.txt");

    std::cout << "Please enter selected city name (with line break after it):" << std::endl;
    std::string selectedCityName;
    std::getline(std::cin, selectedCityName);

    while (selectedCityName != "0") {
        std::cout << "Please enter the desired radius:" << std::endl;
        double radius;
        std::cin >> radius;

        if (radius < 0) {
            std::cout << "ERROR: Invalid radius. Please enter a positive value." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Please enter the desired norm (0 - L2, 1 - Linf, 2 - L1):" << std::endl;
        int norm;
        std::cin >> norm;

        if (norm < 0 || norm > 2) {
            std::cout << "ERROR: Invalid norm. Please enter a number between 0 and 2." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        controller.searchCities(selectedCityName, radius, norm);

        std::cout << "Please enter selected city name (with line break after it):" << std::endl;
        std::getline(std::cin, selectedCityName);
    }

    std::cout << "Bye" << std::endl;

    return 0;
}
