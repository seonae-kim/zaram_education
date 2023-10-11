#include<stdio.h>

int main()
{
	int n = 0;
	int slicer[3] = {0};
	int num = 0;
	int i = 0;
	printf("Please enter the # of element : ");
	scanf("%d", &num);
	int num_list[num];

	printf("Please enter the number : ");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &num_list[i]);
	}

	printf("Please enter the number n : ");
	scanf("%d", &n);

	printf("Please enter the slicer : ");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &slicer[i]);
	}
	
	if (n == 1)
	{
		for (i = 0; i < slicer[1] + 1; i++)
		{
			printf("%d ", num_list[i]);
		}
	}
	else if (n == 2)
	{
		for (i = slicer[0]; i < num; i++)
		{
			printf("%d ", num_list[i]);
		}
	}

	else if (n == 3)
	{
		for (i = slicer[0]; i < slicer[1] + 1; i++)
		{
			printf("%d ", num_list[i]);
		}	
	}

	else if (n == 4)
	{	
		for (i = slicer[0]; i < slicer[1] + 1; i = i + slicer[2])
		{
			printf("%d ", num_list[i]);
		}	
	}

	printf("\n");
	return 0;
}
