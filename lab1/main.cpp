
#include "Calcer.h"


double f (double x) {
    return pow(x,5);
}
int main() {
    SimpsonIntegral Simpson (0,1,0.01,0.0001);
    double result = Simpson.calc(f);
    std::cout << "Simpson " << result << std::endl;
    TrapezoidIntegral Trapezoid (0,1,0.01,0.00001);
    result = Trapezoid.calc(f);
    std::cout << "Trapezoid " << result << std::endl;
}
