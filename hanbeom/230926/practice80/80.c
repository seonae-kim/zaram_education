#include <stdio.h>

int main()
{
	char str[50] = {0,};
	int i = 0;
	while(1)
	{
		scanf("%c", &str[i]);
		if(str[i] == 'q')
		{
			printf("\n");
			printf("exit program");
			return 0;
		}
		printf("%c", str[i]);
		i++;
	}




}
