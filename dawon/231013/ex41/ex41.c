#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n = 0;
	char nstr[20] = {'\0', };

	printf("n: ");

	scanf("%d",&n);

	sprintf(nstr,"%d",n);

	printf("result: %s\n",nstr);

	return 0;
}
