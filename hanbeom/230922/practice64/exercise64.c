#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[50] = {0,};
	int arr2[50] = {0,};
	int arrcopy[50] = {0,};
	int size;
	int i;
	int n;
	int j;
	printf("input array size: \n");
	scanf("%d", &size);

	printf("input many number: \n");
	
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);		
	}

	printf("input n: \n");
	scanf("%d", &n);		

	for(i = 0; i < size; i++)
	{
		arrcopy[i]= arr[i];
	}

	for(i = 0; i <size; i++)
	{
		arr2[i] = abs(arr[i] - n);
	}
	
	int storeindex;
	for(i=0; i < size -1; i++)
	{
		int min = arr2[i];
		int min_index = i;

		for( j= i +1; j < size; j++)
		{
			if (min > arr2[j])
			{
				min = arr2[j];
				min_index = j;
			}
		}
		if(i ==0)
		{
			storeindex = min_index;
		}
		arr2[min_index] = arr2[i];
		arr2[i] = min;
	}
	printf("%d", arrcopy[storeindex]);
}
