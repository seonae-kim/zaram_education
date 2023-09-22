#include <stdio.h>
#include <string.h>

int main()
{
	char str[50] = {0,};
	int i;

	fgets(str,sizeof(str),stdin);	

	size_t len= strlen(str) -1;
	
	for(i = 0; i <len; i++)
	{
		if( (str[i] >= '0' && str[i] <= '9') && (0 <= i && i <=8) )
		{
			printf("*");
		}
		else 
		{
			printf("%c",str[i]);
		}
	}
}

