#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[20] = {'\0', };
	int n = 0, i = 0, min = 100, sub = 0, index = 0, minval = 0;
	char iarr[3] = {'\0', };
	char *ptr;

	printf("arr: ");
	fgets(arr,sizeof(arr),stdin);
    arr[strlen(arr) - 1] = '\0';
	
	
	printf("n: ");
	scanf("%d",&n);
	
	ptr = strtok(arr," ");
	while(ptr != NULL)
    {
		sprintf(iarr,"%s",ptr);
		
		if(atoi(iarr) >= n)
			sub = atoi(iarr) - n;

		else
			sub = n - atoi(iarr);

		if(sub < min)
		{
			min = sub;
			minval = atoi(iarr);

		}

		memset(iarr,'\0',sizeof(char) * 3);
		ptr = strtok(NULL," ");

	}

	printf("result: %d\n",minval);

	return 0;

}




	

