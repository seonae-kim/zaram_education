#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS             

int main()
{
	int input;

	printf("%아침 인사는 1번을 누르세요.\n");
	printf("%점심 인사는 2번을 누르세요.\n");
	printf("%저녁 인사는 3번을 누르세요.\n");
	scanf_s("%d", &input);


	switch (input)
	{
		case 1 :
			printf("good morning\n");
			break;		//case문 빠져나옴
		case 2 :
			printf("good afternoon\n");
			break;
		case 3:
			printf("good night\n");
			break;
	}

}

