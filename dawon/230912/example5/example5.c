#include <stdio.h>

int main()
{
    int *p;
    int i=0, j=0, n=0;

    printf("input N: ");
    scanf("%d",&n);
    printf("num: ");

    p=(int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",p+i);
    }
    printf("\n");
    


