#include <stdio.h>
#include <string.h>

int main()
{
	char str[50] ={0,};
	int i;

	fgets(str,sizeof(str),stdin);	
	
	size_t len = strlen(str) -1;		

	for(i=0; i< len; i++)
	{
		if(str[i]>= 97 && str[i] <= 122)
		{
			str[i] = str[i] -32;
		}
	}
	for(i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
}
