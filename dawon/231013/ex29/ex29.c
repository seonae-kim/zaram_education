#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n = 0, i = 0, max = 0, mul = 0, j = 0;
	int *arr;

	printf("n: ");
	scanf("%d",&n);

	arr=(int*)malloc(sizeof(int) * n);

	for(i = 0; i < n; i++)
	{
		scanf("%d",arr+i);

	}

	for(i = 0; i < n - 1; i++)
	{
		for(j = i+1; j < n; j++)
		{
			mul = *(arr + i) * *(arr + j);

			if(mul > max)
			{
				max = mul;
			}
		}
	}

	printf("Max: %d\n",max);

	return 0;
}


