#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char code[20] = {'\0', };
	int i = 0, mode = 0;
	char c;

	printf("code: ");
	scanf("%s",code);

	mode = 0;

	while(code[i] != '\0')
	{
		if(mode == 0)
		{	
			for(i; i < strlen(code); i += 2)
			{
				printf("%c",code[i]);			
			
				if(code[i + 1] == '1')
				{
					mode = 1;
					i += 3;
					break;
				}
				if(code[i + 2] == '1')
				{
					mode = 0;
					i += 4;
					break;
				}

			}
		}

		if(mode == 1)
		{
			for(i; i < strlen(code); i += 2)
			{
				printf("%c",code[i]);			
			
				if(code[i + 1] == '1')
				{
					mode = 0;
					i += 2;
					break;
				}
				if(code[i + 2] == '1')
				{
					mode = 0;
					i += 3;
					break;
				}
			}
		}
	}

		
	printf("\n");

	return 0;

}


		




