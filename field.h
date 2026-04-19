#ifndef FIELD_H
#define FIELD_H

#include <iostream>

class Field
{
protected:
    double *value;

public:
    Field();
    Field(double x, double y, double z);
    Field(const Field &other);
    Field &operator=(const Field &other);
    virtual ~Field();

    double getComponent(int index) const;
    void setComponent(int index, double v);

    double calculateMagnitude() const;
    virtual void printMagnitude() const;
};

#endif
