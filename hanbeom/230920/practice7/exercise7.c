#include <stdio.h>
#include <string.h>

int main()
{
	char str[50] = {0,};
	char str2[50] = {0,};
	int i;
	int k=0;
	fgets(str,sizeof(str),stdin);		//apple pen

	size_t len = strlen(str) -1;

	for(i=0; i < len; i++)
	{
		if(str[i] != ' ')
		{
			str2[k] = str[i];
			k++;
		}
	}
	for(i=0; i < len; i++)
	{
		printf("%c", str2[i]);
	}
}
