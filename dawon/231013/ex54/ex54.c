#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[15] = {'\0', };
	char *ptr, *string;
	char mystrLen[10] ={'\0', };
	int index = 0, i = 0;


	fgets(mystr,sizeof(mystr),stdin);
	mystr[strlen(mystr) - 1] = '\0';

	string = mystr;

	while((ptr = strsep(&string,"x")) != NULL)
	{
		sprintf(&mystrLen[index++],"%d ",strlen(ptr));
	}

	for(i = 0; i < strlen(mystrLen); i++)
	{
		printf("%c ",mystrLen[i]);
	}
	printf("\n");
	return 0;

}

		
		
