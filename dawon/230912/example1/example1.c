#include <stdio.h>
#include <string.h>

int main()
{
    char array[5][20];
    char array2[5][20];
    char string[30];
    int cmp[10];
    int i=0, j=0, k=0;
    int minlen=100;
    int index=0;
    printf("input:" );
    for(i = 0; i < 5; i++)
    {
       scanf("%s",array[i]);
    }


    for(i = 0; i < 5; i++)
    {
	cmp[i]=strlen(array[i]);
    }

    for(i = 0; i < 5; i++)
    {
	if(cmp[i] < minlen)
	{
	    minlen=cmp[i];
	    array2[i]=array[i];
	}
    }
    

	printf("\n");
    }
    
    

    return 0;
}
