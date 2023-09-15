#include <stdio.h>
#include <string.h>

int main()
{
	char word[5][5] = {0,};
	char str[500] = {0,};	
	int i= 0;
	int k,j;
	int count = 0;

	fgets(str, sizeof(str), stdin);
	
	char* ptr = strtok(str, " ");
	while(ptr != NULL)
	{
		strcpy(word[i], ptr);
		printf("word[%d] is %s\n",i, word[i]);
		ptr = strtok(NULL, " ");
		i++;
	}

	for(k = 0; k < 5; k++)
	{
		for(j = 0; j < 5; j++)
		{	
			if(word[j][k] != '\n')
				printf("%c", word[j][k]);
		}
	}

}
