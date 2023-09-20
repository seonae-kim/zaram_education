/*최빈값 구하기. 주어진 배열에서 가장 자주 나오는 값 출력. 최빈값이 여러 개면 -1을 return.*/

#include <stdio.h>
#include <string.h>

#define SIZE 50

int main(void)
{
	int num[SIZE];
	int mode[SIZE] = {0};
	int n = 0, max = -1, many = 0, i = 0, j = 0, k = 0, u = 0, o = 0 ;

	printf("N:");
	scanf("%d", &n);
	printf("num:");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	for(j = 0; j < i; j++) //몇번 나오는 지 
	{
		for(k = 0; k < i; k++)
		{
			if(num[j] == num[k])
			{
				mode[j] += 1;
			}
		}
	}
	for(u = 0; u < i; u++) 
	{
		if(max < mode[u])
		{
			max = mode[u];
		}
	}
	for(o = 0; o < i; o++)
	{
		if(max == mode[o])
		{
			++many;
			if (many > max)
			{
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", max);
	return 0;
}
