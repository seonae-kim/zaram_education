#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int i =0;
	double num[2] = {0, 0};
	char str[] = "43 + 27";

	char *token = strtok(str, "+");

	while (token != NULL)
	{
	    num[i] = atof(token);
	    printf("%lf \n", num[i]);
	    token = strtok(NULL, "+");
	    i++;
	}
    return 0;
}
