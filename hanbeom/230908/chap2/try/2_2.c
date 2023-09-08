#include <stdio.h>

int main(void)
{
    char a ='f';
    char b = 104;

    printf("변수 a는 %c로 값이 %d다.\n", a, a);         //a를 문자형, 정수형으로 출력
    printf("변수 b는 %d로 값이 %c다.\n", b, b);         //b를 정수형, 문자형으로 출력

    return 0;
}