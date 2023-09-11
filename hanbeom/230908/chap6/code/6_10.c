#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS             

int main()
{
	int number = 0;
	int sum = 0;

	printf("1에서 10까지의 합\n");

	while(number <= 10)
	{
		sum += number;
		number++;
	}

	printf("합은 %d입니다.\n", sum);
	return 0;
}

