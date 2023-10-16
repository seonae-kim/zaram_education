#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char numlist[10] = {'\0'};
	int i = 0, n = 0;

	printf("num list: ");
	fgets(numlist,sizeof(numlist),stdin);

	printf("num: ");
	scanf("%d",&n);

	for(i = 0; i < strlen(numlist); i+=n)
		printf("%c ",numlist[i]);

	printf("\n");

	return 0;

}
