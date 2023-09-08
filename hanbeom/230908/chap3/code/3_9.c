#include <stdio.h>

int main(void) 
{
    char Name[20];      //문자열 출력할거라 배열 선언

    printf("이름을 입력하세요: ");

    gets(Name);         //gets함수 사용(문자열 입력)
    puts(Name);         //puts함수 사용(문자열 출력)

    return 0;
}