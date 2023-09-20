/* 5 * 5 배열이 선언되어 있다.
   5개의 단어를 입력받는다. (단어의 길이는 5를 넘어선 안된다)
   이때 세로로 읽은 경우의 결과를 출력하세요. (빈칸은 무시한다)
*/
#include <stdio.h>
#include <string.h>

#define SIZE 50
int main(void)
{
    char str[SIZE] = {0};
    char *div_str[5] = {0};
    int len[5] = {0};
    int i = 0, j = 0, k = 0, o = 0;
    
	gets(str);
	
	if(str == NULL)
	{
		printf("err");
		return 0;
	}
	
	if(strlen(str) > SIZE)
	{
		printf("문장의 길이가 너무 깁니다(50자이하)");
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
		if(len[j] > 5)
		{
			printf("단어의 길이는 5이상입니다\n");
			return 0;
		}
	}
	
	for(k = 0; k < i; k++)
	{
		for(o = 0; o < i; o++)
		{
			if (div_str[o][k] == '\0')
			continue;
			printf("%c",div_str[o][k]);
		}
	}
	return 0;
}
