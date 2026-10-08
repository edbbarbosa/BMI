#include "bmi.h"
#include <cmath>

Bmi::Bmi(double height, double weight)
{
    bmi = weight / pow((height/100), 2);
}

double Bmi::getBmi()
{
    return bmi;
}
