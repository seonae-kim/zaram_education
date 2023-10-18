#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *numbers;
	int k = 0, n = 0, i = 0, count = 0;
	int p = 1;

	printf("n: ");
	scanf("%d",&n);

	printf("k: ");
	scanf("%d",&k);

//	numbers = (int*)malloc(sizeof(int) * n);

/*	for(i = 0; i < n; i++)
	{
		*(numbers + i) = p++;
	}
*/
	for(i = 1; i < 100; i += 2)
	{
		if(i > n)
			i = i - n;
	
		count++;
		if(count == k)
		{
			break;
		}
		if(i >= n)
			i = i + 2 - n;

	}

	printf("result: %d\n",i);

	return 0;

}
		
		


