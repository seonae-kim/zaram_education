#include <stdio.h>
#include <string.h>

void ReverseCharacter(char* str1, int size); 

int main()
{
    char str[30];
    int i = 0;
    int count = 0;
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        count++;
        i++;
    }

    ReverseCharacter(str, count - 1); 

    printf("%s", str); // 수정된 문자열 출력

    return 0;
}

void ReverseCharacter(char* str1, int size)
{
    char temp;
    int i, j;

    for (i = 0, j = size; i < j; i++, j--)
    {
        temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }
}