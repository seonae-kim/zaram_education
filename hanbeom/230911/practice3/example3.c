#include <stdio.h>

int main()
{
    int num[4];
    int num2[4];
    int i,j;
    int index =0;
    int N = 0;    
    
//    printf("input N: ");
  //  scanf("%d", &N);

    printf("input number: ");
    for(i = 0; i < 4; i++)
    {
	scanf("%d", &num[i]);
    }

    printf("input N: ");
    scanf("%d", &N);


    int max= num[0];

    for(i = 0; i < 4; i++)
    {
	if(num[i] % N != 0)
	{
	    num[i] = 0;
	}    
    }
    for(i = 3; i >= 0; i--)
    {
	 for(j = 0; j < 4; j++)
	 {
	    if(max<=num[j])
	    {
		max = num[j];
		index = j;
	    }  
	 } 
	 num2[i] = max;
	 num[index] = 0;
	 max = 0;
    } 

    for(i = 0; i < 4; i ++)
    {
	    if(num2[i] ==0)
	    {
	        num2[i] = num2[i+1];
	    }    	
	    else
		printf("%d ", num2[i]);
    }




}
