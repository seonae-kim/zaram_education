#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystring[10] = {'\0', };
	int i = 0;

	printf("mystring: ");
	scanf("%s",mystring);

	for(i = 0; i < 10; i++)
	{
		if(mystring[i] >= 'a' && mystring[i] <= 'z')
			mystring[i] = mystring[i] - 32;
	}

	printf("%s\n",mystring);

	return 0;

}
