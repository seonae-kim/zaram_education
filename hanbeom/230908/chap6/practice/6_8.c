#include <stdio.h>

int main()
{
	int num[3] = {0,};
	int i;
	int j;
	int min, min_index;
	int result = 1;

	for(i = 0; i < 3; i++)
	{
		scanf("%d", &num[i]);
	}			// 5 1 7


	//ascending arrange
	for(i = 0; i < 3 - 1; i++)
	{
		min_index = i;
		min = num[i];				//reset min, min_index

		for(j = i+1; j < 3; j++)
		{
			if(min > num[j])	
			{
				min = num[j];
				min_index = j;	
			}
		}

		num[min_index] = num[i];		// change a[i] with a[min_index]
		num[i] = min;				
	}
	//ascending arrange

	for(i = num[0] + 1; i < num[2]; i++)
	{
		if(i % 2 == 0)
		{
			result *= i;
		}
	}

	printf("%d", result);		

}
