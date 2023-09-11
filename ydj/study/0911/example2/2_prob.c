#include<stdio.h>
#define N 100

int main()
{
	char str[N] = {0};
	int i = 0;
	printf("Please enter string : ");

	fgets(str, sizeof(str), stdin);
	
	for(i = 0; i < N; i++)
	{
		if ( str[i] <= '9' && str[i] >= '0')
		{
			printf("%c", str[i]);
		}
	}
	printf("\n");
	return 0;
}
