#include <stdio.h>
int main()
{
	char* pC = "C programming";		//포인터를 이용한 문자열 출력. //포인터 pC가 문자열의 첫 주소를 가리킴
	printf("문자열을 변환기호를 이용해서 출력\n");
	printf("%s\n", pC);

	printf("반복문을 이용해 한 글자씩 출력\n");
	while (*pC)			//null(\0) 전까지
		printf("%c", *pC++);	//한글자씩	
	printf("\n");
}
