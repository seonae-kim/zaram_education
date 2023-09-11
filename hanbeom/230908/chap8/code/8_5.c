#include <stdio.h>

void upper_case(char ch);

int main()
{
	char ch1;
	while ( ( ch1 = getchar() ) != EOF )		// getchar 함수는 enjoy 를 입력했을때 e, n, j, o, y 까지 읽고 EOF 값을 반환함.
	{
		upper_case(ch1);
	}
}

void upper_case(char ch)
{
	char res;
	if (ch >= 'a' && ch <= 'z')
	{
		res = ch - 32;
	}
	else
	{
		res = ch;
	}
	putchar(res);
}