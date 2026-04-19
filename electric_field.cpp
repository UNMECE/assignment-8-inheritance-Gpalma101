#include "Electric_Field.h"
#include <stdexcept>

Electric_Field::Electric_Field() : Field(), calculatedElectricField(0.0) {}

Electric_Field::Electric_Field(double x, double y, double z)
    : Field(x, y, z), calculatedElectricField(0.0) {}

Electric_Field::Electric_Field(const Electric_Field &other)
    : Field(other), calculatedElectricField(other.calculatedElectricField) {}

Electric_Field &Electric_Field::operator=(const Electric_Field &other)
{
    if (this != &other)
    {
        Field::operator=(other);
        calculatedElectricField = other.calculatedElectricField;
    }
    return *this;
}

Electric_Field::~Electric_Field() = default;

double Electric_Field::calculateFromGaussLaw(double Q, double r)
{
    constexpr double PI = 3.14159265358979323846;
    constexpr double EPSILON0 = 8.854187817e-12;

    if (r <= 0.0)
        throw std::invalid_argument("r must be > 0");

    calculatedElectricField = Q / (4.0 * PI * r * r * EPSILON0);
    return calculatedElectricField;
}

double Electric_Field::getCalculatedElectricField() const
{
    return calculatedElectricField;
}

Electric_Field Electric_Field::operator+(const Electric_Field &rhs) const
{
    return Electric_Field(
        value[0] + rhs.value[0],
        value[1] + rhs.value[1],
        value[2] + rhs.value[2]);
}

std::ostream &operator<<(std::ostream &os, const Electric_Field &e)
{
    os << "Electric_Field(" << e.value[0] << ", " << e.value[1] << ", " << e.value[2] << ")";
    return os;
}
