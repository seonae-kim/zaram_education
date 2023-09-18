#include <stdio.h>

void Sorting(int* p, int size);

int main()
{
	int i;
	int arr[9] = {10, 20, 3, 7, 4, 30, 11, 21, 8};
	int sizearr = sizeof(arr)/ sizeof(int);
	

	Sorting(arr, sizearr);

	for(i= 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
}


void  Sorting(int* p, int size)
{
	int i, j;
	int max_value, max_index;

	for(i = 0; i < size -1; i++)
	{
		max_index = i;
		max_value = p[i];

		for(j = i+1; j < size; j++)
		{
			if(max_value < p[j])
			{
				max_index = j;
				max_value = p[j];
			}
		}
		p[max_index] = p[i];
		p[i] = max_value;
	}
}

