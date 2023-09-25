#include<stdio.h>
#include<stdlib.h>

int main()
{
	char str[10] = {0};
	int str_int = 0;
	printf("Please enter the string : ");
	scanf("%s", str);
	str_int = atoi(str);

	printf("Change char to int\n");
	printf("%d\n", str_int);
	return 0;
}
