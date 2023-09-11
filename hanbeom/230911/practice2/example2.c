#include <stdio.h>

int main()
{
    int num = 0;
    int i,j,k;
    scanf("%d", &num);

     for(i =0 ; i < num; i++)
     {	for(j = num; j > i; j--)
        {
	     printf("%c", '*');	//***
	}
        printf("\n");
     }     
}
