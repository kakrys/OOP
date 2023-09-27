#pragma once
#include <iostream>
#include <cmath>

class AbstractCalcer
{
public:
    virtual double calc(double func(double )) = 0;
    AbstractCalcer(double LowerBound,double Upperbound,double step,double accuracy)
    :LowerBound(LowerBound),UpperBound(Upperbound),step(step),accuracy(accuracy) {}

protected:
    double LowerBound;
    double UpperBound;
    double step;
    double accuracy;
};

class SimpsonIntegral : public AbstractCalcer
{
public:
    double calc(double func(double )) override;
    SimpsonIntegral(double Lowerbound, double Upperbound,double step,double accuracy): AbstractCalcer(Lowerbound,Upperbound,step,accuracy){}
};

class TrapezoidIntegral : public AbstractCalcer
{

public:
    TrapezoidIntegral(double  Lowerbound, double Upperbound,double step,double accuracy): AbstractCalcer(Lowerbound,Upperbound,step,accuracy){}

    double calc(double func(double )) override;
};