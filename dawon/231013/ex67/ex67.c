#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int arr[8] = {0, }, count[8], index = 0, result = 0;
	int i = 0;

	printf("arr: ");
	for(i = 0; i < 8; i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i = 0; i < 8; i++)
	{
		if(arr[i] == 2)
		{
			count[index++] = i;
		}
	}

	if(index == 0)
		printf("-1");

	else
	{
		for(i = count[0]; i <= count[index - 1]; i++)
		{
			printf("%d ",arr[i]);
		}
	}

	printf("\n");

	return 0;

}



			
