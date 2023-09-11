#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int a[4] = { 10, 20, 30, 40 };
	int i, aryLength;

	aryLength = sizeof(a) / sizeof(int);		//sizeof(a) = 배열 a의 전체 바이트수, sizeof(int) = 배열 a형의 자료형의 바이트수
												//aryLength = 배열의 원소 개수
	printf("배열의 원소값을 출력하면 \n");
	for (i = 0; i < aryLength; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}

	printf("배열 원소의 주소를 출력하면 \n");
	for (i = 0; i < aryLength; i++)
	{
		printf("a[%d] = %p\n", i, a[i]);			//주소라서 %p
	}
	
}