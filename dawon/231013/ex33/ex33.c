#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystring[20];
	int i = 0;

	printf("string: ");
	fgets(mystring,sizeof(mystring),stdin);
	mystring[strlen(mystring) - 1] = '\0';

	for(i = 0; i < strlen(mystring); i++)
	{
		if(mystring[i] == 'a' || mystring[i] == 'e'|| mystring[i] == 'i' || mystring[i] == 'o' ||
			mystring[i] == 'u')
		{
			continue;
		}

		printf("%c",mystring[i]);
	}

	printf("\n");
	return 0;
}

