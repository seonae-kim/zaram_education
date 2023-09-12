#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    int i=0, j=0, n=0;
    int max=0;
    int nummax=0;
    int a=0;
    int index=0;
    int cnt[20]={0, };

    printf("input N: ");
    scanf("%d",&n);
    printf("num: ");

    p=(int*)malloc(sizeof(int) * n);


    for(i = 0; i < n; i++)
    {
	scanf("%d",p+i);
    }
    printf("\n");

    for(i =0; i < n; i++)
	printf("%d",*(p+i));

    for(i = 0; i < n; i++)
    {
	for(j = 0; j <= i; j++)
	{
	    if(*(p+i) != *(p+j))
	    {
		cnt[*(p+i)]=1;
		
	    }
	    else if(*(p+i) == *(p+j))
	    {
		cnt[*(p+i)]++;
		
	    }
	    if(*(p+i) > nummax)
		nummax=*(p+i);
	}
    }

    for(i = 0; i <= nummax; i++)
    {
	if(cnt[i] > max)
	{
	    max = cnt[i];
	    index = i;
	}
	else if(cnt[i] == max)
	    a = max;

    }

    for(i = 0; i <= nummax; i++)
	printf("%d",cnt[i]);
    printf("\n");

    if(a == max)
	printf("-1\n");
    else 
	printf("%d\n",index);
    
    return 0;
}
    
		
	    

















