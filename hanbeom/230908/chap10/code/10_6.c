#include <stdio.h>

int main() 
{
	int a[] = { 10, 20, 30, 40, 50 };
	int* p = a;
	int i;

	printf("배열명 a를 이용한 주소 표현\n");
	for (i = 0; i < 5; i++)
	{
		printf("a[%d]의 주소 %p\n", i, a + i);			//(1) a[0] a[1] a[2] a[3] a[4] 
	}
		printf("\n포인터 p를 이용한 배열 주소 표현\n");		
		for (i = 0; i < 5; i++)
			printf("a[%d] = %p\n", i, p + i);		//(2) *p *(p+1) *(p+2) *(p+3) *(p+4)				1, 2 표현 동일

		printf("\n포인터 p를 이용한 배열값 표현\n");
		for (i = 0; i < 5; i++)
			printf("a[%d] = %d\n", i, *(p + i));

	return 0;
}