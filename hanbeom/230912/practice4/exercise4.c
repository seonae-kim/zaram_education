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
        countgroup[i] = count;	    //ok
        count = 0;
    }

    int max = countgroup[0];
    for (i = 0; i < n; i++)
    {
        for (j = 1 + i ; j < n; j++)             
        {
            if (countgroup[i] < countgroup[j])	         
            {
                max = num[j];		
            }
        }
    }

    int numberofmax = 0;
    for (i = 0; i < n; i++)
    {
        if (num[i] == max)
        {
            numberofmax++;
        }
    }
   
    int bonus = 0;
    for(i = 0; i < n; i++)
    {
	if (countgroup[i] == numberofmax)
	{
	    bonus++;
	}
    }	
    if (bonus % numberofmax ==0 && bonus / numberofmax !=1)
    {
        printf("-1");
        return -1;
    }
    else
    {
        printf("output : %d", max);	    
    }
}
