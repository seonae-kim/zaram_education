#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	char ch;

	if ((fp = fopen("basic.txt","w")) == NULL)		//파일이 없거나 용량 부족해서 파일 열기or파일 생성이 불가한 경우
	{
		printf("파일이 열리지 않습니다\n");
		exit(1);		// 인자가 0이면 정상 종료, 인자가 1이면 비정상 종료
	}

	printf("문자 하나를 입력하세요. \n");
	ch = getchar();

	while (ch != 'q')		//q 입력하기 전까지
	{
		fputc(ch, fp);		// 입력받은거 출력하고
		ch = getchar();		//다시 입력받음
	}
	printf("파일 입력이 종료되었습니다. \n");
}