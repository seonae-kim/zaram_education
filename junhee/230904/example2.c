#include <stdio.h>
#define arrSIZE 15
int main()
{
	
	int num[arrSIZE] = {0};
	int maxnum =0;
	int history [arrSIZE]={0}; 
	int s=0;
	int count=0;
		
	for(int i=0; i<arrSIZE; i++)
	{
		scanf("%d",&num[i]);
	}
	
	for(int i=0; i<arrSIZE; i++)
	{	
		if(num[i] == 0)
		{
			for(int j = 0; j<i; j++)
			{
				if(num[j]>maxnum)
				{
					maxnum=num[j];
					s=j;
				}
			}
			num[s]=0;
			history[count]=maxnum;
			maxnum=0;
			count++;
		
		}
	}
	for(int i=0; i<count; i++)
	{
		printf("%d", history[i]); 
	}
	return 0;	
}
