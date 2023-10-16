#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char prestr[10] = {'\0', };
	char poststr[10] = {'\0', };

	printf("pre: ");
	scanf("%s",prestr);

	printf("post: ");
	scanf("%s",poststr);

	strcat(prestr,poststr);

	printf("%s\n",prestr);

	return 0;
}
