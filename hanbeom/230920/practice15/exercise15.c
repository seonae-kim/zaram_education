#include <stdio.h>
#include <string.h>
int main()
{
	char str[50] ={0,};
	char alp;
	int i;

	printf("input str:\n");
	fgets(str,sizeof(str),stdin);	//programmers
	
	printf("input alp:\n");
	scanf("%c", &alp);	//p

	size_t len = strlen(str) - 1;
	for(i = 0; i < len; i++)
	{
		if(str[i] == alp && str[i] >= 'a' && str[i] <= 'z')
		{ 
			str[i] -= 32;
		}
		else if(str[i] != alp && str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}

	for(i =0; i< len; i++)
	{
		printf("%c", str[i]);
	}
}
