#include<stdio.h>

int main()
{
	int hour, min;
	printf("Please input time : ");
	scanf("%d %d", &hour, &min);

	min = min + 35;
	
	if (min > 60)
	{
		min = min - 60;
		hour = hour + 1;
		if (hour >= 24)
		{
			hour = hour - 24;
		} 
	}
	printf("%d %d \n", hour, min);
}
