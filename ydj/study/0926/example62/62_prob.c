#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int i = 0, j = 0, k = 0, l = 0;
	int len = 1;
	int flag = 0, temp = 0;
	char str[100] = {0};
	char temp_c[20] = {0};
	int num[20] = {0};
    int sum = 0;
	printf("Please enter the string : ");
	fgets(str, sizeof(str), stdin);

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{	
			len = 1;
			temp_c[k] = str[i];
			i = i + 1;
			while (str[i] <= '9' && str[i] >= '0')
			{
				k++;
				temp_c[k] = str[i];
				i++;
				len++;
			}
			num[l] = atoi(temp_c);
			memset(temp_c, 0, 20 * sizeof(char));
			l++; 
		}
		k = 0;
	}

    for (i = 0; i < l; i++)
    {
        sum = sum + num[i];
    }

    printf("%d", sum);
	return 0;
}