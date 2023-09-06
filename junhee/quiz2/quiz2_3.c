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
	int opcount=0;
	int clcount=0;
	for(int i = 0; i<10;i++)
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
	if (opcount == clcount)
	{
		return 1;
	}
	
	else if(clcount<opcount)
	{
		return 0;
	}
	
	else if(clcount>opcount)
	{
		return 0;
	}
	else
	return -1;
}
