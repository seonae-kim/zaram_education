#include <stdio.h>

int main()
{
	int a[10] = {0,};
	int b[4] = {0,};
	int count = 0;
	int i;

	for(i = 0; i < 10; i ++)
	{
		scanf("%d", &a[i]);
	}

	for(i = 0; i < 4; i++)
	{
		scanf("%d", &b[i]);
	}

	for(i = 0; i < 7; i++)
	{
		if(a[i] == b[0] && a[i+1] == b[1] && a[i+2] == b[2] && a[i+3] == b[3])
		{
			count++;
		}
	}

	printf("%d", count);
}
