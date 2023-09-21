#include <stdio.h>
#include <string.h>

int main()
{
	char str[50] ={0,};
	int count =0;
	int i;
	int j;

	fgets(str,sizeof(str),stdin);

	size_t len = strlen(str) - 1;

	for(i = 0; i < len; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(str[i] == str[j])
			{
				count++;
			}
		}
		if(count ==0)
		{
			printf("%c", str[j]);
		}
		count = 0;
	}
}
