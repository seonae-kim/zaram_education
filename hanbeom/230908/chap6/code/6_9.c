#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS             

int main()
{
	int i, j, count = 0;

	for(i = 2; i <= 100; i++)
	{
		for (j = 2; i % j; j++);			// (i % j) 값이 0이면 for루프 종료   //소수 판별 루프

		if (j == i)
		{
			count++;
			printf("%d%s", i, count % 5 ? " " : "\n");			//소수 출력
		}
	}
	return 0;
}

