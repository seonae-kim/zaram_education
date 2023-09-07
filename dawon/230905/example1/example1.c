#include <stdio.h>


int main()
{
	int a[11];
	
	int n = 0;
	int sum = 0;

	printf("input: ");

	for(int i = 0 ; i < 10 ; i++)
	{
		scanf("%d",&n);
		a[i] = n;
	}
	
	for(int i = 0 ; i < 10 ; i++)
	{
		if(a[i] == 0)
		{
			for(int j = i-1 ; j >= 0 ; j--)
			{
				if(a[j] == 0)
					continue;
												
				a[j] = 0;
				break;
			}	
		}
	}

	printf("output: ");

	for(int j = 0 ; j < 10 ; j++)
	{
		sum += a[j];
	}

	printf("%d\n",sum);
	
	return 0;

}




