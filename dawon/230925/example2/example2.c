#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char num[10]={0, };
	int num_i=0;
	int sum=0;
	int i = 0;


	printf("input: ");
	scanf("%s",num);
	num_i = atoi(num);

	for(i = 0; i < 10; i++)
	{
		if(num[i] == '\0')
			break;
		sum += (num[i] - 48);
		printf("%d\n",sum);
	}

	printf("output: %d\n",num_i + sum);

	return 0;
}
