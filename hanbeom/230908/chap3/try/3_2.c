#include <stdio.h>

int main(void)
{
    char grade;
    printf("성적 등급을 입력하시오\n");

    grade = getchar();      //getchar(grade); 를 수정

    printf("당신의 성적 : ");
    putchar(grade);         //putchar(); 를 수정
    printf("\n");

    return 0;
}