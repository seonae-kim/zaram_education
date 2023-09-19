#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int num_list[100] = {0,};
	int i= 1;
	int count = 0;
	int n;
	int even =0;
	int odd =0;

	printf("input n: \n");
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num_list[i]);
	}

	for(i =0; i < n; i++)
	{
		if(num_list[i] % 2 ==0)
		{
			even++;
		}
		else if(num_list[i] % 2 == 1)
		{
			odd++;
		}
	}
	printf("(%d, %d)", even, odd);
}
