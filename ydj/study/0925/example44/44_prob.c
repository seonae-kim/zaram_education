#include<stdio.h>
#include<string.h>

int main()
{
	int	str_n = 0, pat_n = 0;
	int i = 0, j = 0, order = 0, flag = 0;
 	printf("Please enter the # of element for string : ");
	scanf("%d", &str_n);
	char str[str_n];
	printf("Please enter the string : ");
	scanf("%s", str);

 	printf("Please enter the # of element for pat : ");
	scanf("%d", &pat_n);
	char pat[pat_n];
	printf("Please enter the pat : ");
	scanf("%s", pat);

	for (i = 0; i < str_n; i++)
	{
		if (str[i] == 'A')
		{
			str[i] = 'B';
		}
		else if (str[i] == 'B')
		{
			str[i] = 'A';
		}
	}
//	printf("%s\n", str);
//	printf("%ld\n", strlen(pat));
//	printf("%c", str[0]);
//	printf("%c", pat[0]);
	for (i = 0; i < str_n; i++)
	{
		for (j = 0; j < pat_n; j++)
		{
			if (str[i + j] == pat[j])
			{
				order++;
			}
			if (order == pat_n)
			{
				flag = 1;
			}
		}
//		printf("%d, ", flag);
//		printf("%d. \n ", order);
		order = 0;
	}


	if (flag == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

	return 0;
}
