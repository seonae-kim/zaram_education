#include <stdio.h>

int main()
{
	int arr[50] ={0,};
	int i;
	int n;
	int k;

	printf("input k:\n");
	scanf("%d", &k);

	printf("input many number:\n");
	
	for(i =0; i < k; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("input n:\n");
	scanf("%d", &n);


	if(k % 2 ==1)
	{
		for(i = 0; i < k; i++) 
		{	
			if(i % 2 ==0)
			{
				arr[i] += n;
			}
		}
	}

	else if(k % 2 == 0)
	{
		for(i = 0; i < k; i++)
		{
			if(i % 2 ==1)
			{
				arr[i] += n;
			}
		}
	}

	for(i =0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
}
