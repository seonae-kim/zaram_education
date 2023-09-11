#include <stdio.h>

int main()
{
    unsigned char bitmask = 16;           //00010000   =   16
    unsigned char input = 0;              //00001000   =   8                    

    printf("정수를 입력하시오\n");
    scanf_s("%d", &input);                                           

    printf("입력한 값의 4번째 비트를 바꾸면 값은 %d이다.\n", input ^ bitmask);     //>> 00011000 = 24
}