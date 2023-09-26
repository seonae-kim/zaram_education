#include<stdio.h>

int main()
{
	int n = 0;
	int cnt = 0;
	int i = 0;
	printf("Please enter the # of element : ");
	scanf("%d", &n);

	int arr[n];
	printf("Please enter the num : ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i] < 10)
		{
			if(arr[i] % 10 == 7)
			{
				cnt++;	
			}
		}
		else if (arr[i] > 9)
		{
			if (arr[i] / 10 == 7)
			{
				cnt++;
			}

			if (arr[i] % 10 == 7)
			{
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
