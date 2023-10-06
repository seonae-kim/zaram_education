/*숫자 갯수 N, 숫자의 합 M 을 입력받고, 숫자를 입력받는다.
N개중 3개를 골라 더한 값이 M과 가장 가까운 합을 출력한다. (M보다 크면 안됨) (N >= 3, M >= 10)
ex) input : 10 500
93 181 245 214 315 36 185 138 216 295
output : 497 
*/
#include <stdio.h>

int main()
{
	int n = 0,m = 0;
	int i,j,k,o,a;
	int hap = 0;
	int max = 0;
	int num[50] = {0};
	int n_num[50] = {0};
	printf("갯수(N):"); 
	scanf("%d",&n);
	if(n < 3)
	{
		printf("n은 3이상!\n"); 
		return 0;
	}
	printf("합(M):"); 
	scanf("%d", &m);
	if(m < 10)
	{
		printf("m은 10이상!\n"); 
	}
	
	for (k = 0; k < n; k++)
	{
		scanf("%d", &num[k]);
	}
	
	
	for(i = 0; i < n - 2; i++)
	{
		for(j = i + 1; j < n - 1; j++)
		{
			for(o = j + 1; o < n; o++)
			{	
				hap = num[i] + num[j] + num[o];
				if(hap <= m)
				{
					n_num[a] = hap;
					a++;	
				}
			}
		}
	}
	
	for(i = 0; i < a; i++)
	{
		if( max < n_num[i])
		{
			max = n_num[i];
		}
	}
	
	printf("%d",max);
	
	return 0;
}
