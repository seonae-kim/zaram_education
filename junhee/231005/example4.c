/*4. 숫자 N 을 입력받는다. N * N 행렬이 완성되며, 달팽이 출력을 한다.
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
enum{
	RIGHT = 0,
	DOWN,
	LEFT,
	UP,
};
int main()
{
	int num[SIZE][SIZE] = {0};
	int i = 0,j = 0,n;
	int count = 0, m_count = 0, seq = 0;
	printf("N:");
	scanf("%d", &n);
	m_count = n*n;
	while(count < m_count)
	{
		++count;
		switch(seq)
		{
			case RIGHT:
				 {
					num[i][j] = count;
					j++;
					if(j > (n - 1) || num[i][j] != 0)
					{
						seq++;
						j--;
						i++;
						break;	
					}
					break;
				 }
				
			case DOWN:
				 {
				 	num[i][j] = count;
				 	i++;
					if(i > (n - 1) || num[i][j] != 0)
					{
						seq ++;
						i--;
						j--;
						break;	
					}
					break;
				 }
				
			case LEFT:
				 {
				 	num[i][j] = count;
				 	j--;
				 	if(j < 0 || num[i][j] != 0)
					{
						seq ++;
						j++;
						i--;
						break;	
					}
					break;
				 }
				
			case UP:
				 {
				 	num[i][j] = count;
				 	i--;
					if(i < 0 || num[i][j] != 0)
					{
						seq = 0;
						i++;
						j++;
						break;	
					}
					break;
				 }
		}
	}
	printf("\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d", num[i][j]);
		}
		printf("\n");
	}
	return 0;	
}
