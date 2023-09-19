#include <stdio.h>

int main()
{
	int a[100] = {0,};
	int n;
	int i;
	int j;
	int k = 0;
	int mul[100] = {0,};

	printf("input n\n");
	scanf("%d", &n);		// n =5

	printf("\n");		

	printf("input many numbers:\n");

	for(i = 0 ; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for(i = 0; i < n -1 ; i++)		
	{
		for(j = i+1; j < n; j++)		
		{
			mul[k] = a[i] * a[j];
			k++;
		}
	}

	int min;
	int min_index;

	for(i = 0; i < k-1; i++)
	{
		min_index = i;
		min = mul[i];

		for(j = i+1; j < k; j++)
		{
			if(min > mul[j])
			{
				min_index = j;
				min = mul[j];
			}
		}

		mul[min_index] = mul[i];
		mul[i] = min;
	}
		printf("%d ", mul[i]);
}
