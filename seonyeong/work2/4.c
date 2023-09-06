#include <stdio.h>

int main()
{
    int i, j;
    int num[10]={ 0 };
    int max =  0 ;
    int new_arr[10] = { 0 };
    int max_num = 0;

    printf("10 numbers:");
   

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }
   
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (num[j] >max)
            {  
                max = num[j];
                max_num = j;
            }
        }       
        new_arr[i] = max;
        num[max_num] = 0;
        max = 0;
    }
        
    printf("%d %d %d %d %d %d %d %d %d %d ", new_arr[0], new_arr[9], new_arr[1], new_arr[8], 
        new_arr[2], new_arr[7], new_arr[3], new_arr[6], new_arr[4],  new_arr[5] );
    printf("\n");
    return 0;
}


