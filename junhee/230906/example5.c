/*4행4열로 이루어진 배열에 숫자를 입력받는다.
1행부터 한 행씩 점수를 더하면서 내려왔을 때의 최대값을 찾는다.
(규칙: 같은 열을 연속해서 더할 수 없음)*/
#include <stdio.h>
#define COLUMN 4
#define	ROW 4

int main()
{
	int arr[COLUMN][ROW] = {0,};
	int sum=0;
    	int max =0;
	int i,j,y,u,k = 0;
	for(i = 0; i < COLUMN; i++)
	{
		for(j = 0; j < ROW; j++)
		{
            scanf("%d", &arr[i][j]);
		}
	}
	for(y = 0; y < ROW; y++)
	{
		for(u = 0;u < ROW; u++)
		{
			for(j = 0; j < ROW; j++)
			{	
				for (k = 0; k < ROW;k++)
				{
					if (y == u || u == j || j == k)
					continue;
					sum = arr[0][y] + arr[1][u] + arr[2][j] + arr[3][k];
					if(max < sum)
					{
						max = sum;
					}
				}

			}

		}

	}
	printf("%d",max);
	
	return 0;	
}
