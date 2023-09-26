#include<stdio.h>

int main()
{
	int arr_n = 0, query_n = 0;
	int i = 0, j = 0;
	int temp = 0;
	printf("Please enter # of element for arr : ");
	scanf("%d", &arr_n);
	int arr[arr_n];

	printf("Please enter the arr : ");
	for (i = 0; i < arr_n; i++)
	{
		scanf("%d", &arr[i]);		
	}

	printf("Please enter # of element for query : ");
	scanf("%d", &query_n);
	int query[query_n][2];
	
	printf("Please enter the query : ");
	for (i = 0; i < query_n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%d", &query[i][j]);	
		}
	}
	
	for (i = 0; i < query_n; i++)
	{
		temp = arr[query[i][0]];
		arr[query[i][0]] = arr[query[i][1]];
		arr[query[i][1]] = temp;
	}

	for (i = 0; i < arr_n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
