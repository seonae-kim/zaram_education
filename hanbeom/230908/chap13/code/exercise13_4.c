#include <stdio.h>

void Shell_Sort(int*a, int count);

int main()
{
	int data[] = {4, 2, 20, 8, 1, 33, 35, 9, 6, 26};
	int i;

	printf("data before arrange\n");

	for(i = 0; i < 10; i++)
	{
		printf("[%d] ", data[i]);
	}

	Shell_Sort(data, 10);
	puts("\n");

	printf("data after arrange\n");

	for(i = 0; i < 10; i++)
	{
		printf("[%d] ", data[i]);
	}
	puts("\n");

	return 0;
}

void Shell_Sort(int *a, int count)
{
	int i, j, inc, h;
	int temp;

	for(h = count / 2; h > 0; h /= 2)
	{
		for(i = 0; i < h; i++)
		{
			for(j = i +h; j < count; j +=h)
			{
				temp = a[j];
				inc = j;

				while(inc > h -1 && a[inc - h] > temp)
				{
					a[inc] = a[inc-h];
					inc = inc - h;
				}
				a[inc] = temp;
			}
		}
	}
}
