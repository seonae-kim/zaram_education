#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', };
	char pat[20] = {'\0', };
	int result = 0, i = 0;

	printf("mystr: ");
	scanf("%s",mystr);

	printf("pat: ");
	scanf("%s",pat);

	for(i = 0; i < 20; i++)
	{
		if(mystr[i] == 'A')
			mystr[i] = 'B';
		else if(mystr[i] == 'B')
			mystr[i] = 'A';
	}

	if(strstr(mystr,pat) != NULL)
		result = 1;

	else
		result = 0;

	printf("result: %d\n",result);

	return 0;
}

