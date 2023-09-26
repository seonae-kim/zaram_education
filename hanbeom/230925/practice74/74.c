#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char str[50] = { 0, };
	int p;
	int numarr[50] = { 0, };
	int i, j;
	printf("input str:\n");
	fgets(str, sizeof(str), stdin);	

	printf("input p:\n");
	scanf("%d", &p);				

	int len = strlen(str) - 1;		
	int num = p;
	int size = 0;
	while (p >= 10)
	{
		p /= 10;
		size++;
	}

	size = size + 1;

	for (i = size - 1; i >= 0; i--)
	{
		numarr[i] = num % 10;
		num /= 10;
	}
	char strarr[50] = { 0, };
	for (i = 0; i < size; i++)
	{
		strarr[i] = numarr[i] + '0';
	}
	int count = 0;
	int same = 0;
	for (i = 0; i < len - size + 1; i++)	
	{
		for (j = 0; j < size; j++)			
		{
			if (str[j + i] > strarr[j])
			{
				break;
			}
			else if (str[j + i] == strarr[j])
			{
				same++;
			}
			else if (str[j + i] < strarr[j])
			{
				count++;
				break;
			}
		}
		same = 0;
	}
	if (same == size - 1)
	{
		count++;
	}
	printf("%d", count);

}

