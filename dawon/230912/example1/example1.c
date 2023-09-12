#include <stdio.h>

int main()
{
    char array[5][20];
    int i=0, j=0;
    char[20] max1, max2, max3, max4, max5;
    int a,b,c,d,e;    
    printf("input": );
    for(i = 0; i < 5; i++)
    {
	for(j = 0; j < 20; j++)
	{
	    fgets(array[i][j],sizeof(array[i]),stdin);
	}
    }

    a=strlen(array[0]);
    b=strlen(array[1]);
    c=strlen(array[2]);
    d=strlen(array[3]);
    e=strlen(array[4]);

    for(int i=0;
