#include <stdio.h>
#include <stdlib.h>

int main()
{
	char n_str[50] = {0,};

	fgets(n_str, sizeof(n_str), stdin);
	printf("%d", atoi(n_str));	

}
