#include <stdio.h>
int main()
{
    int i, j, t;
    int num[10];
    int maxgroup[10];
    int mingroup[10];
    int k = 0, p = 0;
    int max_index = 0;
    int min_index = 0;
    int num_copy[10];

    for (i = 0; i < 10; i++)            //1
    {
        scanf("%d", &num[i]);
    }
    int max = num[0];
    int min = num[0];

    for (j = 0; j < 10; j++) {              //num_copy for find min
        num_copy[j] = num[j];
        //printf("%d", num_copy[j]);        //check num_copy 
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (max <= num[j])
            {
                max = num[j];            //update max
                max_index = j;
            }
        }   //max=12 (10개 다 검사)


        for (j = 0; j < 10; j++)
        {
            if (min >= num_copy[j])
            {
                min = num_copy[j];            //update min
                min_index = j;     //recent min index
            }
        }           //min=12

        maxgroup[k] = max;           
        k++;
        max = 0;
        num[max_index] = 0;

        mingroup[p] = min;
        p++;
        min = 5000;
        num_copy[min_index] = 5000;
        //printf("%d", min_index);
    }
    //printf("%d ", maxgroup[0]);
    for (i = 0; i < 5; i++)
    {
        //printf("%d ", maxgroup[i]);
        printf("%d %d ", maxgroup[i], mingroup[i]);            //max[0] min[0] max[1] min [2] ...
    }
}
