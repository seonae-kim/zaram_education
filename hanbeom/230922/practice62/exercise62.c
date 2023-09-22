#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char arr[50] = {0,};
	char str[50] = {0,};
	int i, j;
	fgets(str,sizeof(str),stdin);	
	
	size_t len = strlen(str) - 1;
	int p=0;
	for(i =0; i <len; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')		
		{
			arr[p] = str[i];		
			p++;
		}
		else if(str[i-1] >= '0' && str[i-1] <= '9')
		{
			arr[p] = '*';
			p++;
		}
	}
	char arr2[50][50] = {0,};
	int k=0;
	int o=0;

	for(i =0 ; i < p; i++)	
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			arr2[k][o] = arr[i];
			o++;
		}
		else if (arr[i] == '*' || arr[i] == '\n')
		{
			k++;
			o = 0;
		}
	}
	int sum =0;
	for( i =0; i <k; i++)
	{
		sum += atoi(arr2[i]);
	}
	printf("%d", sum);
}
