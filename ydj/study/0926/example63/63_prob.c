#include<stdio.h>

int main()
{
	int i = 0, j = 0, k = 0;
	int a = 0;
	int cnt = 0;
	printf("Please enter the i : ");
	scanf("%d", &i);

	printf("Please enter the j : ");
	scanf("%d", &j);

	printf("Please enter the k : ");
	scanf("%d", &k);

	for (a = i; a < j + 1; a++)
	{
		if (a < 10)
		{
			if(k == a % 10)
			{
				cnt++;	
			}
		}
		else if (a > 9)
		{
			if (k == a / 10)
			{
				cnt++;
			}

			if (k == a % 10)
			{
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}
