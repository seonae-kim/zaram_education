/*5개의 단어를 입력받는다. (단어의 길이는 10을 넘지 않는다)
단어의 길이가 짧은것 부터 출력하며, 길이가 같은 경우 사전 순으로 출력한다.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

void sort_word(char** word, int *len, int a)
{

	int tmp_num = 0;
	char* tmp_word;
	int i = 0, j = 0;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			if ( len[i] < len[j] )
			{
				tmp_num = len[i];
				tmp_word = word[i];
				
				len[i] = len[j];
				word[i] = word[j];
				
				len [j] = tmp_num;
				word[j] = tmp_word;
			}
			if ( len[i] == len[j] )
			{
				if (strcmp(word[i],word[j]) < 0)
				{
					tmp_word = word[i];
					word[i] = word[j];
					word[j] = tmp_word;
				}
			}
		}
	}
}
int main(void)
{
    char str[SIZE];
    char *div_str[5];
    int len[5];
    int i = 0, j = 0, o = 0;
    
	gets(str);
	if(str == NULL)
	{
		printf("err");
		return 0;
	}
	
	char *ptr = strtok(str," ");
	div_str[i] = ptr;
	while (ptr != NULL)
    {
    	i++;
    	
    	if(i > 5)
    	{
    		printf("단어가 5개 이상입니다"); 
    		return 0;
    	}
        ptr = strtok(NULL, " ");
        div_str[i] = ptr;
    }
    
	for (j = 0; j < i; j++)
	{
		len[j] = (int)strlen(div_str[j]);
		if(len[j] > 10)
		{
			printf("단어의 길이는 10이상을 넘으면 안됩니다\n");
			return 0;
		}
	}
	sort_word(div_str, len, i);
	for (o = 0; o < i; o++)
	{
		printf("%s ", div_str[o]);
	}
    return 0;
}
