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
	int temp_i[20] = {0};
	int num[20] = {0};
	printf("Please enter the string : ");
	fgets(str, sizeof(str), stdin);

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{	
			len = 1;
			temp_c[k] = str[i];
//			printf("%c,,,", temp_c[k]);
			j = i + 1;
			while (str[j] <= '9' && str[j] >= '0')
			{
				k++;
				temp_c[k] = str[j];
//				printf("%c,, ", temp_c[k]);
				j++;
				len++;
			}
			num[l] = atoi(temp_c);
			memset(temp_c, '0', 5 * sizeof(char));
//			printf("%d, ", num[l]);
			l++; 
		}
		k = 0;
	}

	// find & remove  duplicated num
	for (i = 0; i < l; i++)
	{
		flag = 0;
		for(j = i + 1; j < l; j++)
		{
			if(num[i] == num[j])
			{	
				flag++;
				break;
			}
		}
		if(flag == 0)
		{
			temp_i[k] = num[i];
			k++;		
		}
	}

	// to line num
	for (i = 0; i < k; i++)
	{
		for(j = i + 1; j < k; j++)
		{
		 	if(temp_i[i] > temp_i[j])
			{
				temp = temp_i[j];
				temp_i[j] = temp_i[i];
				temp_i[i] = temp;
			}
		}
	}

	// print
	for(i = 0; i < k; i++)
	{
		printf("%d ", temp_i[i]);
	}
	printf("\n");
	return 0;
}
