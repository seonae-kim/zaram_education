#include <stdio.h>

int main()
{
    int number = 0;

    printf("input :");
    scanf("%d", &number);

    if (number % 3 == 0)
	    if (number % 6 == 0)
		    printf("number is multiple of 3 and multiple of 6");
    else
	    printf("number is not multiple of 3 and multiple of 6");
}

