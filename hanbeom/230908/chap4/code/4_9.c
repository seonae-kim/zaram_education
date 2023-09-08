#include <stdio.h>

int main()
{
    unsigned char lastmask = 1;    //2의 1승에 위치 : 00000001    (1바이트=8비트)
    unsigned char firstmask = 128; //2의 7승에 위치 : 10000000    (1바이트=8비트)  

    unsigned char input;

    printf("값을 입력하시오.\n");
    scanf("%d", &input);

    printf("입력한 값 %d의 첫번째 비트는 %d이다.\n", input, input & firstmask);    //   25 & 128 >>   00011001 & 10000000  (비트연산자)  // 

    printf("입력한 값 %d의 마지막 비트는 %d이다.\n", input, input & lastmask);
}