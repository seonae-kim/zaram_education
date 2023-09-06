#include <stdio.h>

int main()
{	
	int n=0;
	int a[16];
	int max=0;
	int index=0;
	int j=0;
	int c=0;

	printf("input: ");
	for(int i = 0 ; i < 15 ; i++)
	{
		scanf("%d",&n);
		a[i] = n;
	}

	printf("   output: ");

	for(j = 0 ; j < 15 ; j++)
	{
		if(a[j] == 0)
		{
			printf("%d ",max);

			max = 0;
			a[index] = 0;
		
			for(int i = 0 ; i <= j ; i++)
			{
				if(a[i] >= max)
				{
					max = a[i];
					index = i;	
				}
			}
		}

		else if(a[j] >= max)
		{
			max = a[j];
			index = j;
		}	
	}

	printf("\n");

	return 0;

}
				
			


