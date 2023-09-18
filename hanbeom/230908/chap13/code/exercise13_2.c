#include <stdio.h>

void Bubble_Sort(int* a, int count);

int main()
{
	int data[] = {4, 2, 20, 8, 1, 33, 35, 9, 6, 26};
	int i;

	printf("data before arrange\n");

	for(i = 0; i < 10; i++)
	{
		printf("[%d] ", data[i]);
	}
	Bubble_Sort(data, 10);
	puts("\n");

	printf("data after arrange\n");

	for(i = 0 ; i < 10; i++)
	{
		printf("[%d] ", data[i]);
	}

	puts("\n");

	return 0;
}

void Bubble_Sort(int *a, int count)
{
	int i, j;
	int temp;

	for(i = 0; i < count - 1; i++)
	{
		for(j = 1; j < count - i; j++)
		{
			if(a[j-1] > a[j])
			{
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}

