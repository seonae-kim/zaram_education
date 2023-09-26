#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int num[50] = { 0, };
	int gap[50] = { 0, };
	int i, j;
	int n;
	int size;

	printf("input size:\n");
	scanf("%d", &size);				

	printf("input many number:\n");
	for (i = 0; i < size; i++)
	{
		scanf("%d", &num[i]);			
	}
	printf("input n:\n");
	scanf("%d", &n);			

	for (i = 0; i < size - 1; i++)
	{
		int max = num[i];
		int max_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (max < num[j])
			{
				max = num[j];
				max_index = j;
			}
		}
		num[max_index] = num[i];
		num[i] = max;
	}

	for(i =0; i < size; i++)
	{
		gap[i] = abs(num[i] - n); 
	}
	
	int final[50] = { 0, };
	for(i =0; i < size; i++)
	{
		int min = gap[i];
		int min_index =i;
		for(j =0 ; j < size; j++)
		{
			if(min > gap[j])
			{
				min = gap[j];
				min_index = j;
			}
		}
		final[i] = num[min_index];		//core
		gap[min_index] = 99999;			//core
	}	
	for (i = 0; i < size; i++)
	{
		printf("%d ", final[i]);											
	}
}
