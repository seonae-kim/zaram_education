#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', };
	int n = 0, i = 0;

	printf("n: ");
	scanf("%d",&n);

	scanf("%s",mystr);

	for(i = strlen(mystr) - n; i < strlen(mystr); i++)
	{
		printf("%c",mystr[i]);
	}
	printf("\n");

	return 0;
}
