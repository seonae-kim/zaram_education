#include <stdio.h>

struct circle
{
	int x;
	int y;
	int r;
};

typedef struct circle circle;

int CheckCircumcircle(circle a, circle b)
{
	if( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) == (a.r + b.r) * (a.r + b.r) )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main(void)
{
	circle one, two ;

	printf("input x, y, r: ex) (4 3 5) ");
	scanf("%d %d %d", &one.x, &one.y, &one.r);
	printf("x is %d and y is %d and r is %d\n", one.x, one.y, one.r);
	
	printf("input x, y, r: ex) (4 3 5) ");
	scanf("%d %d %d", &two.x, &two.y, &two.r);		
	printf("x is %d and y is %d and r is %d\n", two.x, two.y, two.r);
	
	CheckCircumcircle(one, two);
	
	if(CheckCircumcircle(one, two) == 1)
	{
		printf("result : 1");
	}
	else if (CheckCircumcircle(one, two) == 0)
	{
		printf("result : 0");
	}
}
