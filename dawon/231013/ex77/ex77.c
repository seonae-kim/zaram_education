#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char code[20] = {'\0', };
	int i = 0;
	char c;

	printf("code: ");
	scanf("%s",code);
/*
	for(i = 0; i < strlen(code); i += 2)
	{
		printf("%c",code[i]);
		if(code[i] == '1')
		{
			printf("i :%d\n",i);
			c = '1';
			break;
		}
	}

*/

	for(i = 0; i < strlen(code); i++)
	{
		if(code[i] == '1')
		{
			c = '1';
			break;
		}

	





	
	printf("\n");

	return 0;

}


		




