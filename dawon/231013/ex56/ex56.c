#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char input[5] = {'\0', };
	int n = 0, i = 0;

	printf("input: ");
	scanf("%d",&n);

	sprintf(input,"%d",n);


	for(i = 0; i < 5; i++)
	{
		switch(input[i])
		{
			case '0':
				input[i] = 'a';
				break;
			
			case '1':
				input[i] = 'b';
				break;
			
			case '2':
				input[i] = 'c';
				break;

			case '3':
				input[i] = 'd';
				break;

			case '4':
				input[i] = 'e';
				break;

			case '5':
				input[i] = 'f';
				break;

			case '6':
				input[i] = 'g';
				break;

			case '7':
				input[i] = 'h';
				break;

			case '8':
				input[i] = 'i';
				break;

			case '9':
				input[i] = 'j';
				break;

			case '\0':
				break;
		}
	}

	printf("result: %s\n",input);

	return 0;

}



