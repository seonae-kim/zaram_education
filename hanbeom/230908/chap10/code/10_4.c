#include <stdio.h>

void Swap(int* a, int* b);						//10_3과 다른부분 (포인터)
int main()
{
	int x = 10, y = 5;
	printf("Swap() 함수 실행 전\n");
	printf("x = %d, y = %d이다.\n\n", x, y);

	Swap(&x, &y);								//10_3과 다른부분 (포인터)
	printf("Swap() 함수 실행 후\n");
	printf("x= %d, y = %d이다.\n", x, y);
}

void Swap(int* a, int* b)						//10_3과 다른부분 (포인터)		
{
	int temp;
	temp = *a;									//10_3과 다른부분 (포인터)
	*a = *b;									//10_3과 다른부분 (포인터)
	*b = temp;									//10_3과 다른부분 (포인터)
}