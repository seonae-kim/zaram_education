#include <stdio.h>
#include <string.h>
int main()
{
	char str[50] = {0,};
	int i;

	printf("input s1: \n");
	fgets(str, sizeof(str), stdin);		//bus

	for(i = 0; i < strlen(str) -1; i++)
	{
		if(str[i] != 'A' &&  str[i] != 'E' &&  str[i] != 'I' && str[i] != 'O' && str[i] != 'U' && str[i] != 'a' && str[i]!= 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
		{
			printf("%c", str[i]);
		}
	}
	
}
