#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	double b[] = { 2.3 ,3.0, 4.1, 5.5 };
	int a[4] = { 10, 20, 30, 40 };
	int i, aryLenDouble, aryLenInt;

	aryLenDouble = sizeof(b) / sizeof(double);
	aryLenInt = sizeof(a) / sizeof(int);

	printf("double형 배열 원소의 주소를 출력하면\n");

	for (i = 0; i < aryLenDouble; i++)
	{
		printf("b +%d =%p \n", i, b + i);				// b, b+1, b+2, b+3 주소 출력 = 각각 &b[0], &b[1], &b[2], &b[3] 의미.
	}		

	printf("int형 배열 원소의 주소를 출력하면\n");

	for (i = 0; i < aryLenDouble; i++)
	{
		printf("a + %d =%p \n", i, a + i);				// a, a+1, a+2, a+3 주소 출력 = 각각 &a[0], &a[1], &a[2], &a[3] 의미.
	}
	return 0;
}