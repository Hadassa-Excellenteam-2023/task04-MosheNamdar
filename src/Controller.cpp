#include "Controller.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

Controller::Controller(const std::string& filename) {
    loadCities(filename);
}

void Controller::searchCities(const std::string& selectedCityName, double radius, int norm) {
    bool cityFound = false;
    City selectedCity;

    for (const City& city : cities) {
        if (city.getName() == selectedCityName) {
            selectedCity = city;
            cityFound = true;
            break;
        }
    }

    if (!cityFound) {
        std::cout << "ERROR: \"" << selectedCityName << "\" is not found in the city list. Please try again." << std::endl;
        return;
    }

    std::vector<City> citiesWithinRadius;

    for (const City& city : cities) {
        double distance = calculateDistance(selectedCity, city, norm);
        if (distance <= radius) {
            citiesWithinRadius.push_back(city);
        }
    }

    std::sort(citiesWithinRadius.begin(), citiesWithinRadius.end(), [&](const City& city1, const City& city2) {
        double distance1 = calculateDistance(selectedCity, city1, norm);
        double distance2 = calculateDistance(selectedCity, city2, norm);
        return distance1 < distance2;
        });

    std::cout << citiesWithinRadius.size() << " city/cities found in the given radius." << std::endl;

    int citiesToNorth = std::count_if(citiesWithinRadius.begin(), citiesWithinRadius.end(), [&](const City& city) {
        return city.getY() < selectedCity.getY();
        });

    std::cout << citiesToNorth << " cities are to the north of the selected city." << std::endl;

    std::cout << "City list:" << std::endl;
    for (const City& city : citiesWithinRadius) {
        std::cout << city.getName() << std::endl;
    }
}

double Controller::calculateDistance(const City& city1, const City& city2, int norm) {
    double dx = std::abs(city1.getX() - city2.getX());
    double dy = std::abs(city1.getY() - city2.getY());

    if (norm == 0) {
        return std::sqrt(dx * dx + dy * dy);
    }
    else if (norm == 1) {
        return std::max(dx, dy);
    }
    else if (norm == 2) {
        return dx + dy;
    }

    return 0.0;
}

void Controller::loadCities(const std::string& filename) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cout << "ERROR: Unable to open the input file." << std::endl;
        return;
    }

    std::string cityName;
    while (std::getline(inputFile, cityName)) {
        std::string coordinatesLine;
        std::getline(inputFile, coordinatesLine);

        double x, y;
        if (std::sscanf(coordinatesLine.c_str(), "%lf - %lf", &y, &x) == 2) {
            cities.push_back(City(cityName, x, y));
        }
        else {
            std::cout << "ERROR: Invalid coordinate format for city " << cityName << std::endl;
        }
    }

    inputFile.close();
}
