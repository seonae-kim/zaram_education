#include<stdio.h>

int main()
{
	int i = 0, j = 0;
	int flag = 0;
	int arr[8] = {0};
	printf("Please enter the element : ");
	for (i = 0; i < 8; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < 8; i++)
	{
		if (arr[i] == 2)
		{
			j++;
		}
	}
//	printf("%d, \n", j);
	int location[j];
	j = 0;

	for (i = 0; i < 8; i++)
	{
		if (arr[i] == 2)
		{
			location[j] = i;
			j++;
		}
	}

//	printf("%d .", j);
//	printf("%d %d", location[0], location[j]);


	if (j == 0)
	{
		printf("-1\n");
		flag = 1;
	}

	if (flag == 0)
	{
		for (i = location[0]; i < location[j - 1] + 1; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");	
	}
	return 0;
}
