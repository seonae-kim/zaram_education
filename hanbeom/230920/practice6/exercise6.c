#include <stdio.h>
#include <string.h>
int main()
{
	char str[50] = {0,};
	int result;
	int i;

	printf("input str: \n");
	fgets(str,sizeof(str),stdin);	
	
	printf("input result: \n");
	scanf("%d", &result);			

	size_t len = strlen(str) -1;

	for(i = len -result; i < len; i++)
	{
		printf("%c", str[i]);
	}	
}
