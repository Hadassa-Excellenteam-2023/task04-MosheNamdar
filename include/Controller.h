#pragma once



#include <string>
#include <vector>

#include "City.h"

class Controller {
public:
    Controller(const std::string& filename);

    void searchCities(const std::string& selectedCityName, double radius, int norm);

private:
    std::vector<City> cities;

    double calculateDistance(const City& city1, const City& city2, int norm);
    void loadCities(const std::string& filename);
};

