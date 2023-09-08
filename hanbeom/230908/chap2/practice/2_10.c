#include <stdio.h>

int main()
{
    float a = 0;
    float b = 0;


    printf("사격형의 가로, 세로 길이를 입력하시오: ");

    scanf_s("%f %f", &a, &b);  

    printf("넓이는 %d", (int)(a*b) );      //명시적 형변환
}