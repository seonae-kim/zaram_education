#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', };
	int s, e, index = 0, i;
	char rvstr[20] = {'\0', };

	fgets(mystr,sizeof(mystr),stdin);
	mystr[strlen(mystr) - 1] = '\0';

	printf("s: ");
	scanf("%d",&s);

	printf("e: ");
	scanf("%d",&e);

	for(i = e; i >= s; i--)
	{
		rvstr[index++] = mystr[i];
	}


	for(i = 0; i < index; i++)
	{
		mystr[s++] = rvstr[i];
	}

	printf("result: %s\n",mystr);

	return 0;

}





	
