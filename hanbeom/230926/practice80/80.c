#include <stdio.h>
#include <string.h>

int main()
{
    char str[50][50];
    int i;
    for (i = 0; i < 50; i++)
    {
        fgets(str[i], sizeof(str[i]), stdin);
        if (strcmp(str[i], "q\n") == 0)
        {
            return 0;
        }
        printf("%s", str[i]);
    }
}