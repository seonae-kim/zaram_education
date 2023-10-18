#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char t[20] = {'\0', };
	char p[10] = {'\0', };
	char arr[10] = {'\0', };
	int i = 0, j = 0, count = 0, index = 0, pint=0, arrint = 0;

	printf("t: ");
	scanf("%s",t);

	printf("p: ");
	scanf("%s",p);
	pint = atoi(p);

	for(i = 0; i <= strlen(t) - strlen(p); i++)
	{
		for(j = i; j < i + strlen(p); j++)
		{
			arr[index++] = t[j];
		}
		arrint = atoi(arr);
		if(arrint <= pint)
			count++;
		index = 0;
		memset(arr, '\0', sizeof(char) * 10);
	}

	printf("result: %d\n",count);

	return 0;

}






