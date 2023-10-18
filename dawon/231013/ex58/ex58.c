#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int date1[3], date2[3];
	int i = 0, result = 0;

	printf("date1: ");
	for(i = 0; i < 3; i++)
	{
		scanf("%d",&date1[i]);
	}

	printf("date2: ");
	for(i = 0; i < 3; i++)
	{
		scanf("%d",&date2[i]);
	}

	if(date1[0] > date2[0])
		result = 0;

	else if(date1[0] < date2[0])
		result = 1;

	else if(date1[0] == date2[0] && date1[1] > date2[1])
		result = 0;
	
	else if(date1[0] == date2[0] && date1[1] < date2[1])
		result = 1;

	else if(date1[0] == date2[0] && date1[1] == date2[1] && date1[2] > date2[2])
		result = 0;

	else if(date1[0] == date2[0] && date1[1] == date2[1] && date1[2] < date2[2])
		result = 1;

	else 
		result = 0;

	printf("result: %d\n",result);

	return 0;

}



