#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int sumTwo(int a, int b);		//함수 선언

int main()
{
	int x = 10, y = 5;
	int value;

	value = SumTwo(x, y);		//함수 호출

	printf("두 수의 합 : %d\n", value);


}

int SumTwo(int a, int b)		//함수 정의
{
	int result;
	result = a + b;
	return result;
}