#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char a[10] = {0};
    char b[10] = {0};
    int i = 0;
    int flag = 0, no_print_flag = 0;
    char temp[1] = {0};

    printf("Please enter the string A : ");
    scanf("%s", a);
    printf("Please enter the string B : ");
    scanf("%s", b);

    while(strcmp(a, b) != 0)
    {
        temp[0] = a[strlen(a) - 1];
        for (i = strlen(a) - 1; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = temp[0];
        flag++;
        memset(temp, 0, 1 * sizeof(char));
        if (flag > strlen(a))
        {
            printf("-1\n");
            no_print_flag = 1;
            break;
        }
    }

    if (no_print_flag == 0)
    {
        printf("%d\n", flag);
    }
    return 0;
}