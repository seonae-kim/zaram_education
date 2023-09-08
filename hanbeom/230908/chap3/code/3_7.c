#include <stdio.h>

int main(void) 
{
    printf("\t\'프로그램의 시작 \' \n\n");  // \' 사용

    printf("\t\"C언어 %c \" \n\n", '!');                 // %c= 문자 1개, ' '

    printf("\t\"시작이 반이다 %s \"\n", "!!");           //%s= 문자열 , " "

    printf("\t\a\a\a\a\a\n");                           // %a = 경고음

    priintf("\t\\ \\ \n");                              //  \\ = 역슬래시(\) 출력

    return 0;
}