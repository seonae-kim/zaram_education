#include<stdio.h>

int main()
{
	int n = 0;
	char str[10] = {0};
	printf("Please enter the int num : ");
	scanf("%d", &n);
	
	sprintf(str, "%d", n);
	printf("Change int to str\n");
	printf("%s\n", str);
	return 0;
}
