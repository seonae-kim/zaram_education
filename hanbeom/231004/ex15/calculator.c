#include "calculator.h"

double sum(double a, double b)
{
    return a + b;
}

double minus(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b != 0)
    {
        return a / b;
    }
}