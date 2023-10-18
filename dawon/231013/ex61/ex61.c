#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char phnum[15] = {'\0', };
	int i = 0;

	fgets(phnum,sizeof(phnum),stdin);
	phnum[strlen(phnum) - 1] = '\0';

	for(i = 0; i < 8; i++)
	{
		if(phnum[i] == '-')
			continue;
		phnum[i] = '*';
	}

	printf("return: %s\n",phnum);

	return 0;

}
