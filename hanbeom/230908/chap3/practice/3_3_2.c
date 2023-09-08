#include <stdio.h>

int main()
{
    char word = 'a';

    printf("문자 1개를 입력하시오: ");
    scanf("%c", &word);
    printf("%c", word);

    return 0;
}