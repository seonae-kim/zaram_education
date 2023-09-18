#include <stdio.h>

struct circle
{
	int x;
	int y;
	int r;
};

typedef struct circle circle;


int main(void)
{
	circle one;

	printf("input x, y, r: ex) (4 3 5) ");
	scanf("%d %d %d", &one.x, &one.y, &one.r);
		
	printf("x is %d and y is %d and r is %d", one.x, one.y, one.r);
}
