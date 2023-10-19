#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char players[6][5] = {"mumu","soe","poe","kai","mine"};
	char callings[4][5] = {"kai","kai","mine","mine"};
	char name[5] = {'\0', };
	int i = 0, j = 0;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(strcmp(callings[i],players[j]) == 0)
			{
				strcpy(name,players[j - 1]);
				strcpy(players[j - 1],players[j]);
				strcpy(players[j],name);
			}
			memset(name,'\0',sizeof(char) * 5); 
		}
	}

	for(i = 0; i < 5; i++)
	{
		printf("%s ",players[i]);
	}
	
	printf("\n");
	return 0;

}



