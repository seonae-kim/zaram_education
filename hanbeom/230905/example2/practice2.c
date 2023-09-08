#include <stdio.h> 

int main() 
{
	int num[15];
	int i, j;
	int index = 0;

	for (i = 0; i < 15; i++)			
	{
		scanf("%d", &num[i]);
	}
	int max = num[0];
	
	for (i = 0; i < 15; i++)			
	{
		for (j = 0; j < i; j++)              
		{
			if (max <= num[j])				
			{
				max = num[j];
				index = j;
			}
			else
			{
				max = max;
			}
		}

		if (num[i] == 0) 
		{
			printf("%d ", max);		
			num[index] = 0;  
			max = 0;
		}
	}

}



