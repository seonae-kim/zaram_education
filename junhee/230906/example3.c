#include <stdio.h>

int dec(char str[]);
int main()
{
	char str[10];
	
	scanf("%s",str);
	if (dec(str)==1)
	{
		printf("ok");
	}
	
	else
	{
		printf("no");
	}
	
	return 0;	
}


int dec(char str[])
{
	int opcount = 0;
	int clcount = 0;
	int in = 0;
	for(int i = 0; i < 10; i++)
	{
		char prChar = str[i];
		if(prChar=='(')
		{
			opcount++;
		}
		else if(prChar==')')
		{
			clcount++;
		}
	}
	if(clcount < opcount)
	{
		return 0;
	}
	
	else if(clcount > opcount)
	{
		return 0;
	}
	else if (str[0] == ')' || str[opcount + clcount - 1] == '(')
	{
		return 0;
	}
	for (in = 0; str[in] != NULL; in++)
	{
		if(str[in]=='(')
		opcount --;
		else 
		clcount --;
		
		if(opcount > clcount)
		return 0;
	}

	return 1;
}
