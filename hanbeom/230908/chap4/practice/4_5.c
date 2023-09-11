#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS             

int main()
{
	int num[3];
	int i;

	printf("정수 3개를 입력하시오: ");

	
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &num[i]);
	}
	

	printf("평균은 %f", (double)( (num[0] + num[1] + num[2]) / 3 ));

}


