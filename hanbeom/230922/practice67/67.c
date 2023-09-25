#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main()
{
	int arr[50] = { 0, };
	int N;
	int i;

	printf("input N:\n");
	scanf("%d", &N);

	printf("input many number:\n");
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);				
	}
	int count = 0;
	int count2 = 0;
	int countarr[50] = { 0, };

	for (i = 0; i < N; i++)
	{
		if (arr[i] == 2)
		{
			count++;
			count2++;
		}
		countarr[i] = count;				// 0 1 0 0 0 1 0 0       
		count = 0;
	}

	if (count2 == 0)
	{
		printf("-1");
		return 0;
	}

	int index_a = 0;
	int index_b = 0;

	for (i = 0; i < N; i++)
	{
		if (countarr[i] == 1)
		{
			index_a = i;
			break;
		}
	}

	for (i = N; i > 0; i--)
	{
		if (countarr[i] == 1)
		{
			index_b = i;
			break;
		}
	}
	
	for(i = index_a; i <= index_b; i++)
	{
		printf("%d ",arr[i]);
	}
}



