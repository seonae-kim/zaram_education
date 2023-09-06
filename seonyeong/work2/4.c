#include <stdio.h>

int main()
{
    int i;
    int num[100];

    printf("10 numbers:");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }
    int max_number = 0;
    int min_number = 0;

    printf("output:");
   

    for (int p = 1; p < 10; p++)
    {
        for (int i = 1; i < 10; i++)
        {           
            
            if (num[i] > num[max_number])
            { 
                max_number = i;
            }
           
            if (num[i] != 0 && num[i] < num[min_number])
            {                
                min_number = i;
            }
        } 
        
        if (p % 2 == 1)
        {
            printf("%d ", num[max_number]);
            num[max_number] = 0;
        }
        else
        {
            printf("%d ", num[min_number]); //min ?
            num[min_number] = 0;
        }      
        
    }   

    return 0;
}


