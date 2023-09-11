#include <stdio.h>

int SumTwo(int a, int b)			// 특정 함수를 main함수보다 먼저 정의하면, 함수 선언은 안해도 됨
{
	int result;
	result = a + b;

	return result;
}

int main()							// main함수 정의
{
	int x = 10, y = 5;
	int value;

	value = SumTwo(x, y);

	printf("두 수의 합 : %d\n", value);
	return 0;
}