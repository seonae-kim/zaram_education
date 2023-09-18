#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct ThreeDime
{
    double x;
    double y;
    double z;
};

typedef struct ThreeDime ThreeDime;

double Distance1(ThreeDime* a)       //구조체를 인자로 받는 함수.   ThreeDime= 구조체, a= 객체, x,y,z=멤버
{
    double d;
    d = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
    return d;
}

double Distance2(ThreeDime* a, ThreeDime* b)
{
    double d;
    d = sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z));
    return d;
}

ThreeDime Sym0ri(ThreeDime* a)
{
    a->x = -a->x;
    a->y = -a->y;
    a->z = -a->z;
    return *a;                  //*붙여야함
}

int main(void)
{
    double D1, D2;
    ThreeDime A1, A2, A3;

    printf("3차원의 점 A1의 x, y, z 좌표를 입력하시오. \n");
    scanf("%lf %lf %lf", &A1.x, &A1.y, &A1.z);
    
    printf("3차원의 점 A2의 x, y, z 좌표를 입력하시오. \n");
    scanf("%lf %lf %lf", &A2.x, &A2.y, &A2.z);

    D1 = Distance1(&A1);         //A1점과 원점의 거리.  (함수 인자가 포인터형(주소값)이라 & 붙임)

    D2 = Distance2(&A1, &A2);     //A1점과 A2점의 거리  (함수 인자가 포인터형(주소값)이라 & 붙임)

    A3 = Sym0ri(&A1);            //A1점을 원점에 대칭시킨 점  (함수 인자가 포인터형(주소값)이라 & 붙임)

    printf("\nA1점과 원점의 거리는 %.2lf이다.\n", D1);
    printf("\nA1점과 A2점의 거리는 %.2lf이다.\n", D2);
    printf("\nA1점을 원점에 대칭시킨 점은 x : %.2lf, y : %.2lf, z : %.2lf이다.\n", A3.x, A3.y, A3.z);

    return 0;

}