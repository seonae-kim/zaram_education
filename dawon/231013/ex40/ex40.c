#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystring[20] = {'\0', };
	char prefix[20] = {'\0', };
	int i = 0, result = 0, p0 = 0;

	printf("mystring: ");
	scanf("%s",mystring);

	printf("prefix: ");
	scanf("%s",prefix);

	if(strncmp(mystring,prefix,strlen(prefix)) == 0)
		result = 1;
	else
		result = 0;


	printf("result: %d\n",result);

	return 0;

}



