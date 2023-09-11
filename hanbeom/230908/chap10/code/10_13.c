#include <stdio.h>

int strleng(char* ch);			//문자열 입력받아 문자 개수 세는 함수
int main()
{
	int len;
	char str[] = "c language and data structure";
	len = strleng(str);			// 문자열 크기
	printf("문자열의 크기는 %d다.\n", len);
}

int strleng(char* ch)
{
	int index;			//ch를 따로 선언할 필요는없음
	for (index = 0; *(ch + index) != '\0'; index++);		//포인터가 가리키는 값이 \0(null) 되기전까지 index 증가
	return index;
}