#include <stdio.h>

int main()
{
    unsigned char number = 0;      //입력받는 수가 1바이트=8비트
    unsigned char two = 64;   //2번재비트  0100000
    unsigned char four = 16;   //4번째비트  0001000

    printf("임의의 수를 입력하시오: ");                   

    scanf_s("%d", &number);                         //  8 = 00001000      

    printf("%d ", number & two);                    // 01000000
    printf("%d ", number & four);                   // 00010000

    return 0;

}