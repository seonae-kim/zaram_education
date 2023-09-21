#include <stdio.h>
#include <string.h>
int main()
{
	char word[50][50] ={0,};
	char copy[50][50] ={0,};
	char str[50] = {0,};
	int k =0;
	int i;
	int j =0;
	fgets(str,sizeof(str),stdin);		//abxaxabx

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
/*
	for(i = 0; i < k; i++)
	{
		printf("%s\n", word[i]);		//word[0] = ab, word[1]= a, word[2] = ab
	}
*/	

	for( i =0; i <k; i++)
	{
		if( strcmp(word[i],word[i+1]) < 0)
		{
			//pass
		}
		else if (strcmp(word[i],word[i+1]) >0)
		{
			/*
			copy[i] = word[i];				//change word[i] <> word[i+1]
			word[i] = word[i+1];
			word[i+1] = word[i];
			*/


		}
	}

	//printf("%d", strcmp(word[0],word[1]));
}
