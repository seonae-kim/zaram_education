#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[50] = { 0, };
	char str2[50] = { 0, };
	fgets(str1, sizeof(str1), stdin);	//str1= 2021, 12, 28
	fgets(str2, sizeof(str2), stdin);	//str2= 2021, 12, 29

	if (strcmp(str1, str2) == -1)
	{
		printf("%d", 1);
	}
	else
	{
		printf("%d", 0);
	}
}