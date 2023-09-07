#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int hour,min=0;

	scanf("%d %d",&hour,&min);
	printf("input: %d %d  ",hour,min);

	min=min+35;
		
	if((min)>60)
	{
		hour=hour+1;
		if(hour>=24)
		{
			hour=hour-24;
		
		}
		min=min-60;
	
	}

	printf("output: %d %d\n", hour,min);
	return 0;

}
