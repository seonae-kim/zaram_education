/*N 개의 물건이 원을 그리며 세워져있다. K번째 물건을 제거한후 다음 물건부터 K번째 물건을 제거한다.
   이 과정은 N개의 물건이 모두 제거될 때까지 반복한다.
   (K <= N)*/
#include <stdio.h>
#define SIZE 100
int main()
{
	int n,k = 0;
	int num[SIZE][SIZE];
	int d_num [SIZE];
	int i,j,o,u = 0;
	int p_num = 0;
	int k_count = 0;
	printf("n과 k는 100까지\n");
	printf("n = ");
	scanf("%d",&n);
	printf("k = ");
	scanf("%d",&k);
	p_num = k;
	if (k > n || n > SIZE || k > SIZE)
	{
		printf("오류!\n"); 
		return 0;
	}
	
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < n; j++)
		{
			num[i][j] = j + 1;  
		}  
	}
	
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < n; j++)
		{
			if( num[i][j] == 0)
			{
				continue;
			}
			else
			{
				++k_count;
				
				if( k_count > n )
				{
					k_count -= n;
				}
			}
			 
			if(k_count == k)
			{
				d_num[o] = num[i][j];
				for ( u = 0; u < SIZE; u++)
				{
					num[u][j] = 0;
				}
				printf("\n remove = %d\n",d_num[o]);
				++o;
				k+=p_num;
				if (k > n)
				{
					k -= n ;
				}					
			}
		}
	}
	printf("\n");
	return 0;	
}	
