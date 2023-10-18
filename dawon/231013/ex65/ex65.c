#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *mystr, *ptrstr;
	char pat[5] = {'\0', };
	char *ptr, *ptr1;
	int i = 0, count = 0;
	char newstr[20] = {'\0', };

	mystr = (char*)malloc(sizeof(char) * 10);
	ptrstr = (char*)malloc(sizeof(char) * 10);

	printf("mystr: ");
	scanf("%s",mystr);

	printf("pat: ");
	scanf("%s",pat);

	strcpy(ptrstr,mystr);

	ptr1=strstr(mystr,pat);

	while(strstr(ptrstr,pat) != NULL)
	{
		ptr = strstr(ptrstr,pat);
		ptrstr = ptrstr + strlen(pat);
		count++;
	}
	
	for(i = 0; i < count; i++)
	{
		strcat(mystr +  , pat);
	}

	printf("%s\n",mystr);

	free(mystr);
	free(ptrstr);
	return 0;

}
	
	


