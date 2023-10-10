/*3. 단어의 개수를 입력받고, 단어를 입력받는다.

다음 단어중 각 문자가 연속해서 나타나는 경우는 몇개인지 출력하세요.

ex) cabbccc 는 c가 연속하지않고 따로 나와 실패. 
ajcssee 각 단어가 연속적이므로 성공*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int main()
{
	char number[SIZE];
	char str[SIZE];
	char* words[SIZE];
	char tmp[SIZE] = {0};
	int num;
	int i,j,k,o = 0;
	int a = 0;
	int s_count = 0;
	int a_flag = 0, b_flag = 0, fail_flag = 0;
	printf("N:");
	fgets(number,sizeof(SIZE),stdin);
	num = atoi(number);
	
	fgets(str,sizeof(str),stdin);
	
	char* word = strtok(str, " ");
	while (word != NULL && a < num) 
	{
        	words[a] = word;
	        word = strtok(NULL, " ");
        	a++;
    	}
	 
	for (i = 0; i < a; i++)
	{
		a_flag = 0;
		b_flag = 0;
		fail_flag = 0;
		memset(tmp,0,SIZE);
		for( j = 0; words[i][j] != '\0'; j++)
		{
			for(k = 0; tmp[k] !='\0'; k++)
			{
				if(tmp[k] == words[i][j])
				{
					if(k-j != 1)
					{
						for (o = k; o < j; o++)
						{
							if(tmp[o] != words[i][j])
							{
								fail_flag = 1;
								break;
							}

						}
					}
				}
			}
			tmp[j] = words[i][j];
			if(fail_flag == 1)
			{
				break;
			}
		}
		if(fail_flag == 1)
		{
			num--;
		}
	}
	
	printf("%d\n", num);
	return 0;
}
