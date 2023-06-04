#include "City.h"

City::City(const std::string& name, double x, double y)
    : name(name), x(x), y(y) {}

City::City()
{
    name = "";
    x = 0;
    y = 0;
}

std::string City::getName() const {
    return name;
}

double City::getX() const {
    return x;
}

double City::getY() const {
    return y;
}
