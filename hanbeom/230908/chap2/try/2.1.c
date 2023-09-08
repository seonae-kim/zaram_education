#include <stdio.h>

int main()
{
	int a = 20;
	int b = 3;			//const를 제거해야 함

	printf("변수 a의 초기값은 %d이다.\n", a);
	printf("변수 b의 초기값은 %d이다.\n", b);

	a = 10;
	b = 4;

	printf("a의 값은 %d로 바뀌었다.\n", a);
	printf("b의 값은 %d로 바뀌었다.\n", b);
	return 0;
}