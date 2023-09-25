#include <stdio.h>

int solution(int *arr2, int queries[][2], int quersize, int arrsize);

int main()
{
	int n1, n2;
	int i, j;
	int quer[50][2] = {0,};
	int arr[50] = {0,};

	printf("input n1:\n");
	scanf("%d", &n1);						

	printf("input arr:\n");
	for(i = 0; i < n1; i++)
	{
		scanf("%d", &arr[i]);			
	}

	printf("input n2:\n");
	scanf("%d", &n2);						
	
	printf("input queries:\n");
	for(i = 0; i < n2; i++)			
	{
		for(j = 0; j < 2; j++)
		{
			scanf("%d", &quer[i][j]);		
		}
	}
	printf("queries:\n");

	solution(arr, quer, n2, n1);
}

int solution(int *arr2, int queries[][2], int quersize, int arrsize )
{
	int i, j, temp;
	for(i = 0; i < quersize; i++)		
	{
		for(j = 0; j < 1; j++)
		{
			temp = arr2[queries[i][j+1]];
			arr2[queries[i][j+1]] = arr2[queries[i][j]]; 
			arr2[queries[i][j]] = temp;
		}
	}

	for(i= 0; i < arrsize; i++)
	{
		printf("%d ", arr2[i]);
	}
}

