#include <stdio.h>
#include <string.h>
int main()
{
	char word[50][50] ={0,};
	char str[50] = {0,};
	int k =0;
	int i;
	int j =0;
	fgets(str,sizeof(str),stdin);		

	size_t len = strlen(str) - 1;		
	
	for(i = 0; i < len+1; i++)		
	{
		if( str[i] != 'x' && str[i] != '\n')				
		{
			word[k][j] = str[i];		
			j++;
		}
		else if( str[i] == 'x')	
		{
			k++;
			j=0;		
		} 
		else if( str[i] == '\n' && str[i-1] != 'x')
		{
			k++;
			j=0;
		}
	}

	int min_index;
	char min;
	int o;
	for(o =0; o < k; o++)			
	{
		min = word[o][0];		 
		min_index = o;
		for(j = 0; j < k; j++)		
		{
			if(min >= word[j][0])
			{
				min = word[j][0];
				min_index = j;
			}
		}
		printf("%s ",word[min_index]);	
		word[min_index][0] = 'z'; 
	}
}
