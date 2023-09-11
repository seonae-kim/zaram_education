#include <stdio.h>

int main()
{
	char *pC = "c language";	//포인터로 문자열 표현

	while (*pC)		//null 전까지
	{
		printf("%c", *pC-32);		//소문자를 대문자로
		pC++;
	}
	printf("\n");
}