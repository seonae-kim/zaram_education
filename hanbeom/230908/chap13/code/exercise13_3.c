#include <stdio.h>

void Insert_Sort(int*a, int count);

int main(void)
{
	int data[] = {4, 2, 20, 8, 1, 33, 35, 9, 6, 26};
	int i;

	printf("data before arrange\n");

	for(i = 0; i < 10; i++)
	{
		printf("[%d] ", data[i]);
	}

	Insert_Sort(data, 10);
	puts("\n");

	printf("data after arrange\n");

	for(i = 0; i < 10; i++)
	{
		printf("[%d] ", data[i]);
	}

	puts("\n");

	return 0;
}

void Insert_Sort(int *a, int count)
{
	int i, j;
	int temp;

	for(i = 1; i < count; i++)
	{
		temp = a[i];
		j = i;

		while((a[j - 1] > temp) && (j > 0))
		{
			a[j] = a[j - 1];
			j = j -1;
		}

		a[j] = temp;
	}
}




