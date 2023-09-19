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

	int min;
	int min_index;

	for(i = 0; i < n-1; i++)
	{
		min_index = i;
		min = a[i];

		for(j = i+1; j < n; j++)
		{
			if(min > a[j])
			{
				min_index = j;
				min = a[j];
			}
		}

		a[min_index] = a[i];
		a[i] = min;
	}

	printf("%d", a[n-1] * a[n-2]);
}
