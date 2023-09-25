#include <stdio.h>
#include <string.h>

int main()
{
	char str1[50] = {0,};
	char str2[50] = {0,};
	int i, j;
	int countarr[50] = {0,};
	int k = 0;

	printf("input str1:\n");		
	fgets(str1,sizeof(str1),stdin);

	printf("input str2:\n");		
	fgets(str2,sizeof(str2),stdin);

	size_t len1 = strlen(str1) - 1;		
	size_t len2 = strlen(str2) - 1;		
	int count =0;

	for(i =0; i < (len1 - len2) +1; i++)		
	{
		for(j=0; j < len2; j++)
		{
			if(str1[i+j] == str2[j])
			{
				count++;
			}
			else
			{
				count= 0;
			}
		}	
		if(count == len2)
		{
			countarr[k] = (i + len2) -1;		
			count = 0;
			k++;
		}
	}
	for(i = 0; i <= countarr[k -1]; i++)
	{
		printf("%c", str1[i]);			
	}
}
