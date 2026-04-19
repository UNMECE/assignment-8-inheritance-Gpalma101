#ifndef ELECTRIC_FIELD_H
#define ELECTRIC_FIELD_H

#include "Field.h"

class Electric_Field : public Field
{
private:
    double calculatedElectricField;

public:
    Electric_Field();
    Electric_Field(double x, double y, double z);
    Electric_Field(const Electric_Field &other);
    Electric_Field &operator=(const Electric_Field &other);
    ~Electric_Field() override;

    double calculateFromGaussLaw(double Q, double r);
    double getCalculatedElectricField() const;

    Electric_Field operator+(const Electric_Field &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const Electric_Field &e);
};

#endif
