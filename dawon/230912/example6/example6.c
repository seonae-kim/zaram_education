#include <stdio.h>
#include <stdlib.h>
int main()
{
    char array[50];
    char numarray[50];
    int i=0, j=0, k=0, h=0;
    int p=0, m=0, flag=0;
    int index=0;
    int array2[50];
    int minnum=100;
    
    numarray[0]='\0';
    printf("input: ");
    fgets(array,sizeof(array),stdin);
    printf("array: ");
    for(i = 0; i < 50; i++)
    {
	if(array[i] == '\0')
	    break;
	printf("%c",array[i]);
    }

    for(i = 0; i < 50; i++)
    {
	if(array[i] == '\0')
	    break;
	if(i <= index && flag == 1)
	    continue;
	if(
	    array[i] == '0'
	    || array[i] == '1'
	    || array[i] == '2'
	    || array[i] == '3'
	    || array[i] == '4'
	    || array[i] == '5'
	    || array[i] == '6'
	    || array[i] == '7'
	    || array[i] == '8'
	    || array[i] == '9'
	  )
	{
	    p=i;
	    for(h=i+1; h<50; h++)
	    {
		if(
			array[h] == '0'
			|| array[h] == '1'
			|| array[h] == '2'
			|| array[h] == '3'
			|| array[h] == '4'
			|| array[h] == '5'
			|| array[h] == '6'
			|| array[h] == '7'
			|| array[h] == '8'
			|| array[h] == '9'
		    ){
		    p++;
		}
		else 
		    break;
	    }
	    index=p;
	    if(p == i)
	    {  
		numarray[k]=array[i];
		flag=0;
	    }
	    else
	    {
		for(j = i; j <= p; j++)
		{
		    numarray[k]=array[j];
		    k++;
		    flag=1;
		}
	    }
	    printf("numarray:");	    
    
	    for(int j = 0; j<k; j++)
	    {
		printf("%c",numarray[j]);
	    }
	    printf("\n");
	    array2[m]=atoi(numarray);
	    m++;
	}
	numarray[0]='\0';
	k=0;
    }	

    printf("m: %d\n",m);

    for(i = 0; i < m; i++)
    {
	printf("%d ",array2[i]);
    }

    return 0;
}


    






    
    
