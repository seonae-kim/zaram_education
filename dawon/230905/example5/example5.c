#include <stdio.h>

int main()
{
	int arry[4][4];
	int sum=0, max=0;

        printf("input: ");
        for(int i = 0 ; i < 4 ; i++)
        {
                for(int j = 0 ; j < 4 ; j++)
                {
                        scanf("%d",&arry[i][j]);
                }
        }

        printf("output: ");
        for(int i = 0 ; i < 4 ; i++)
        {
                for(int j = 0 ; j < 4 ; j++)
                {
			for(int k = 0; k < 4; k++)
			{
				for(int h = 0; h < 4; h++)
				{
					sum = arry[0][i] + arry[1][j] + arry[2][k] + arry[3][h];

					if( sum > max && i != j && j != k && k != h)
						max = sum;

				}
			}
                }
        }
	
	printf("%d\n", max);
        return 0;
}
