#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int middle(int *arr, int n);
int main()
{
	int arr[20];
	int i = 0, n = 0, re = 0;

	printf("n: ");
	scanf("%d",&n);

	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}

	re = middle(arr, n);
	printf("result: %d\n",re);

	return 0;

}

int middle(int *arr, int n)
{
	int i = 0, min = 0, index = 0, p = 0, j = 0;
	int sor[20];

	min = *(arr);

	for(j = 0; j < n; j++)
	{
		for(i = 0; i < n; i++)
		{
			if(*(arr + i) < min)
			{
				min = *(arr + i);
				index = i;
			}
		}
			sor[p++] = min;
			*(arr + index) = 1000;
			min = 1000;
	}

	if(sor[n - 1] == 0)
			return 0;

	else	
		return sor[n / 2];
}
	




	


