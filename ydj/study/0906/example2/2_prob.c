#include<stdio.h>
#define N 15

int main()
{
	int arr[N] = {0};
	int i = 0;
	int j = 0;
	int zero, max_i = 0;
	printf("Please enter the num(15) : ");
	
	//1.
	for(i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for(i = 0; i < N; i++)
	{
		if(arr[i] == 0)
		{
			for(j = 0; j < i; j++)
			{
				if(arr[j] > max_i)
				{
					max_i = arr[j];
					zero = j;
				}	
			}
			printf("%d ", max_i);
			max_i = 0;
			arr[zero] = 0;
		}
	}	
	return 0;
}


	//2.
/*	for(i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i] == 0)
		{
			if(max_i == 0)
			{
				printf("0	");
			}
			else
			{
				printf("%d	", max_i);
				// max -> new max code
				for ()
				
			}
		}
		else if(arr[i] > max_i)
		{
			nozero[j] = arr[i];
			j++;
			max_i = arr[i];

		}
	}*/
