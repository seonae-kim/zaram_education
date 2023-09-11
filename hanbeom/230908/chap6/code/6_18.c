#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int i, sum =0;

	for (i = 1; i <= 10; i++)
	{
        if(i % 2 ==0) continue;
        sum += i;
	}

	printf("1부터 10까지의 홀수의 합은 %d다.\n", sum);
}