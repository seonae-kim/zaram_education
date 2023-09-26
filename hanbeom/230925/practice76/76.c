#include <stdio.h>
#include <string.h>
int main()
{
	char A[50] = {0,};
	char B[50] = {0,};
	char C[50] = {0,};
	int i;

	printf("input A:\n");
	fgets(A,sizeof(A),stdin);		

	printf("input A:\n");
	fgets(B,sizeof(B),stdin);		

	size_t len = strlen(A) - 1;		
	int k;
	int result = 1;
	int noresult =0;

	for(k =0; k < len; k++)
	{	
		for(i =0; i <len; i++)	
		{
			if(i != 0)
			{
				C[i] = A[i-1];			
			}
			else if(i ==0)
			{
				C[i]= A[len-1];		
			}
		}		

		for(i = 0; i <len; i++)
		{
			A[i] = C[i];		
		}

		int count = 0;
		for(i = 0; i <len; i++)
		{
			if(A[i] == B[i])
			{
				count++;
			}
		}
		
		if(result == len && count ==len)	 
		{
			printf("0");
			break;
		}

		if(count == len)
		{
			printf("%d", result);
			break;
		}
		else if (count != len)			
		{
			noresult++;
		}
		if(noresult == len)
		{
			printf("-1");
			break;
		}
		result++;
	}
}
