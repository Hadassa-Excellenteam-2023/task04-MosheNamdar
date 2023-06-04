#pragma once

#include <string>

class City {
public:
    City(const std::string& name, double x, double y);
    City();

    std::string getName() const;
    double getX() const;
    double getY() const;

private:
    std::string name;
    double x;
    double y;
};


