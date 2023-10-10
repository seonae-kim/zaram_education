#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char p[10] = {0};
    char t[10] = {0};
    int num = 0;
    int par_t = 0;
    int i = 0, j = 0, flag = 0;
    char temp[10] = {0};
    printf("Please enter the string p : ");
    scanf("%s", p);

    printf("Please enter the string t : ");
    scanf("%s", t);

    if (strlen(t) < strlen(p))
    {
        printf("0\n");
    }

    else if (strlen(t) == strlen(p))
    {
        if (atoi(t) > atoi(p))
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }

    else 
    {
        num = strlen(t) - strlen(p) + 1;
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < strlen(p); j++)
            {
                temp[j] = t[i + j];
            }
            par_t = atoi(temp);
            if (atoi(p) >= par_t)
            {
                flag++;
            }
            memset(temp, 0, 10 * sizeof(char));
        }
        printf("%d", flag);
    }

//    printf("%d", strlen(str));
    return 0;
}