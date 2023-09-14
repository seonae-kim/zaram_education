#include <stdio.h>
#include <string.h>

int main()
{
    char array[5][20]={0, };
    char array2[5][20]={0, };
    char string[30] = {0, };
    int cmp[10];
    int i=0, j=0, k=0, n=0, p=1;
    int minlen=100;
    int index=0;
    printf("input:" );
    for(i = 0; i < 5; i++)
    {
       scanf("%s",array[i]);
    }
	

	for(i = 0; i < 5; i++)
	{
		if(cmp[i] < minlen)
		{
			minlen=cmp[i];
		}
		//	array2[i]=array[i];
	
	}
	strcpy(array2[0],array[0]);
	for(i = 1; i < 5 ; i++)
	{
		if(cmp[i] > minlen)
		{
			strcpy(array2[i],array[i]);
		}
		if(cmp[i] == minlen)
		{
			while(cmp[i-p] == minlen) 
			{
				for(n = 0; n < 10 ; n++)
				{
					if(strcmp(array[i-n],array2[i-p]) == -1)
					{
						strcpy(string,array2[i-p]);
						strcpy(array2[i-p],array[i-n]);
						strcpy(array2[i-n],string);
						p++;
					}


					else if(strcmp(array[i-n],array2[i-p]) == 1)
					{
						strcpy(array2[i],array[i]);
					}

				}		
			}

		}


		p=1;
	}
	
			
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 20; j++)
		{
			printf("%c",array2[i][j]);
		}
		printf("\n");
	}

	printf("\n");    
        
    return 0;
}
