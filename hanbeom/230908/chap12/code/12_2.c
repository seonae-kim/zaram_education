#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LINE 30

int main()
{
	FILE* fp1, * fp2;		//fp1, fp2 둘다 포인터형
	char line[LINE];	//문자 배열

	fp1 = fopen("lineInput.txt", "r");

	if (fp1 == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		exit(1);
	}

	fp2 = fopen("linetarget.txt", "w");

	while (fgets(line, LINE, fp1) != NULL)		//입력받은 문자열이 NULL이 아닐떄까지 (fp1이 가리키는 파일의 문자열을 line에 넣음)
		fputs(line, fp2);			//fp2이 가리키는 파일에, 문자 배열 line이 들어간  

	fclose(fp1);
	fclose(fp2);

	return 0;
}