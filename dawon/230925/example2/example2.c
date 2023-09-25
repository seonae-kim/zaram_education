#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char num[10]={0, };
	int num_i=0;
	int sum=0;
	int i = 0, j = 0, h = 0;
	int a = 0, b = 0, c = 0;
	int d = 0;


	printf("input: ");
	scanf("%d",&d);
	num_i = atoi(num);

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			for(h = 0; h < 10; h++)
			{
				sprintf(num,"%d%d%d",i,j,h);
				num_i = atoi(num);
				if(i + j + h + num_i == d)
				{
					printf("output: %d\n",num_i);
				}
			}
		}
	}

	return 0;
}
