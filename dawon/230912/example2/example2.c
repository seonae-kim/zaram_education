#include <stdio.h>

int main()
{
    char array[5][5];
    int i=0, j=0;
    
    printf("input: ");
    for(i = 0; i < 5; i++)
    {
	scanf("%s",array[i]);
    }

    printf("output: ");
    for(i = 0; i < 5; i++)
    {
	for(j = 0; j < 5; j++)
	{
	    printf("%c",array[j][i]);
	}
    }

    printf("\n");
    return 0;
}

    
