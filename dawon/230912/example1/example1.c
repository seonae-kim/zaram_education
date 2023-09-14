#include <stdio.h>
#include <string.h>

int main()
{
    char array[5][20]={0, };
    char array2[5][20]={0, };
    char string[30] = {0, };
    int cmp[10]={0, };
    int i=0, j=0, k=0, n=0, p=1, m;
    int len=100;
    int index=0, index2=0;
    printf("input:" );

    for(i = 0; i < 5; i++)
    {
       scanf("%s",array[i]);
    }

	for(i = 0; i < 5; i++)
	{
		cmp[i]=strlen(array[i]);
	}

/*	for(i = 0; i < 5; i++)
	{
		if(cmp[i] < len)
		{
			len=cmp[i];
			index2=i;
		}
	}
*/
	for(i = 0; i < 5 ; i++)
	{
	/*	if(i == index2)
			continue;
	*/		
		if(cmp[i] > len)
		{
			strcpy(array2[i],array[i]);
			
		}
		if(cmp[i] == len)
		{
			while(cmp[i-p] == len) 
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


				/*	else if(strcmp(array[i-n],array2[i-p]) == 1)
					{
						strcpy(array2[i],array[i]);
				
					}
					*/
				}		
			}
			p=1;
		}
		if(cmp[i] < len)
		{
			p=0;
			if(i==0)
			{
				strcpy(array2[i],array[i]);
				continue;
			}

			k=i-1;
			while(cmp[k] == len)
			{
				k--;
			}
			for(n = 0; n < i-k ; n++)
			{
					strcpy(array2[i-p],array2[i-n]);
					p++;
			}
		    strcpy(array2[k],array[i]);
			if(strlen(array2[k]) == strlen(array2[k-1]))
			{
				m=1;
				while(strlen(array2[k-m]) == strlen(array2[k]))
				{
					for(n = 0; n < 10 ; n++)
					{
						if(strcmp(array2[k],array2[k-m]) == -1)
						{
							strcpy(string,array2[k-m]);
							strcpy(array2[k-m],array[k-n]);
							strcpy(array2[k-n],string);
							m++;
						}

					}
				


				}
			}		
	
		}
		len=cmp[i];
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
