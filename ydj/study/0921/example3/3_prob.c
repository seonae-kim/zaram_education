#include<stdio.h>

int main()
{
	int N = 0;
	int i = 0, j = 0, tmp = 0, max = 0;

	printf("Please enter the # of list : ");
	scanf("%d", &N);
	int num[N];

	printf("Please enter the #%d of num : ", N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (num[i] > num[j])
			{
				tmp = num[j];
				num[j] = num[i];
				num[i] = tmp;
			}
		}
	}

	max = num[N - 2] * num[N - 1];
	printf("%d \n", max);

	return 0;
}
