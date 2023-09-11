#include <stdio.h>

int main()
{
	int a[] = { 11, 22, 33, 44, 55 };
	int* p = a;

	printf("*p의 값 = %d\n", *p);			//11
	p++;

	printf("*p의 값 = %d\n", *p);			//22
	p++;

	printf("*p의 값 = %d\n", *p);			//33
	p--;

	printf("*p의 값 = %d\n", *p);			//22
}