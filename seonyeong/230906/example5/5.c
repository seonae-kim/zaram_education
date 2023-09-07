#include <stdio.h>

int main()
{
	int num[4][4] = { 0 };
	int i, j;
	int max1[4] = { 0 }; // maximum
	int max2[4] = { 0 };
	int sum = 0;
	int p[4] = { 0 }; //column

	printf("16 numbers:");
	

	for ( i = 0; i < 4; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			scanf("%d", &num[i][j]);			
		}
	}
	
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (num[i][j] > max1[i])
			{
				max2[i] = max1[i];
				max1[i] = num[i][j];			
				p[i] = j;
			}			
		}
		if ((num[i - 1][p[i - 1]] == max1[i - 1]) && (p[i] == p[i - 1]))
		{
			sum = sum + max2[i];
			printf("%d\n",max2[i]);
		}
		else sum = sum + max1[i];		
				
	}		
	printf("%d\n", sum);
	return 0;
}
