#include<stdio.h>

int main()
{
	int n, k;
	printf("Please enter k, n (k <= n) : ");
	scanf("%d %d", &k, &n);
	
	int arr[n];
	for (int j = 0; j < n; j++)
	{
		arr[j] = j + 1;
	}

	int pos;
	int i, a;

	for(i = 1; i < n; i++)
	{
		if(n < i*k)
		{
			if((n-i) == 1)
			{
				if ((k % 2) == 1)
				{
					printf("%d ", arr[0]);
					printf("%d ", arr[1]);
				}
				else
				{	
					printf("%d ", arr[1]);
					printf("%d ", arr[0]);
				}
			}

			else
			{
				pos = pos + k - 1;
				if(pos > n - i)
				{
					pos = pos - (n - i + 1);
				}
				printf("%d ", arr[pos]);	
				for (a = pos; a < n-i; a++)
				{
					arr[a] = arr[a + 1];
				}
			}
		}		

		else if(n >= i*k)
		{	
			pos = i*k - i;
			printf("%d ", arr[pos]);
			for (a = pos; a < n-i; a++)
			{
				arr[a] = arr[a + 1];
			}
		}
	}	
	return 0;
}
