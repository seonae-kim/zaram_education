#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS             

int main()
{

	int i, j, count = 0;			//i   j= 나누는 수

	for (i = 2; i <= 100 ; i++) 					//2~ 100		
	{
		for (j = 2; j <= i; j++)			// <가 아니라 <=     
		{
			if (i % j == 0)			//소수 판별
				break;
		}


		if (j == i)						
		{
			count++;					//소수 찾으면 count 올라감
			printf("%d%s", i, (count % 5) ? " " : "\n");			//소수 5개 찾을때마다 밑줄로. 
		}															//(count % 5) 값이 0이면 false. 0 아니면 True
	}
		
	
}

