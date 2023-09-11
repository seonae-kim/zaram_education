#include <stdio.h>

void CallNumber();

int main()
{
	int i;
	for (i = 0; i < 5; i++)
	{
		CallNumber();
	}
}

void CallNumber()
{
	static int count = 1;
	int number = 1;
	printf("%d번째 호출되었습니다. \n", count++);			//값 바뀜(정적변수).   초기화 한 번만 함
	printf("Number 값은 %d이다. \n\n", number++);		//값 안바뀜. 초기화 계속 함
}