#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n=0, i=0, j=0, k=0,num=0,index = 0, flag = 0;
	char a[20] = {0, };
	char arr[10][10] = {0, };
	char d;

	printf("num: ");
	scanf("%d", &num);
	printf("array: ");
	
		
	for(i = 0; i < num; i++)
	{
		scanf("%s",arr[i]);
	}


	for(i = 0; i < num; i++)
	{
		for(j = 0; j < strlen(arr[i]); j++)
		{
				if(arr[i][j] != arr[i][j+1])
				{
					for(k = j + 1; k < strlen(arr[i]); k++)
					{
						if(arr[i][j] == arr[j][k])
						{
							flag = 1;
							break;
						}
					}
				}
				if(flag == 1)
					break;			

			if(flag == 1)
				break;	

		}
		if(flag != 1)
			n++;
	}
	
	printf("output: %d\n",n);
		
								
	return 0;
}


	


