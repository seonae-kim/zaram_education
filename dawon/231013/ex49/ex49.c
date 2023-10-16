#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr1[10] = {'\0', };
	char arr2[10] = {'\0', };
	int i = 0, result = 0, sum1 = 0, sum2 = 0;
	char str1[10] = {'\0', }, str2[10] = {'\0', };
	char *ptr1, *ptr2;

	printf("arr1: ");
	fgets(arr1,sizeof(arr1),stdin);
	while(getchar() != '\n');

	printf("arr2: ");
	fgets(arr2,sizeof(arr2),stdin);


	if(strlen(arr1) > strlen(arr2))
	{
		result = 1;
	}

	else if(strlen(arr1) > strlen(arr2))
	{
		result = -1;
	}

	else if(strlen(arr1) == strlen(arr2))
	{
		ptr1 = strtok(arr1," ");
		while(ptr1 != NULL)
		{
			sum1 += atoi(ptr1);
			ptr1 = strtok(NULL," ");

		}
		printf("sum1: %d\n",sum1);

		ptr2 = strtok(arr2," ");
		while(ptr2 != NULL)
		{
			sum2 += atoi(ptr2);
			ptr2 = strtok(NULL," ");
		}
		printf("sum2: %d\n",sum2);
			
		if(sum1 > sum2)
			result = 1;

		else if(sum1 < sum2)
			result = -1;

		else
			result = 0;
	}
		
	printf("result: %d\n",result);

	return 0;

}





