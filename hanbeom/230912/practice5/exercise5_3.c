#include <stdio.h>

int main()
{
 
    int num[100];
    int n,i,j;
    int index; 
    int mingroup[100];

    printf("input N: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
	scanf("%d", &num[i]);
    }


    int min = num[0];

    for (i = 0; i < n; i++)	//1
    {
	for(j = 0; j < n; j++)
	{
	    if (min >= num[j])
	    {
		min = num[j];
		index = j;
	    }
	}
	mingroup[i] = min;
	num[index] = 10000;
	min = 9999;
    }
		    
    //2
    
    for(i=0 ; i < n; i ++)
    {
	for(j = i +1 ; j < n; j++)
	{
	    if(mingroup[i] == mingroup[j])
	    {
		mingroup[j] = 0;
	    }
	}
    }

    //2-2   
    int newgroup[100];
    int newsize = 0;
    for (i = 0; i < n; i++)
    {
        if (mingroup[i] !=0)
	{
	    newgroup[newsize] = mingroup[i];
	    newsize++;
	}
    }
    
 
    //3

    for(i = 0; i < newsize -1; i ++)
    {
        for(j =1 +i ; j < newsize; j++)
	{
	    printf("(%d, %d) ", newgroup[i], newgroup[j]);
	}
    }

}
