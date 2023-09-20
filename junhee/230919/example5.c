/* N개의 숫자가 주어질 때 2개의 숫자조합을 모두 출력한다. 
조건: (같은 숫자의 조합은 출력하지 않는다, 중복 될 경우 한번만 출력한다.)
*/
#include <stdio.h>
#define SIZE 50

void sort_num(int *num, int a)
{
	int tmp = 0;
	int i = 0, j = 0;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			if ( num[i] < num[j] )
			{
				tmp = num[i];
				num [i] = num[j];
				num [j] = tmp;
			}
		}
	}
}
int find(int *num, int a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if(num[i] == a)
		return 0;
	}
	
	return 1;
}
int main(void)
{
	int num[SIZE];
	int div[SIZE] = {0};
	int n = 0, a = 0, i = 0, j = 0, k = 0, u = 0, o = 0 ;

	printf("N:");
	scanf("%d", &n);
	printf("num:");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	
	for (k = 0; k < n; k++)
	{
		if(find(div,num[k],a))
		{
			div[a] = num[k];
			a++;
		}
	}
	sort_num(div,a);
	for(j = 0; j < a; j++)
	{
		for(u = j + 1; u < a; u++)
		{
			if(div[j] == div[u])
			{
				continue;
			}
			printf("(%d, %d)", div[j],div[u]);
		}
	}
	
	return 0;
}
