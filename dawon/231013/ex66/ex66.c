#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', }, newstr[20] = {'\0', }, sorstr[20] = {'\0', };
	int min = 123, i = 0, j  = 0, index = 0, sameflag = 0;
	char minch;

	fgets(mystr,sizeof(mystr),stdin);
	mystr[strlen(mystr) - 1] = '\0';

	for(i = 0; i < strlen(mystr); i++)
	{
		for(j = 0; j < strlen(mystr); j++)
		{
			if(i == j)
				continue;

			if(mystr[i] == mystr[j])
			{
				sameflag = 1;
				break;
			}
		}
		if(sameflag != 1)
		{
			newstr[index++] = mystr[i];
		}
		sameflag = 0;
	}

	printf("newstr: %s\n",newstr);

	for(i = 0; i < strlen(newstr); i++)
	{
		for(j = 0; j < strlen(newstr); j++)
		{
			if(newstr[j] < min)
			{
				minch = newstr[j];
				index = j;
				min = newstr[j];
			}
			
		}

		sorstr[i] = minch;
		newstr[index] = '{';
		min = 123;
	}

	printf("result: %s\n",sorstr);

	return 0;

}
