#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *arr;
	int n = 0, i = 0, j = 0, count = 0;
	char c[5] = {'\0', };


	printf("n: ");
	scanf("%d",&n);

	arr = (int*)malloc(sizeof(int) * n);


	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i = 0; i < n; i++)
	{
		sprintf(c,"%d",arr[i]);
		for(j = 0; j < strlen(c); j++)
		{
			if(c[i] == '7')
				count++;
		}
	}

	printf("result: %d\n",count);

	return 0;

}




		
	
