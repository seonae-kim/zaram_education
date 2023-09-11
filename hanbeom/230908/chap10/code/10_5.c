#include <stdio.h>

void CountIncrement1(int n);
void CountIncrement2(int* n);

int main(void)
{
	int a = 10;
	int n = 0;
	printf("a의 초깃값 : %d\n", a);

	CountIncrement1(a);
	printf("CountIncrement1 함수 실행 후 a의 값 : %d\n", a);			//포인터 x (값 안변함)
	
	CountIncrement2(&a);
	printf("CountIncrement2 함수 실행 후 a의 값 : %d\n", a);			//포인터 o (값 변함)
}

void CountIncrement1(int n)
{
	n++;
}

void CountIncrement2(int* n)
{
	(*n)++;
}