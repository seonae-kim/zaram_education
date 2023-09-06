#include <stdio.h>

int main()
{
	int arry[][5];
	int n=0;
	int max1=0, max2=0, max3=0, max4=0;
	int a=0;
	int j1=0, j2=0, j3=0, j4=0;


	printf("input");
	for(int  i = 0 ; i < 4 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			scanf("%d",&n);
			arry[i][j] = n;
		}
	}

	for(int i = 0 ; i < 4 ; i++)
	{
		if(arry[0][i] > max1)
		{
			max1 = arry[0][i];
			j1 = i;
			arry[0][i] = 0;
		}
	
		if(arry[1][i] > max2)
		{
			max2 =  arry[1][i];
			j2 = i;
			arry[1][i] = 0;
		}

		if(arry[2][i] > max3)
		{
			max3 =  arry[2][i];
			j3 = i;
			arry[2][i] = 0;
		}

		if(arry[3][i] > max4)
		{
			max4 =  arry[3][i];
			j4 = i;
			arry[3][i] = 0;
		}	
	}
	
	if(j1 == j2)
	{
		for(int i =0 ; i < 4 ; i++)
		{
			if(arry[0][i] > max12)
			{
				max12 =  arry[0][i];
			}
			if(arry[1][i] > max22)
			{
				max22 =  arry[1][i];
			}
		}
		if((max1 + max22) > (max2 + max12))
		{
			max1 = max12;
		}
	}

	if(j2 == j3)
	{
		for(int i =0 ; i < 4 ; i++)
		{
			if(arry[1][i] > max32)
			{
				max32 =  arry[0][i];
			}
			if(arry[1][i] > max22)
			{
				max22 =  arry[1][i];
			}
		}
		if((max1 + max22) > (max2 + max12))
		{
			max1 = max12;
		}
	}
	

	






/*	
	for(int i = 0 ; i < 4 ; i++)
	{
		if(max2 > max1)
		{
			a = max1;
			max1 = max2;
			max2 = a;
			
			a = j1;
			j1 = j2;
			j2 = a;	
		}

		if(max3> max1)
		{
			a = max1;
			max1 = max3;
			max3 = a;
			a = j1;
			j1 = j3;
			j3 = a;	
		}

		if(max4> max1)
		{
			a = max1;
			max1 = max4;
			max4 = a;
			a = j1;
			j1 = j4;
			j4 = a;	
		}
			
		if(max3 > max2)
		{
			a = max2;
			max2 = max3;
			max3 = a;
			a = j3;
			j2 = j3;
			j3 = a;	
		}

		if(max4 > max2)
		{
			a = max2;
			max2 = max4;
			max4 = a;
			a = j2;
			j2 = j4;
			j4 = a;	
		}
		
		if(max4 > max3)
		{
			a = max4;
			max3 = max4;
			max4 = a;
			a = j4;
			j3 = j4;
			j3 = a;	
		}
			
	}	
	
*/	















	return 0;	

}
