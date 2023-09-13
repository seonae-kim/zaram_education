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
	    while(
		     array[h] != '0'
		    && array[h] != '1'
		    && array[h] != '2'
	    	    && array[h] != '3'
		    && array[h] != '4'
		    && array[h] != '5'
		    && array[h] != '6'
		    && array[h] != '7'
		    && array[h] != '8'
		    && array[h] != '9'
		 )
	    {
		for(int h=i; h<50; h++)
		{
		    if(array[h] == '\0')
			break;
		    p++;
		}
	    }
	    for(j = i; i < p; i++)
	    {
		numarray[k]=array[i];
		k++;
	    }

	    array2[m]=atoi(numarray);
	    m++;
	}
	numarray[0]='\0';
	k=0;
    }	

    for(i=0;i<m;m++)
    {
	printf("%d",array2[i]);
    }





/*	    for(k=0; k <= i; k++)
	    {
		if(numarray[k] == array[i])
		{
		    flag=1;
		    break;
		}
	    }
	    if(flag == 0)	
	    {
		numarray[p] = array[i];
		p++;
	    }
	}
	flag=0;
    }

    j=0;

    printf("numarray: ");
    for(i = 0; i < p; i++)
    {
	printf("%c",numarray[i]);
    }


    for(k = 0; k <= p; k++)
    {
	for(i = 0; i <= p; i++)
	{
	    if(numarray[i] < minnum)
	    {
		minnum=numarray[i];
		index=i;
	    }
	}
    
	array2[j]=minnum;
	numarray[index]=100;
	j++;

    }

    for(i = 0; i < p; p++)
    {
	printf("%d", array2[i]);
    }
    */

    return 0;
}


    






    
    
