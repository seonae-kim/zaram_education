#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', };
	int i = 0, index = 0, sum = 0;
	int istr[4];
	char cstr[20] = {'\0', };
	
	fgets(mystr,sizeof(mystr),stdin);
	mystr[strlen(mystr) - 1] = '\0';

	for(i = 0; i < strlen(mystr); i++)
	{
		if(mystr[i] >= '0' && mystr[i] <= '9')
		{
			cstr[index++] = mystr[i];
			if(!(mystr[i + 1] >= '0' && mystr[i + 1] <= '9'))
			{
				sum += atoi(cstr);
				memset(cstr,'\0',sizeof(char) * 20);
				index = 0;
			}
			
		}
	}

	printf("return: %d\n",sum);

	return 0;

}

		


