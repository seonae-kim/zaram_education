#include <stdio.h>

int main(void)
{
    int a =10, b= 20, c;
    float d= 5.6, e = 8,4, f;

    c = d +e;
    printf("c = d + e is %.2f\n", (float)c);    //c is changed to float

    f = d+ e;	
    printf("f = d + e is %.2f\n", f);		// .2

    f = d + (int)e;
    printf("f = d + (int)e is %.2f\n", f);	// .2


    return 0;
}
