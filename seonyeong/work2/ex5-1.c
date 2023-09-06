#include <stdio.h>

int main()
{
        int i = 0;
        int j = 0;
        int num[4][4] = { 0 };
	int sum1_max[2] ={ 0 };
	int sum2_max[2] ={ 0 };
	int row[4] = { 0 };
	int sum_total = 0;

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
                       if( num[0][i] + num[1][j] > sum1_max)
		       { 
			       sum1_max[1] = sum1_max[0];
			       sum1_max[0] = num[0][i] + num[1][j];
			       row[0] = i;
			       row[1] = j;
		       	 
		       }

                }
        }
			

	for(i = 0; i < 4; i++)
        {
                for (j = 0; j < 4; j++)
                {
                       if( num[2][i] + num[3][j] > sum2_max)
                       { 
			       sum2_max[1] = sum2_max[0];
                               sum2_max[0] = num[2][i] + num[3][j];
			       row[2] = i;
			       row[3] = j;
                       }

                }
        }
 
	///////	
        
	if (row[1] == row[0])
	{	
		sum_total = sum1_max[1] + sum2_max[0];
	        printf("%d ", sum_total);	
	}

	if(row[2] == row[1])
	{
		if(sum1_max[0]+sum2_max[1] > sum1_max[1]+sum2_max[0])
		{
			sum_total = sum1_max[0]+sum2_max[1];
			printf("%d ", sum_total);

		}
		else 
		{
			sum_total = sum1_max[1]+sum2_max[0];
			printf("%d ", sum_total);
		}
	}
	else sum_total = sum1_max[0] + sum2_max[0];
	printf("%d ", sum_total);
	
	printf("\n");
	return 0;

}




