#include <stdio.h>

int main()
{

    int score, grade;

    printf("점수를 입력하세요 : ");
    scanf("%d", &score);

    grade = (score >= 90);              //조건문 true면 grade=1, false면 grade=0
    printf("%d",grade);

}