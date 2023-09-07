#include <stdio.h>


int main()
{
	
	int num[10];
	int sum = 0;
	for(int i=0; i<=9; i++)
	{
		scanf("%d",&num[i]);
		}
	for(int i=0; i<=9; i++)
	{
		if(num[i] == 0)
		{
			sum-=num[i-1];
		}
		else
		sum+=num[i];
	}
	
	printf("%d",sum);
	return 0;	
}

