#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS             

int main()
{

	int x;

	printf("양수를 입력하세요.\n");
	scanf_s("%d", &x);

	(x >= 0) ? printf("x는 유효한 값입니다.\n") : printf("x는 유효한 값이 아닙니다.\n");


}

