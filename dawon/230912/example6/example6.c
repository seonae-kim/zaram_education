#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char array[50];
    char numarray[50];
    int i=0, j=0, k=0, h=0;
    int p=0, m=0, flag=0, flag2=0;
    int index=0;
    int array2[50];
    int array3[20];
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
	if((int)array[i] > 47 && (int)array[i] < 58)
	{
	    p=i;
	    for(h=i+1; h<50; h++)
	    {
		if((int)array[h] > 47 && (int)array[h] < 58)
		{
		    p++;
		}
		else 
		    break;
	    }
	    index=p;
	    printf("numarray:");

	    if(p == i)
	    {  
		numarray[k]=array[i];
		flag=0;
		printf("%c",numarray[k]);
	    }
	    else
	    {
		for(j = i; j <= p; j++)
		{
		    numarray[k]=array[j];
		    k++;
		    flag=1;
		}
		for(int j = 0; j<k; j++)
		{
		    printf("%c",numarray[j]);
		}

	    }
    
	    printf("\n");
	    array2[m]=atoi(numarray);
	    m++;
	}
	memset(numarray,'\0',sizeof(char)*k);
	k=0;
    }	

    k=0;
    printf("m: %d\n",m);

    for(i = 0; i < m; i++)
    {
	printf("%d ",array2[i]);
    }

    for(i = 0; i < m; i++)
    {
	for(j = 0; j < m; j++)
	{
	    if(array2[j] < minnum)
	    {
		minnum=array2[j];
		index=j;
	    }
	}
	for(int l = 0; l <= k; l++)
	{
	    if(array2[index] == array3[l])
		flag2=1;
	}
	if(flag2 == 0)
	{
	    array3[k]=minnum;
	    k++;
	}
	array2[index]=100;
	minnum=100;
	flag2=0;
    }

    printf("\n output:");    
    for(i = 0; i < k; i++)
    {
	printf("%d ",array3[i]);

    }



    return 0;
}


    






    
    
