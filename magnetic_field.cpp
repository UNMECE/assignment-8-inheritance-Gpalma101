#include "Magnetic_Field.h"
#include <stdexcept>

Magnetic_Field::Magnetic_Field() : Field(), calculatedMagneticField(0.0) {}

Magnetic_Field::Magnetic_Field(double x, double y, double z)
    : Field(x, y, z), calculatedMagneticField(0.0) {}

Magnetic_Field::Magnetic_Field(const Magnetic_Field &other)
    : Field(other), calculatedMagneticField(other.calculatedMagneticField) {}

Magnetic_Field &Magnetic_Field::operator=(const Magnetic_Field &other)
{
    if (this != &other)
    {
        Field::operator=(other);
        calculatedMagneticField = other.calculatedMagneticField;
    }
    return *this;
}

Magnetic_Field::~Magnetic_Field() = default;

double Magnetic_Field::calculateFromAmpereLaw(double I, double r)
{
    constexpr double PI = 3.14159265358979323846;
    constexpr double MU0 = 4.0 * PI * 1e-7;

    if (r <= 0.0)
        throw std::invalid_argument("r must be > 0");

    calculatedMagneticField = (MU0 * I) / (2.0 * PI * r);
    return calculatedMagneticField;
}

double Magnetic_Field::getCalculatedMagneticField() const
{
    return calculatedMagneticField;
}

Magnetic_Field Magnetic_Field::operator+(const Magnetic_Field &rhs) const
{
    return Magnetic_Field(
        value[0] + rhs.value[0],
        value[1] + rhs.value[1],
        value[2] + rhs.value[2]);
}

std::ostream &operator<<(std::ostream &os, const Magnetic_Field &b)
{
    os << "Magnetic_Field(" << b.value[0] << ", " << b.value[1] << ", " << b.value[2] << ")";
    return os;
}
