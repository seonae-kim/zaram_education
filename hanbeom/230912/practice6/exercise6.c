#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[100];
    char word[500][500];  //2D
    char word2[100];
    int num[500] ={0,};
    int i = 0;

    printf("input the sentence: ");

    fgets(word2, sizeof(word2), stdin);
    //fgets(str, sizeof(str), stdin);
    
    char* ptr = strtok(str, " ");
    while (ptr != NULL)
    {
	strcpy(word[i], ptr);

//	printf("string is %s\n", word[i]); //
	num[i] = atof(word[i]);
//	printf("number is %d\n", num[i]); 
	ptr = strtok(NULL, " ");
	i++;
    }
    printf("character is %c\n", word[0][0]);

    //2
    
    int count =0;
    for(i = 0; i < strlen(word2) - 1; i++)
    {
//	printf("%c\n", word2[i]);

	if(word2[i] > '0' && word2[i] <'9')
	{
	    printf("%c ", word2[i]);
	}
    }

    


  //  printf("str is %s", str);
   // printf("word2 is %s", word2);
   // printf("count is %d", count);
  //  printf("strlen is %ld\n", strlen(str));


}
