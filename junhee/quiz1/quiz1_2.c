#include <stdio.h>

int main(void)
{
	int hour,min=0;
	
	scanf("%d %d",&hour,&min);
	if(hour>24||min>60)
	{
		printf("잘못 입력하셨습니다");
		return 0;
	}
	min+=35;
	if (min>60)
	{
		hour+=1;
		min-=60;
		if(hour>23)
		{
			hour-=24;
		}
	}
	printf("%d %d", hour, min);
	
	return 0;	
}
