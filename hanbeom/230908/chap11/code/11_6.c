#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct ThreeDime
{
	double x;
	double y;
	double z;
};

typedef struct ThreeDime ThreeDime;

int main()
{
	ThreeDime A1 = { 3, 1, 8 };

	ThreeDime* pA1 = &A1;	//A1은 배열이 아니라 구조체므로, = A1은 안 됨

	printf("3차원 점 A1의 x: %.2lf, y: %.2lf, z : %.2lf 이다. \n", pA1->x, pA1->y, pA1->z);

	return 0;
}