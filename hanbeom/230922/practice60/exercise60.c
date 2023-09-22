#include <stdio.h>
#include <string.h>
int main()
{
	char str[50] = {0,};
	int s = 0;
	int e = 0;
	int i;

	fgets(str,sizeof(str),stdin);		
	
	printf("input s:\n");
	scanf("%d", &s);		

	printf("input e:\n");
	scanf("%d", &e);		

	size_t len = strlen(str) - 1;
	int fix_e= e;
	
	for(i = 0; i < len; i++)
	{
		if(s <= i && i <= fix_e)	
		{
			printf("%c", str[e]);
			e--;
		}
		else
		{
			printf("%c", str[i]);
		}
	}
}
