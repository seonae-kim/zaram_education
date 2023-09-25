#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int N = 0;
	int i = 0, j = 0;
	int count = 0;
	char arr[50] = {0};
	char word[10] = {0};

	printf("input N: ");
	scanf("%d", &N);
	
	printf("input words:");
	
	for(i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
	}


	printf("output:");

	for( i = 0; i < N; i++)
	{
		for( j = 0; j < 10; j++)
		{
			sprintf(word,"%s",arr[i]);
			if( word[j] != word[j+1])
			{
				if(word[j] == word[j++])
				{
					count = -1;
					break;
				}
			}
			else 
				count = 1;
			printf("%s ", word);
		}

	}

return 0;


}


