#include<stdio.h>
#include<string.h>

int main()
{
	int i = 0, j = 0;
	int len1 = 0, len2 = 0;
	printf("Please enter str1 legth : ");
	scanf("%d", &len1);
	printf("Please enter str2 legth : ");
	scanf("%d", &len2);

	char str1[len1][10];
	char str2[len2][10];

	int count = 0;
	printf("Please enter s1 : ");

	for (i = 0; i < len1; i++)
	{
		scanf("%s", str1[i]);
	}

	printf("please enter s2 : ");
	for (i = 0; i < len2; i++)
	{
		scanf("%s", str2[i]);
	}
	
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (strcmp(str1[i], str2[j]) == 0)
			{
				count++;
			}
		}
	}
	
	printf("%d\n", count);

	return 0;
}
