#include <stdio.h>

int main()
{
	int arr[30] ={0,};
	int i,j;
	int n;

	printf("input n: \n");
	scanf("%d", &n); 
	
	printf("input many number: \n");

	for(i =0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int min;
	int min_index;

	for(i = 0; i < n-1; i++)
	{
		min_index = i;
		min = arr[i];

		for(j = i+1; j <n; j++)
		{
			if(min > arr[j])
			{
				min_index = j;
				min = arr[j];
			}

		}
		arr[min_index] = arr[i];
		arr[i] = min;
	}
	printf("%d ", arr[n/2]);
}
