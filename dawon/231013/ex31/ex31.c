#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(char **s1, char **s2, int n1, int n2);

int main()
{
	char **s1;
	char **s2;
	int n1 = 0, n2 = 0, i = 0;

	int result = 0;

	printf("n1 :");
	scanf("%d",&n1);
	printf("n2 :");
	scanf("%d",&n2);

	s1 = (int**)malloc(sizeof(int*) * n1 + 1);
	for(i = 0; i < n1; i++)
	{
		*(s1 + i) = (int*)malloc(sizeof(int) * 10);
	}

	s2 = (int**)malloc(sizeof(int*) * n2 + 1);
	for(i = 0; i < n2; i++)
	{
		*(s2 + i) = (int*)malloc(sizeof(int) * 10);
	}
		
	printf("s1: ");
	for(i = 0; i < n1; i++)
	{
//		fgets(*(s1 + i),sizeof(*(s1 + i)),stdin);
//		*(*(s1 + i) + strlen(*(s1 + i)) - 1) = '\0';
		scanf("%s",*(s1 + i));
	}
	printf("%c",*(*(s1 + i - 1) + 2));

//	while(getchar() != '\n');
	getchar();	
	printf("s2: ");

	for(i = 0; i < n2; i++)
	{
//		fgets(*(s2 + i),sizeof(*(s2 + i)),stdin);
//		*(*(s2 + i) + strlen(*(s2 + i)) - 1) = '\0';
		scanf("%s",*(s2 +i));
	}

	result = cmp(s1,s2,n1,n2);

	printf("result: %d\n",result);	

	return 0;
}

int cmp(char **s1, char **s2, int n1, int n2)
{
	int count = 0, i = 0, a = 0, min = 0, max = 0, j = 0;
	char **arr1, **arr2;

	if(n1 > n2)
	{
		min = n2;
		max = n1;
	}
	else
	{
		min = n1;
		max = n2;
	}

	
	arr1 = (int**)malloc(sizeof(int*) * min + 1);
	for(i = 0; i < min; i++)
	{
		*(arr1 + i) = (int*)malloc(sizeof(int) * 10);
	}

	arr2 = (int**)malloc(sizeof(int*) * max + 1);
	for(i = 0; i < max; i++)
	{
		*(arr2 + i) = (int*)malloc(sizeof(int) * 10);
	}
	
	if(n1 > n2)
	{
		arr1 = s2;
		arr2 = s1;
	}
	else
	{
		arr1 = s1;
		arr2 = s2;
	}

	for(i = 0; i < min; i++)
	{
		for(j = 0; j < max; j++)
		{
			if(strcmp(*(arr1+i),*(arr2+j)) == 0)
			{
				count++;
			}
		}
	}


	return count;
}


	


	




