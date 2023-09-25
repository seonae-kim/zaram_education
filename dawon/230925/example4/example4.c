#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0, i = 0, j = 0;
	int **arr1;
	int **arr2;
	int a = 0;

	printf("num: ");
	scanf("%d",&n);

	arr1=(int**)malloc(sizeof(int)*n);
	
	for(i = 0; i < n; i++)
	{
		*(arr1+i) = (int*)malloc(sizeof(int)*n);
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d",*(arr1+i)+j);
		}
	}

	for(i = 0; i < n; i++)
	{
		arr2[0][i] = arr1[0][i];
	}
	
	for(i = 1; i < n; i++)
	{
		arr2[i][2] = arr1[1][a];
		a++;
	}
	for(i = n-1; i > 0; i--)
	{
		arr2[i][n] = arr1
	







		
	return 0;
}
