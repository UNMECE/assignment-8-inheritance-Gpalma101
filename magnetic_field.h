#ifndef MAGNETIC_FIELD_H
#define MAGNETIC_FIELD_H

#include "Field.h"

class Magnetic_Field : public Field
{
private:
    double calculatedMagneticField;

public:
    Magnetic_Field();
    Magnetic_Field(double x, double y, double z);
    Magnetic_Field(const Magnetic_Field &other);
    Magnetic_Field &operator=(const Magnetic_Field &other);
    ~Magnetic_Field() override;

    double calculateFromAmpereLaw(double I, double r);
    double getCalculatedMagneticField() const;

    Magnetic_Field operator+(const Magnetic_Field &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const Magnetic_Field &b);
};

#endif
