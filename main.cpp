#include <iostream>
#include "Electric_Field.h"
#include "Magnetic_Field.h"

int main()
{
    Electric_Field e1(0.0, 1e5, 1e3);
    Magnetic_Field b1(0.02, 0.01, -0.03);

    std::cout << "Initial electric field:\n";
    e1.printMagnitude();

    std::cout << "\nInitial magnetic field:\n";
    b1.printMagnitude();

    double Ecalc = e1.calculateFromGaussLaw(2.5e-6, 0.12); // Q, r
    double Bcalc = b1.calculateFromAmpereLaw(15.0, 0.05);  // I, r

    std::cout << "\nGauss law result E: " << Ecalc << " N/C\n";
    std::cout << "Ampere law result B: " << Bcalc << " T\n";

    Electric_Field e2(1.0, 2.0, 3.0), e3(4.0, 5.0, 6.0), eSum;
    eSum = e2 + e3;

    Magnetic_Field b2(0.1, 0.2, 0.3), b3(0.4, 0.5, 0.6), bSum;
    bSum = b2 + b3;

    std::cout << "\nOperator + demo:\n";
    std::cout << "e2 + e3 = " << eSum << '\n';
    std::cout << "b2 + b3 = " << bSum << '\n';

    std::cout << "\nOperator << demo:\n";
    std::cout << e1 << '\n';
    std::cout << b1 << '\n';

    return 0;
}
