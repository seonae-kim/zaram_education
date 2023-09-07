#include <stdio.h>

int main()
{       
        int i = 0, j = 0, a = 0, b = 0;
 	int num[4][4] = { 0 };
	int max = 0, sum = 0;

        printf("16 numbers: ");

        for (i = 0; i < 4; i++)
        {
                for (j = 0; j < 4; j ++)
                {
                        scanf("%d",&num[i][j]);

                }
        }

        for(i = 0; i < 4; i++)
        {
                for (j = 0; j < 4; j++)
                {
			for (a = 0; a < 4; a++)
               		{
				for (b = 0; b < 4; b++)
                       	 	{
					if (j == i) continue;
					if (j == a) continue;
					if (a == b) continue;
					
					sum = num[0][i] + num[1][j] + num[2][a] + num[3][b];
					if(sum>max)
                                        {
                                                max = sum;
                                        }

				}
			}

                }
        }
        
	printf("%d\n",max);
        printf("\n");
}





