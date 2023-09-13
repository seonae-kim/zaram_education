#include <stdio.h>

int main()
{
    int N = 0;
    int num[30] = {0};
    int i = 0;
    int j = 0;
    int a = 0;

    printf("input N: ");
    scanf("%d", &N);

    printf("num: ");

    for (i = 0; i < N; i++)
    {
	scanf("%d", &num[i]);
    }
    
    printf("output: ");

    for (i = 0; i < N; i++)
    {
	for(j = i + 1; j < N; j++)
	{	    
	    for( a = j + 1; a < N; a ++)
	    {
		if(num[a] == num[j])
		{
		    num[a] = 'z';
		} 
		
		if(num[a] == num[i])
                {
                    num[a] = 'z';
                }	
	    }
	    
	    if(num[j] == 'z')
		continue;
	    if(num[i] == 'z')
		continue;

	    if( num[j] != num[i] ) 
	    {
	        printf("(%d %d) ", num[i], num[j]);
	    }
	}

    }

    printf("\n");

}

