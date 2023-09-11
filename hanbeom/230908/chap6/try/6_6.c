#include <stdio.h>

int main()
{
    int i =1;
    int num = 0;

    for(i = 1; i < 11; i++)
	{
	    if(i % 2 !=0)
		continue;
	    num += i;
	}
    printf("%d", num);
}
