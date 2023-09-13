#include <stdio.h>

int main()
{
    int num[100];
    int i, j;
    int n = 0;
    int count = 0;
    int countgroup[100] = {0, };

    printf("input: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    for (i = 0; i < n ; i++)
    {
        for (j = 0; j < n ; j++)		
        {
            if (num[i] == num[j])	
            {                                               
                count++;
            }
        }
        countgroup[i] = count;
        count = 0;
    }
    int max = countgroup[0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)             
        {
            if (countgroup[i] < countgroup[j + 1])
            {
                max = num[j + 1];		
            }
        }
    }
    int numberofmax = 0;
    for (i = 0; i < n; i++)
    {
        if (countgroup[i] == max)
        {
            numberofmax++;
        }
    }
    
    if (numberofmax % max == 0 && numberofmax / max != 1)         
    {
        printf("-1");
        return -1;
    }
    else
    {
        printf("output : %d", max);	    
    }
}
