#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS             

int main()
{
	int sum = 0;
	int number = 0;

	printf("1에서 10까지의 합을 구합니다.\n");

	do
	{
		number++;
		sum += number;
	} while (number < 10);

	printf("합은 %d입니다.\n", sum);

}

