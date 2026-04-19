#include "Field.h"
#include <cmath>
#include <stdexcept>

Field::Field() : value(new double[3]{0.0, 0.0, 0.0}) {}

Field::Field(double x, double y, double z) : value(new double[3]{x, y, z}) {}

Field::Field(const Field &other)
    : value(new double[3]{other.value[0], other.value[1], other.value[2]}) {}

Field &Field::operator=(const Field &other)
{
    if (this != &other)
    {
        value[0] = other.value[0];
        value[1] = other.value[1];
        value[2] = other.value[2];
    }
    return *this;
}

Field::~Field()
{
    delete[] value;
}

double Field::getComponent(int index) const
{
    if (index < 0 || index > 2)
        throw std::out_of_range("Index must be 0, 1, or 2");
    return value[index];
}

void Field::setComponent(int index, double v)
{
    if (index < 0 || index > 2)
        throw std::out_of_range("Index must be 0, 1, or 2");
    value[index] = v;
}

double Field::calculateMagnitude() const
{
    return std::sqrt(value[0] * value[0] + value[1] * value[1] + value[2] * value[2]);
}

void Field::printMagnitude() const
{
    std::cout << "Components: (" << value[0] << ", " << value[1] << ", " << value[2] << ")\n";
    std::cout << "Magnitude: " << calculateMagnitude() << '\n';
}
