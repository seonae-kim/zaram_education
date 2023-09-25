#include <stdio.h>
#include <stdlib.h>


int main()
{
	int m=0, n=0, i=0, j=0, h=0;
	int *arr;
	int min=0;
	int sum = 0;
	int max = 0;

	printf("input n,m: ");
	scanf("%d %d",&n,&m);

	arr=(int *)malloc(sizeof(int)*n);

	printf("num: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d",(arr+i));
	}

	for(i = 0; i < n-2; i++)
	{
		for(j = i + 1; j < n-1; j++)
		{
			for(h = j + 1; h < n; h++)
			{
				sum = *(arr + i) + *(arr + j) + *(arr + h);
				printf("sum: %d\n",sum);
				if(m - sum <=  min && sum <= m)
				{
					min = m - sum;
					max = sum;
					
				}
			}
		}

	}

	printf("\noutput: %d\n",max);
	
	return 0;

}
	








