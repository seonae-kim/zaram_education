#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[15] = {'\0', };
	char c;
	int i = 0;

	printf("arr: ");
	fgets(mystr,sizeof(mystr),stdin);

//	while(getchar() != '\n');
	mystr[strlen(mystr) - 1] = '\0';
	
	printf("c: ");
	scanf("%c",&c);

	for(i = 0; i < strlen(mystr); i++)
	{
		if(mystr[i] == c)
			mystr[i] = mystr[i] - 32;
	}

	printf("%s\n",mystr);

	return 0;

}

