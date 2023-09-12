#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char arr[60] = {0};
    char word[5][60] = {0};
    int i = 0, j = 0;
    int space[5] = {0}; 
    int count = 0;
    int length[6] = {0};
    int size= 0;
    int q = 0;
    int min =11;
    int min_num = length[1];
    char new_arr[5][60] = {0};

    printf("5 words: ");
    fgets(arr, sizeof(arr),stdin);

    size = strlen(arr); 
    for ( i = 0; i < 60; i++)
    {
	if(arr[i] == ' ')
	{
	    count++;

	    if(count == 1)
	    {
		space[1] = i;
		for(j = 0; j < i; j++)
		{
		  word[1][j] = arr[j]; 
		}	
	    }

	    if(count == 2)
	    {
		space[2] = i;
		for(j = space[1] + 1; j < i; j++)
		{		   		    
		    word[2][j - (space[1]+1)] = arr[j];
		}
	    }
	    
	    if(count == 3)
	    {
		space[3] = i;
		for(j = space[2] + 1; j < i; j++)
		{
		    word[3][j - (space[2]+1)] = arr[j];
		}
	    }
	    
	    if(count == 4)
            {
                space[4] = i;
                for(j = space[3] + 1; j < i; j++)
                {
                    word[4][j - (space[3]+1)] = arr[j];
                }
	    
                for(j = space[4] + 1; j < size - 1; j++)
                {
                    word[5][j - (space[4]+ 1)] = arr[j];
                }
	    } 

	}
    }
    
    for (i = 1; i < 6; i++) 
    {	
	length[i] = strlen(word[i]);
    }
	
    for(i = 0; i < 5; i++)
    {
        for(j = 1; j < 6; j ++)
        {

	    if(min > length[j])
	    {
	        min = length[j];
	        min_num = j;
	    }

	}
	for( j = 0; j < min; j++)
	{
	    new_arr[i][j] = word[min_num][j];
	}
	    length[min_num] = 20;
	    min = 20;
    }

    for(i = 0; i < 5; i ++)
    {
	printf("%s ", new_arr[i]);
    }

    printf("\n");
    return 0;
}
