#include <stdio.h>
#include <string.h>		//추가
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char cmp1[40] = "C programming";
	char cmp2[] = "java programming";
	char cmp3[] = "C programming";
	char str[] = "is easy";

	int length, i;
	length = strlen(cmp1);			//strlen

	for (i = 0; i < length; i++)
		printf("%c", cmp1[i]);

	printf("\n");
	printf("cmp1과 cmp2는 서로 %s\n", strcmp(cmp1, cmp2) ? "같지않다." : "같다.");		//strcmp에서 비교한 값이 동일하면 0 반환 (그래서 False에 "같다")
	printf("cmp1과 cmp3는 서로 %s\n", strcmp(cmp1, cmp3) ? "같지않다." : "같다.");		//strcmp에서 비교한 값이 동일하면 0 반환 (그래서 False에 "같다")
	printf("cmp1에 cmp2를 복사하면\"%s\"이 출력된다.\n", strcpy_s(cmp1, cmp2));			//strcpy
	printf("cmp1에 str를 연결하면\"%s\"가 출력된다.\n", strcat_s(cmp1, str));				//strcat
	return 0;
}