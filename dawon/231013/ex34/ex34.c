#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *repeat(char *mystring);
int main()
{
	char mystring[20] = {'\0', };
	char *re;
	int i = 0;

	printf("string: ");
	fgets(mystring,sizeof(mystring),stdin);
	mystring[strlen(mystring) - 1] = '\0';

	re = repeat(mystring);

	for(i = 0; i < strlen(re); i++)
	{
		printf("%c",*(re + i));
	}
	printf("\n");

	return 0;

}

char *repeat(char *mystring)
{
	int i = 0, j = 0, index = 0;
	char *newstr;

	newstr = (char *)malloc(sizeof(char) * 20);

	for(i = 0; i < strlen(mystring); i++)
	{
		for(j = 0; j < 3; j++)
		{
			*(newstr + index) = *(mystring + i);
			index ++;
		}
	}

	return newstr;
}
