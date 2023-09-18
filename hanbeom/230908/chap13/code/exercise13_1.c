#include <stdio.h>

void Select_Sort(int*a, int count);

int main()
{
	int data[] = {4, 2, 20, 8, 1, 33, 35, 9 ,6, 26};
	int i;

	printf("data before arrange\n");

	for(i=0; i < 10; i++)
	{
		printf("[%d] ", data[i]);
	}

	Select_Sort(data, 10);
	puts("\n");

	printf("data after arrange\n");

	for(i = 0; i < 10; i++)
	{
		printf("[%d] ", data[i]);
	}
			
	puts("\n");
	return 0;
}

void Select_Sort(int *a, int count)
{
	int i, j;
	int min_value, min_index;

	for(i = 0; i < count - 1; i++)
	{
		min_index = i;
		min_value = a[i];

		for(j = i+1; j < count; j++)
		{
			if(min_value > a[j])
			{
				min_index = j;
				min_value = a[j];
			}
		}
		a[min_index] = a[i];
		a[i] = min_value;
	}
}

