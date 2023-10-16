#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', };
	int indexlist[20] = {0, };
	char rstr[20] = {'\0', };

	int n = 0, index = 0, i = 0;
	
	printf("mystring: ");
	scanf("%s",mystr);

	printf("num: ");
	scanf("%d",&n);

	printf("index list: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&indexlist[i]);
	}

	for(i = 0; i < n; i++)
	{
		rstr[index++] = mystr[indexlist[i]];
	}

	printf("%s\n",rstr);
	return 0;

}


	
