#include<stdio.h>
int main()
{
	int i = 0, j = 0, flag = 0;
	int n = 0;
	char temp_c[10];
	int temp_len = 0;
	char temp = 0;
	printf("Please enter the # of element : ");
	scanf("%d", &n);

	char str[n];
	printf("Please enter the string : ");
	scanf("%s", str);

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (str[i] == str[j])
			{
				str[j] = '0';
				flag = 1;
			}
		}
		
		if (flag == 1)
		{
			str[i] = '0';
		}
		flag = 0;
	}

	j = 0;
	for (i = 0; i < n; i++)
	{
		if (str[i] != '0')
		{
			temp_c[j] = str[i];
			j++;
		}
	}
	temp_len = j;
	
	for (i = 0; i < temp_len; i++)
	{
		for(j = i + 1; j < temp_len; j++)
		{
			if (temp_c[i] > temp_c[j])
			{
				temp = temp_c[i];
				temp_c[i] = temp_c[j];
				temp_c[j] = temp;
			}
		}
	}
	printf("%s\n", temp_c);
	return 0;
}
