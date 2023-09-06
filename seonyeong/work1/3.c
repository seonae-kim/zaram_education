#include <stdio.h>

int main()
{
    int N, k, i;
    int p = 0;
    int q = 0;

    printf("N: ");
    scanf("%d", &N); //9  7

    printf("k: ");
    scanf("%d", &k); //4  3

    printf("output: ");
    
    int num[100];
    
    for (i = 0; i < N; i++)
    {
        num[i] = i + 1;
    }
    
    while (1)
    {
        if (q == N)
            break;

        for (i = 0; i < N; i++)
        {
            if (num[i] == 0)
                continue;

            p++;
            if (p == k)
            {
                printf("%d ", num[i]);
                num[i] = 0;
                p = 0;
            }
        }
            q++;
            if (q == N)
            {
                for (i = 0; i < N; i++)
                {
                    if (num[i] != 0)
                        printf("%d", num[i]);
                }
                break;
            }
        } 
        
    return 0;
}


