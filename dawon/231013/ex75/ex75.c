#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int p = 0;
	int *numlist;
	int n = 0, i, sub = 0, min = 10000, j = 0, index = 0, k = 0;
	int nlist[10];

	printf("p: ");
	scanf("%d",&p);

	printf("n: ");
	scanf("%d",&n);

	numlist = (int*)malloc(sizeof(int) * n);
	printf("numlist: ");
	for(i = 0; i < p; i++)
	{
		scanf("%d",numlist + i);
	}

	for(i = 0; i < p; i++)
	{
		for(j = 0; j < p; j++)
		{
			if(n >= *(numlist + j))
				sub = n - *(numlist + j);
			else
				sub = *(numlist + j) - n;


			if(sub < min)
			{
				min = sub;
				index = j;
			}
			if(sub == min)
			{
				if(*(numlist + j) > *(numlist + index))
					index = j;
			}

		}
		nlist[k++] = *(numlist + index);
		*(numlist + index) = 100000;
		min = 100000;
	}

	for(i = 0; i < k; i++)
	{
		printf("%d ",nlist[i]);
	}
	printf("\n");

	return 0;

}
		


		



