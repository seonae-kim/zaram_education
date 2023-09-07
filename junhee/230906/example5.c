#include <stdio.h>
#define COLUMN 4
#define	ROW 4

int main()
{
	int arr[COLUMN][ROW] = {0,};
	int sum=0;
    int max =0;
	for(int i=0;i<COLUMN;i++)
	{
		for(int j=0; j<ROW;j++)
		{
            scanf("%d", &arr[i][j]);
		}
	}
	for(int y = 0; y<ROW;y++)
	{
		for(int u = 0;u < ROW; u++)
		{
			for(int j = 0; j < ROW; j++)
			{	
				for (int k = 0; k < ROW;k++)
				{
					if (y == u || u == j || j == k)
					continue;
					sum=arr[0][y]+arr[1][u]+arr[2][j]+arr[3][k];
					if(max<sum)
					{
						max=sum;
					}
				}

			}

		}

	}
	printf("%d",max);
	
	return 0;	
}
