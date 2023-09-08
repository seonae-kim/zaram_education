#include <stdio.h>
int main()
{
    int i, j;
    int num[10];
    int maxgroup[10];
    int k = 0;
    int max_index = 0;

    for (i = 0; i < 10; i++)            
    {
        scanf("%d", &num[i]);
    }
    int max = num[0];
    
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (max <= num[j])
            {
                max = num[j];           
                max_index = j;
	    }
        }       
        maxgroup[k] = max;           
        k++;
        max = 0;    
        num[max_index] = 0;
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d %d ", maxgroup[i], maxgroup[9-i]);
    }
}
