#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', };
	char *ptr;
	char pstr[20][5] = {'\0', };
	int index = 0, i = 0;

	fgets(mystr,sizeof(mystr),stdin);
	mystr[strlen(mystr) - 1] = '\0';
	ptr = strtok(mystr,"x");

	while(ptr != NULL)
	{
		pstr[index++] = &ptr;
		ptr = strtok(NULL,"x");
	}

	

	for(i = 0; i < strlen(pstr); i++)
	{
		printf("%s\n",*(pstr + i));
	}

	return 0;

}




	


