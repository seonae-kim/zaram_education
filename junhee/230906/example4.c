/*숫자 10개를 입력받는다. 
최댓값, 최소값 순서로 번갈아 가면서 출력한다*/
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
    int i,j,k,o,u = 0;
    for (i = 0; i < arr; i++)
    {
        scanf("%d", &num[i]);
        max_count++;
    }
    for (j = 0; j < arr; j++)
    {
        if (j % 2 == 0)
        {
            for (k = 0; k < max_count; k++)
            {
                if (num[k] > maxnum)
                {
                    maxnum = num[k];
                    x = k;
                }
            }
            delete_at(x);
            history[count] = maxnum;
            maxnum = -2147483647;  

        }
        else
        {
            for (o = 0; o < max_count; o++)
            {
                if (num[o] < minnum && num[o] != 0)  
                {
                    minnum = num[o];
                    n = o;
                }
            }
        	delete_at(n);
            history[count] = minnum;
            minnum = 2147483647;

        }
        count++;
    }
    for (u = 0; u < count; u++)
    {
        printf("%d ", history[u]);
    }
    return 0;
}

