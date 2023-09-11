#include <stdio.h>

int SumArray(int Array[], int Size);

int main()
{
	int a[] = { 10, 5, 15, 25, 7 };
	int Sum;
	Sum = SumArray(a, 5);
	printf("배열 원소의 합 : %d\n", Sum);
}

int SumArray(int Array[], int Size)			//배열을 함수의 인자로 사용
{
	int result = 0, i;
	for (i = 0; i < Size; i++)
		result += Array[i];

	return result;
}