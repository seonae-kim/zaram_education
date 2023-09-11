#include <stdio.h>

float Average(float x, float y);		//함수 선언

int main()
{
	float num1, num2, result;
	printf("실수 2개를 입력하세요 : ");
	scanf_s("%f %f", &num1, &num2);


	result = Average(num1, num2);		//함수 호출

	printf("두 실수의 평균 : %f\n", result);
}

float Average(float x, float y)			//함수 정의
{
	float z;
	z = (x + y) / 2;
	return z;
}