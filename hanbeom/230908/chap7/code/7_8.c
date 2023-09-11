#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int i;
	char str[4] = { 'A', 'B', 'C', '\0'};	// \0 = 문자열의 끝(Null)
	char student[] = "John";		

	printf("문자열을 동시에 출력하는 경우\n");
	printf("학생의 이름은 %s이다. \n\n", student);		//문자열 출력 "%s"
	printf("문자열을 한 글자씩 출력하는 경우\n");

	for (i = 0; str[i] != '\0'; i++)	// 문자열의 끝 도달할때까지 루프돌아감
	{
		printf("%c\n", str[i]);		//문자열 안의 문자 한개씩 출력  "%c"
	}
}