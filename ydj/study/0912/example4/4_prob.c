#include<stdio.h>

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int count = 0, max = 0, num = 0, arr_max =0, arr_i = 0;
	int flag = 0;
	printf("Please enter the N : ");
	scanf("%d", &N);
	printf("Please enter the num : ");

	int arr[N];
	int arr_count[N];

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (i = 0; i < N; i++)
	{
		count = 1;
		for (j = i + 1 ; j < N; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		arr_count[i] = count;

		if (max < count)
		{
			num = arr[i];
			max = count;
		}
	}

	for(i = 0; i < N; i++)
	{
		if (arr_count[i] > arr_max)
		{
			arr_max = arr_count[i];
		}
	}

	for (i = 0; i < N; i++)
	{
		if(arr_max == arr_count[i])
		{
			flag++;
		}
	}

	if (flag == 1)
	{
		printf("%d \n", num);
	}
	else
	{
		printf("-1 \n");
	}

	return 0;		
}
