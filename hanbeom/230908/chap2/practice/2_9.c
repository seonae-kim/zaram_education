#define PIE 3.14
#include <stdio.h>

int main()
{
    double r = 0;
    double result = 0;

    printf("반지름을 입력하시오: ");

    scanf_s("%lf", &r);
    result = r * r * PIE;
    


    printf("원의 넓이는: %lf", result);
}