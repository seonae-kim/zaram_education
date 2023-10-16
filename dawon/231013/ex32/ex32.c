#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char **str;
	int sum = 0, n = 0, i = 0;

	printf("n: ");
	scanf("%d",&n);

	str = (int**)malloc(sizeof(char*) * n);
	for(i = 0; i < n; i++)
	{
		*(str + i) = (int*)malloc(sizeof(char) * n);
	}

	for(i = 0; i < n; i++)
	{
		scanf("%s",*(str + i));
		sum += atoi(*(str + i));
	}
	
	printf("sum: %d\n",sum);

	return 0;
}




