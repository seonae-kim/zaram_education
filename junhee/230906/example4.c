#include <stdio.h>
#include <stdint.h>

#define arr 10

int num[arr] = {0};
uint32_t max_count = 0;

void delete_at(uint32_t index)
{
    uint32_t q;
    for (q = index; q < max_count - 1; q++)
    {
        num[q] = num[q + 1];
    }
    --max_count;
}

int main()
{

    int maxnum = -2147483647;  
    int minnum = 2147483647; 
    int history[arr] = {0};
    int x, n = 0;
    int count = 0;
    for (int i = 0; i < arr; i++)
    {
        scanf("%d", &num[i]);
        max_count++;
    }
    for (int i = 0; i < arr; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < max_count; j++)
            {
                if (num[j] > maxnum)
                {
                    maxnum = num[j];
                    x = j;
                }
            }
            delete_at(x);
            history[count] = maxnum;
            maxnum = -2147483647;  

        }
        else
        {
            for (int j = 0; j < max_count; j++)
            {
                if (num[j] < minnum && num[j] != 0)  
                {
                    minnum = num[j];
                    n = j;
                }
            }
        	delete_at(n);
            history[count] = minnum;
            minnum = 2147483647;

        }
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d ", history[i]);
    }
    return 0;
}

