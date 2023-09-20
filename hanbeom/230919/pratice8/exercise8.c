#include <stdio.h>

int main()
{
	char str[50];
	int i = 0;
	int N;
	int j;
	printf("input N\n");
	scanf("%d", &N);

	while (getchar() != '\n');

	printf("input string\n");
	fgets(str, sizeof(str), stdin);	//hello'\0'

	printf("str[5] is %c", str[5]);		
	while(str[i] != '\n')
	{
		for(j = 0; j < N ; j++)
		{
				printf("%c", str[i]);		
		}									
		i++;								
	}
	
}

