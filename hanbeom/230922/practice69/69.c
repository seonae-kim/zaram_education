#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main()
{
	int arr[50] = { 0, };
	int N;
	int i;
	int count = 0;

	printf("input N:\n");
	scanf("%d", &N);

	/*
	while (N * 10 >= 10)					// N=7,        
	{
		if (N % 10 == 7)			
		{
			count++;
		}
		N= N / 10;
	}

	printf("%d", count);				//7 개수 count 됨
	*/


	printf("input many number:\n");
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);							//7 77 17
	}

	int countarr[50] = { 0, };
	
	for (i = 0; i < N; i++)
	{
		while (arr[i] * 10 >= 10)
		{
			if (arr[i] % 10 == 7)
			{
				count++;
			}
			arr[i] = arr[i] / 10;
		}
		countarr[i] = count;
		count = 0;
	}

	for (i = 0; i < N; i++)
	{
	//	printf("%d ", countarr[i] );
	}

	int result =0;
	for (i = 0; i < N; i++)
	{
		result +=  countarr[i];
	}

	printf("%d", result);
}



