#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *arr;
	int n = 0, num = 0, i = 0;



	printf("n: ");
	scanf("%d",&n);

	printf("num: ");
	scanf("%d",&num);

	arr = (int*)malloc(sizeof(int) * num);

	printf("arr: ");
	for(i = 0; i < num; i++)
	{
		scanf("%d",arr + i);
	}



//	arr[strlen(arr) - 1] = '\0';

	if(num % 2 == 1)
	{
		for(i = 0; i < num; i++)
		{
			if(i % 2 == 0)
				*(arr + i) = *(arr + i) + n;
		}
	}

	else
	{
		for(i = 0; i < num; i++)
		{
			if(i % 2 == 1)
				*(arr + i) = *(arr + i) + n;
		}
	}

	for(i = 0; i < num; i++)
	{
		printf("%d ",*(arr + i));
	}

	printf("\n");

	return 0;

}


