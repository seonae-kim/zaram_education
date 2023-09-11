#include <stdio.h>
int main()
{
	char* pStr[] = { "english", "math", "korean" };		//포인터 배열
	char subject[][8] = { "english", "math", "korean" };	//2차원 배열
	int i;

	printf("포인터 배열을 이용해 문자열 출력.\n");
	for (i = 0; i < 3; i++)
		printf("pStr[%d] = %s\n", i, pStr[i]);		//pStr[0] pStr[1] pStr[2]

	printf("이차원 배열을 이용해 문자열 출력.\n");
	for (i = 0; i < 3; i++)
		printf("subject[%d] = %s\n", i, subject[i]);	//subject[0] subject[1] subject[2]
}