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
	fgets(str1, sizeof(str1), stdin);		//fs gd etd

	char *ptr1 = strtok(str1, " ");			//
	while (ptr1 != NULL)					//
	{
		size_t len1= strlen(str1);			//use size_t when use srtlen
		if(str1[len1 -1] == '\n')
		{
			str1[len1 -1] = '\0';
		}
		strcpy(word1[i], ptr1);
		printf("word1[%d] is %s\n",i, word1[i]);
		ptr1 = strtok(NULL, " ");
		i++;				//i =3
	}
		
	printf("input s2: \n");
	fgets(str2, sizeof(str2), stdin);		//fs'\n'

	char *ptr2 = strtok(str2, " ");
	while (ptr2 != NULL)
	{
		size_t len2= strlen(str2);
		if(str2[len2 -1] == '\n')
		{
			str2[len2 -1] = '\0';
		}
		strcpy(word2[k], ptr2);
	printf("word2[%d] is %s\n",k, word2[k]);
		ptr2 = strtok(NULL, " ");
		k++;				//k= 5
	}

//ok	printf("i, k is %d %d ", i, k);

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
	printf("count is %d\n", count);

/*
	printf("word1[0][0] is %c\n", word1[0][0]);
	printf("word1[0][1] is %c\n", word1[0][1]);
	printf("word1[0][2] is %c\n", word1[0][2]);
	printf("word1[0][3] is %c\n", word1[0][3]);

	printf("word1[1][0] is %c\n", word1[1][0]);
	printf("word1[1][1] is %c\n", word1[1][1]);
	printf("word1[1][2] is %c\n", word1[1][2]);
	printf("word1[1][3] is %c\n", word1[1][3]);


	printf("word1[2][0] is %c\n", word1[2][0]);
	printf("word1[2][1] is %c\n", word1[2][1]);
	printf("word1[2][2] is %c\n", word1[2][2]);
	printf("word1[2][3] is %c\n", word1[2][3]);	
	printf("word1[2][4] is %c\n", word1[2][4]);

	printf("word2[0][0] is %c\n", word2[0][0]);
	printf("word2[0][1] is %c\n", word2[0][1]);
	printf("word2[0][2] is %c\n", word2[0][2]);
	printf("word2[0][3] is %c\n", word2[0][3]);	// '\n'
*/
}

