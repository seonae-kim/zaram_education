#include<stdio.h>

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int count = 0, max = 0, num = 0;
	int flag = 0;
	printf("Please enter the N : ");
	scanf("%d", &N);
	printf("Please enter the num : ");

	int arr[N];

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (i = 0; i < N; i++)
	{
		count = 1;
		for (j = i + 1; j < N; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}

		if (max < count)
		{
			num = arr[i];
			max = count;
		}

		else if (max == count)
		{
			printf("%d \n", -1);
			flag++;
			break;
		}
	}
	
	if (flag == 0)
	{
		printf("%d \n", num);
	}
	return 0;
		
}
