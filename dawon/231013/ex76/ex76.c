#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[10] = {'\0', };
	char sarr[10] = {'\0', };
	char narr[10] = {'\0', };
	int i = 0, j = 0, count = 0, result = 0, flag = 0;
	char c;
	
	printf("arr: ");
	scanf("%s",arr);

	printf("sarr: ");
	scanf("%s",sarr);

	for(j = 0; j < strlen(arr); j++)
	{
		if(strcmp(arr,sarr) == 0)
		{
			result = count;
			flag = 1;
			break;
		}
		for(i = 0; i < strlen(arr); i++)
		{
			c = arr[strlen(arr) - 1];

			if(i == strlen(arr) - 1)
			{
				narr[0] = c;
			}
			else
			{
				narr[i+1] = arr[i];
			}
		}
		count++;
		if(strcmp(narr,sarr) == 0)
		{
			result = count;
			flag = 1;
			break;
		}

	}

	if(flag != 1)
		result = -1;

	printf("result: %d\n",result);

	return 0;

}



			
		



