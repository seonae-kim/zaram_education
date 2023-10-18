#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int arr[1000] = {0, };
	int query[1000][2];
	int i = 0, j = 0, p = 0;

//	fgets(arr,sizeof(arr),stdin);
//	arr[sizeof(arr) - 1] = '\0';

	for(i = 0; i < 5; i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 2; j++)
		{
			scanf("%d",&query[i][j]);
		}
	}

	for(i = 0; i < 3; i++)
	{
		p = arr[query[i][0]];
		arr[query[i][0]] = arr[query[i][1]];
		arr[query[i][1]] = p;
	}

	for(i = 0; i < 5; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;

}


			
				





