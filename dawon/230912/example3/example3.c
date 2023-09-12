#include <stdio.h>

int main()
{
    int N=0;
    int cnt=0;

    printf("input: ");
    scanf("%d",&a);

    while(a != 1)
    {
	if(a % 2 == 0)
	{
	    a /= 2;
	    cnt++;
	}
	else if(a % 3 == 0)
	{
	    a /= 3;
	    cnt++;
	}
	else 
	{
	    a -= 1;
	    cnt++;
	}
    }
    printf("%d",cnt);
    
    return 0;
}

