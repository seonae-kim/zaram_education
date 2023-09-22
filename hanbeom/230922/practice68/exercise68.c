#include <stdio.h>
#include <string.h>
int main()
{	
	char bin1[50];	
	char bin2[50];	
	int pow1 =1;
	int pow2 =1;
	int i;
	fgets(bin1,sizeof(bin1),stdin);			
	fgets(bin2,sizeof(bin2),stdin);			
	size_t len1= strlen(bin1) -1;
	size_t len2= strlen(bin2) -1;
	int num1 = 0;
	int num2 = 0;
	int num[100] = {0,};
	int count =0;

	for(i=0; i < len1- 1; i++)			
	{
		pow1 *= 2;
	}

	for(i = 0; i < len1; i++)		
	{
		num1 += (bin1[i] - '0') * pow1;
		pow1 /= 2;
	}
	
	for(i=0; i < len2- 1; i++)			
	{
		pow2 *= 2;
	}


	for(i = 0; i < len2; i++)		
	{
		num2 += (bin2[i] - '0') * pow2;
		pow2 /= 2;
	}

	int sum = num1 + num2;

	while(sum !=0)			
	{
		num[count] = sum % 2;				
		sum = sum /2;
		count++;
	}

	for(i =count -1 ; i >=0 ; i--)
	{
		printf("%d", num[i]);
	}
}
