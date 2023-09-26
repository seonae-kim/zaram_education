#include <stdio.h>
#include <string.h>

int main()
{
	char code[50] = {0,};
	int  mode = 0;
	int i;

	printf("input code:\n");
	fgets(code,sizeof(code),stdin);		

	size_t len = strlen(code) - 1;	

	for(i =0; i < len; i++)
	{
		if(code[i] == '1')
		{
			mode = (mode + 1) % 2;
		}

		if(mode == 0)
		{
			if(i % 2 == 0 && code[i] != '1')
			{	
				printf("%c", code[i]);
			}
		}
		else if(mode == 1)
		{
			if(i % 2 == 1 && code[i] != '1' )
			{
				printf("%c", code[i]);
			}
		}
	}		
}
