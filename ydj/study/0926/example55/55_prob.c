#include<stdio.h>
#include<string.h>

int main()
{
	
	int i = 0, j = 0;
	int x = 0;

	char myString[15] = {0};
	char temp[10] = {0};
	char *slice[10] = {0};

	printf("Please enter the string : ");
	scanf("%s", myString);

	char *ptr = strtok(myString, "x");

	i = 0;
	while (ptr != NULL)
	{
		slice[i] = ptr;
		i++;
		ptr = strtok(NULL, "x");
	}
	
	x = i;
	for (i = 0; i < x; i++)
	{
		for (j = i + 1; j < x; j++)
		{
			if (strcmp(slice[i], slice[j]) > 0)
			{
				strcpy(temp, slice[i]);
				strcpy(slice[i], slice[j]);
				strcpy(slice[j], temp);
			}
		}
	}
	
	for (i = 0; i < 10; i++)
	{
		if (slice[i] == NULL)
		{
			continue;
		}
		printf("%s ", slice[i]);
	}
	printf("\n");

	/*
	for (i = 0; i < strlen(myString); i++)
	{
		if (myString[i] == 'x')
		{
			for (j = )
		}
	}

	for (i = 0; i < strlen(index) + 1; i++)
	{
		for (j = index[i]; j < index[i + 1]; j++)
		{
			slice[k] = myString[j];
			k++;
		}
		printf()
	}
	*/
	




/*
	int i = 0, j = 0;
	int n = 0;
	printf("Please enter the length of string : ");
	scanf("%d", &n);

	char str[n];
	char str_slice[n + 1];
//	char *str_slice[10] = {0};
//	char *temp[10] = {0}; 

	printf("Please enter the string : ");
	scanf("%s", str);

	char *ptr = strtok(str, "x");
	while (ptr != NULL)
	{
		strcpy(str_slice[i], ptr);
//		str_slice[i] = ptr;
		i++;
//		printf("%s\n", ptr);
		ptr = strtok(NULL, "x");
	}
	
	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (str_slice[i] != NULL && str_slice[j] != NULL)
			{
				if (strcmp(str_slice[i], str_slice[j]) > 0)
				{
					printf("%s ", str_slice[j]);
//					str_slice[j] = NULL;
				}
			}
		}
	}
	
*/


/*	
	for (i = 0; i < 10; i++)
	{
		if (str_slice[i] != NULL)
		{
			printf("%s\n", str_slice[i]);
		}
	}
*/
	

//	printf("%s", str_slice[1]);

	/*
	char str[n];
	for (i = 0; i < n; i++)
	{
		if (str[i] == 'x')	
		{
			cnt++;
		}
	}
	
	int x_loc[cnt];
	cnt = 0

	for (i = 0; i < n; i++)
	{
		if (str[i] == 'x')	
		{
			x_loc[cnt] = i;
			cnt++;
		}
	}
	
	for (j = 0; j < )
	*/
	return 0;
}
