#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char nstr[20] = {'\0', };
	int n = 0;

	fgets(nstr,sizeof(nstr),stdin);
	n = atoi(nstr);

	printf("atoi: %d\n",n);

	return 0;
}


