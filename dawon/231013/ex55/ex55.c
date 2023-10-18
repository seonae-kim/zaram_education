#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', };
	char *ptr;
	char *pstr[10];
	char *nstr[10];
	char minstr[10] = {'\0', };
	int index = 0, i = 0, j = 0, p = 0, minIndex = 0;

	printf("mystr: ");
	fgets(mystr,sizeof(mystr),stdin);
	mystr[strlen(mystr) - 1] = '\0';
	ptr = strtok(mystr,"x");

	memset(minstr,'{',sizeof(char) * 10);

	while(ptr != NULL)
	{
		pstr[index] = (char*)malloc(sizeof(char) * 5);
		strcpy(pstr[index++],ptr);
		ptr = strtok(NULL,"x");
	}

	for(i = 0; i < index; i++)
	{
		for(j = 0; j < index; j++)
		{
			if(strcmp(pstr[j],minstr) < 0)
			{
				strcpy(minstr,pstr[j]);
				minIndex = j;
			}
		}

		nstr[p] = (char*)malloc(sizeof(char) * 5);
		strcpy(nstr[p++],minstr);
		memset(pstr[minIndex],'{',sizeof(char) * 10);
		memset(minstr,'{',sizeof(char) * 10);
	}

	
	for(i = 0; i < p; i++)
	{
		printf("%s ",nstr[i]);
	}

	printf("\n");

	return 0;

}





	


