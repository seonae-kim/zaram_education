#include <stdio.h>
#define COLUMN 4
#define	ROW 4

int main()
{
	int arr[COLUMN][ROW] = {0,};
	int max=0;
	int x=0; 
	int history[4] = {0};
    int count = 0;
    
	for(int i=0;i<COLUMN;i++)
	{
		for(int j=0; j<ROW;j++)
		{
            scanf("%d", &arr[i][j]);
		}
	}
	for(int i=0;i<COLUMN;i++)
	{
		for(int j=0; j<ROW;j++)
		{
			if(i>0)
			{
				arr[i][x] = 0;
			}
			if (arr[i][j] > max)
                {
                    max = arr[i][j];
                    x = j;
                }
		}
        history[count] = max;
        max =0;  
        count ++;
	}

	for (int i = 0; i < count; i++)
    {
        printf("%d ", history[i]);
    }
	return 0;	
}
