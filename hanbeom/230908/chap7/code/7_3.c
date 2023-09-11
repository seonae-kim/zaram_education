#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int i, j;
	int a[2][3] = { {15,20}, {25,30} };		// { {15,20,0}, {25, 30, 0} } 과 동일 (0 자동 생성)
	
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("a[%d][%d] = %d\n", i, j, a[i][j]);
		}
	}

	return 0;
}