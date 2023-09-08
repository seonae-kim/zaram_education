#include <stdio.h>

int main()
{
    int c = 0;   //섭씨
    float f = 0;   //화씨

    printf("섭씨온도를 입력하시오: ");
    scanf_s("%d", &c);

    f = (c * 1.8) + 32;

    printf("%f", f);

}