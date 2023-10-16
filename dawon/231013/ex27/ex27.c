#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[11] = {'\0', };
	char num[11] = {'\0', };
	int i = 0, count = 0, index = 0, a = 0;

	printf("arr: ");
	fgets(arr,sizeof(arr),stdin);
	while(getchar() != '\n');

	printf("num: ");
	fgets(num,sizeof(num),stdin);
	num[strlen(num) - 1] = '\0';

	printf("arr: %s\n",arr);
	printf("num: %s\n",num);

	for(i = 0; i < 10; i++)
	{
		if(num[index] != arr[i])
		{
			index = 0;
			printf("i: %d\n",i);
			if(i != 0)
				i--;
		}
		else
		{
			index;
			index++;

			if(num[index] == '\0')
			{				
				count++;
				index = 0;
				i--;
			}
		}
	}


	printf("Output: %d\n",count);
	 
	return 0;
}


