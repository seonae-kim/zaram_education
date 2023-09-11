#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS             

int main()
{
	int i;

	for (i = 1; i < 100; i++)
	{
		printf("%d ", i);
		if (i >= 5)
			break;
	}

	printf("\nfor문을 빠져나왔습니다.\n");
}

