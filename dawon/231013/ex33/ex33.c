#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystring[20];
	int i = 0;
//	int n = 0;

//	printf("n: ");
//	scanf("%d",&n);

//	mystring = (int *)malloc(sizeof(int) * n);

	printf("string: ");
	fgets(mystring,sizeof(mystring),stdin);
	mystring[strlen(mystring) - 1] = '\0';
//	scanf("%s",mystring);

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

