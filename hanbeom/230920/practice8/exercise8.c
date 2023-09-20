#include <stdio.h>
#include <string.h>
int main()
{
	char str[50];
	char str2[50];
	int i,j;
	int count =0;
	printf("input mystring: \n");
	fgets(str,sizeof(str),stdin);	

	size_t len = strlen(str) - 1;		

	for(i = 0; i <len; i++)
	{
		if(str[i] == 'A')
		{
			str[i] = 'B';
		}
		else if(str[i] == 'B')
		{
			str[i] = 'A';
		}
	}

	for(i = 0; i < len; i++)
	{
	}

	printf("input pat: \n");
	fgets(str2,sizeof(str2),stdin);

	size_t len2 = strlen(str2) - 1;		
	for(i = 0 ; i < len - 3; i++)
	{
		if(str[i] == str2[0] && str[i+1] == str2[1] && str[i+2] == str2[2] && str[i+3] == str2[3])
		{
			printf("1");
			count =1;
			break;
		}
	}

	if(count!=1)
	{
		printf("%d", 0);
	}
}
