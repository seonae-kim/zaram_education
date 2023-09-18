#include <stdio.h>


struct complex
{
	double real;
	double image;
};

typedef struct complex complex;

int main(void)
{
	complex one;

	printf("input real and image: ex) (5 4i) ");
	scanf("%lf %lf", &one.real, &one.image);

	printf("real is %f and image is %f", one.real, one.image);

}
