#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', };

	int i = 0, j = 0, k = 0;

	fgets(mystr,sizeof(mystr),stdin);
	mystr[strlen(mystr) - 1] ; '\0';

	for(i = 0; i < strlen(mystr) - 1; i++)
	{
		for(j = i + 1; j < strlen(mystr); j++)
		{
			if(mystr[j] == mystr[i] || mystr[j] == mystr[i] - 32 || mystr[j] - 32 == mystr[i])
			{
				for(k = j; k < strlen(mystr); k++)
				{
					mystr[k] = mystr[k + 1];
				}
			}
		}
	}

	printf("result: %s\n",mystr);
	
	return 0;

}


