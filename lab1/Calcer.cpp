#include <cmath>
#include "Calcer.h"

double SimpsonIntegral::calc(double (*func)(double)) {
    double even = 0;
    double odd = 0;
    double result = 0;
    for (double x = LowerBound + 2*step; x<UpperBound;x += 2*step) even += func(x);
    for (double x = LowerBound+step; x<UpperBound; x+=2*step) odd += func(x);
    result = (step/3) * (func(LowerBound)+2*even+4*odd+func(UpperBound));
    return trunc(result / accuracy)*accuracy;
}

double TrapezoidIntegral::calc(double (*func)(double)) {
    double addition = 0;
    double result = 0;
    for (double x = LowerBound + step; x < UpperBound;x+=step) addition+=func(x);
    result = (step/2) * (func(LowerBound)+2*addition+func(UpperBound));
    return trunc(result / accuracy)*accuracy;
}
