#include <stdio.h>

int main()
{
    float num = 0;
    printf("등수를 입력하시오: ");

    scanf_s("%f", &num);

    printf("당신의 성적 백분율은 %.1f%%입니다", (num / 1000 * 100) );
}