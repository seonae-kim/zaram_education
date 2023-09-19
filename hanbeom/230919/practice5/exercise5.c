#include <stdio.h>
#include <string.h>

int main()
{
	char str1[50] = {0,};
	char str2[50] = {0,};
	char word1[500][500];
	char word2[500][500];
	int i= 0;
	int k = 0;

	printf("input s1: \n");
	fgets(str1, sizeof(str1), stdin);

	char *ptr1 = strtok(str1, " ");
	while (ptr1 != NULL)
	{
		strcpy(word1[i], ptr1);
//		printf("word1 is %s\n", word1[i]);
		ptr1 = strtok(NULL, " ");
		i++;				//i =3
	}

		
	printf("input s2: \n");
	fgets(str2, sizeof(str2), stdin);

	char *ptr2 = strtok(str2, " ");
	while (ptr2 != NULL)
	{
		strcpy(word2[k], ptr2);
//		printf("word2 is %s\n", word2[k]);
		ptr2 = strtok(NULL, " ");
		k++;				//k= 5
	}

//	printf("i, k is %d %d ", i, k);

	int a, b;
	int count= 0;
	for(a =0; a < i; a++)
	{
		for(b = 0; b < k; b++)
		{
			if(strcmp(word1[a], word2[b]) == 0)
			{
				count++;
			}
		}
	}
	printf("count is %d", count);
}

