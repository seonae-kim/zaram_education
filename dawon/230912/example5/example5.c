#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    int i=0, j=0, n=0, k=1, flag=0;
    int num[20]={0, };
    char ch;

    printf("input N: ");
    scanf("%d",&n);
    while((ch = getchar()) != '\n' && ch != EOF);
    printf("num: ");

    p=(int*)malloc(sizeof(int) * n);
    if(p == NULL)
    {
	printf("error");
	exit(0);
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d",p+i);
    }
    printf("\n");

    for(i = 0; i < n; i++)
        printf("%d",*(p+i));  
   
    num[0]=*p;
    
    for(i = 1; i < n; i++)
    {
	for(j = 0; j < i; j++)
	{
	    if(*(p+i) == *(p+j))
	    {
		flag=1;
		break;		
	    }
	     		
	}
	if(flag==0)
	{
	    num[k]=*(p+i);
	    k++;
	}
	flag=0;
    }

    for(i = 0; i < k; i++)
	printf("%d",num[k]);
    printf("\n");

    for(i = 0; i < k-1; i++)
    {
	for(j = i+1; j < k; j++)
	{
	   printf("(%d, %d) ",num[i],num[j]);
	}
    }
    printf("\n");
    return 0;
}    







    

