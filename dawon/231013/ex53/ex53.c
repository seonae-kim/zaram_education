#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char mystr[20] = {'\0', };
	char c;
	int num1, num2;

	printf("mystr: ");
	fgets(mystr,sizeof(mystr),stdin);

	printf("num1: ");
	scanf("%d",&num1);

	printf("num2: ");
	scanf("%d",&num2);

	c = mystr[num1];
	mystr[num1] = mystr[num2];
	mystr[num2] = c;

	printf("%s\n",mystr);

	return 0;

}


	
