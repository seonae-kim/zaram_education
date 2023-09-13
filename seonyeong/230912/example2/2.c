#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char arr[25] = { 0 };
    char word[5][5] = { 0 };
    int i = 0, j = 0;
    int count = 0;
    int size = 0;
    int space[5] = {0};  
    int q = 0;
    printf("5 words: ");
    fgets(arr, sizeof(arr), stdin);
    size = strlen(arr); 

    for(i = 0; i < 25; i++)
    {	
	if(arr[i] == ' ')
	{
	    count++;

	    if(count == 1)
	    {
		space[1] = i;
		for(j = 0; j < i; j++)
		{
		  word[0][q] = arr[j];
		  q++;
		}
		q = 0;
	    }

	    if(count == 2)
	    {
		space[2] = i;
		for(j = space[1] + 1; j < i; j++)
		{
		    word[1][q] = arr[j];
		    q++;
		}
		q = 0;
	    }

	    if(count == 3)
	    {
		space[3] = i;
		for(j = space[2] + 1; j < i; j++)
		{
		    word[2][q] = arr[j];
		    q++;
		}
		q = 0;
	    }

	    if(count == 4)
            {
                space[4] = i;
                for(j = space[3] + 1; j < i; j++)
                {
                    word[3][q] = arr[j];
		    q++;
                } 
		q = 0;

                for(j = space[4] + 1; j < size - 1; j++)
                {
                    word[4][q] = arr[j];
		    q++;
                }
	    }

	}

    }
   
    printf(" output: ");
    
    for(j = 0; j < 5; j++)
    { 
	for(i = 0; i < 5; i++)
	{
	    printf("%c", word[i][j]);
	}
    }
    
    printf("\n");
}

