#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int n =0;
	char *arr;
	int max = 0, count = 0, i = 0, j = 0, maxcount = 0;

	printf("n: ");
	scanf("%d",&n);

	arr = (char*)malloc(sizeof(char) * n);

	for(i = 0; i < n; i++)
	{
		scanf("%s",arr + i);
		printf("strlen: %d\n",strlen(arr + i));
		if(strlen(arr + i) > max)
			max = strlen(arr + i);
	}

	printf("max: %d\n",max);
	printf("max: %s\n",arr);

	for(i = 1; i <= max; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("strlen: %d\n",strlen(arr + j));
			if(strlen(arr + j) == i)
			{
				count++;
			}
		}
		printf("%d count: %d\n",i,count);
		if(count > maxcount)
		{
			maxcount = count;
		}
		count = 0;
	}

	printf("return: %d\n",maxcount);

	return 0;

}

		

		

