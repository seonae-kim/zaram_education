#include<stdio.h>

int main()
{
	int n = 0;
	int i = 0, j = 0;
	int arr[10] = {-1};
	int cnt = 0;

	printf("Please enter the length of string : ");
	scanf("%d", &n);
	char str[n];
	printf("Please enter the string : ");
	scanf("%s", str);

	for (i = 0; i < n; i++)
	{
		if (str[i] == 'x')
		{
			arr[j] = i;
			j++;
		}
	}
	cnt = j;

	for (i = 0; i < cnt; i++)
	{
		if (i == 0)
		{
			printf("%d ", arr[0]);
		}
		else
		{
			printf("%d ", arr[i] - arr[i - 1] - 1);
		}

		if (i == cnt - 1)
		{
			printf("%d ", n - arr[cnt - 1] - 1);
		}
	}

	printf("\n");

	return 0;
}
