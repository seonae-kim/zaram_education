#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[50] = { 0, };
	int	count = 0;
	int count_x = 0;
	int arr[50] = { 0, };
	int i;
	int k = 0;
	fgets(str, sizeof(str), stdin);		

	size_t len = strlen(str) - 1;		

	for (i = 0; i < len + 1; i++)			   
	{
		if (str[i] != 'x' && str[i] != '\n')		
		{
			count++;
		}
		else if (str[i] == 'x')
		{
			arr[k] = count;
			count = 0;
			k++;
		}
		else if (str[i] == '\0' || str[i] == '\n')		
		{
			arr[k] = count;
		}
	}

	for (i = 0; i < k+1; i++)			
	{
		printf("%d ", arr[i]);			
	}
}
