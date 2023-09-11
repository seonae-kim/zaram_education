#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int i;
	int a[] = { 5, 10, 15 }; //배열 초기화

	for (i = 0; i < 3; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}

}