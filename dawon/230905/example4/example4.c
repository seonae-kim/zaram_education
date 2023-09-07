#include <stdio.h>

int main()
{
	int n=0;
	int a[11];
	int b[11];
	int arr[11];
	int max=0;
	int index=0;
	
	printf("input: ");
	for(int i = 0 ; i < 10 ; i++)
	{
		scanf("%d",&n);
		a[i]=n;
	}

	for(int i = 0 ; i < 10 ; i++)
	{
		for(int j = 0 ; j < 10 ; j++)
		{
			if(a[j] > max)
			{
				max =  a[j];
				index = j;
			} 
		
		}

		b[i] = max;
		a[index] = 0;
		max = 0;
	}

	for(int i = 0 ; i < 5 ; i++)
	{
		arr[i * 2] = b[i];
		arr[i * 2 + 1] = b[9 - i];
	}

	printf("\noutput: ");
	for(int i = 0 ; i < 10 ; i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\n");

	return 0;
}




