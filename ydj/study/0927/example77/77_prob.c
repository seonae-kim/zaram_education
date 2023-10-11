#include<stdio.h>
#include<string.h>

int main()
{
    char str[15] = {0};
    int i = 0;
    int num = 0;
    printf("Please enter the string : ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '1')
        {
            num++;
        }
    }

    if (num % 2 == 0)
    {
        for (i = 0; i < strlen(str); i = i + 2)
        {
            printf("%c", str[i]);
        }
    }
    else 
    {
        for (i = 1; i < strlen(str); i = i + 2)
        {
            printf("%c", str[i]);
        }       
    }
    return 0;
}