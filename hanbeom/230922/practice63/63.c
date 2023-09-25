#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int solution(int i, int j, int k);


void main()
{

	int a, b, c;

	printf("input a:\n");
	scanf("%d", &a);

	printf("input b:\n");
	scanf("%d", &b);
	
	printf("input c:\n");
	scanf("%d", &c);

	int solutionanswer = solution(a, b, c);
	printf("solutionanswer is : %d\n", solutionanswer);
	
}


int solution(int i, int j, int k)
{
	int arr[50] = { 0, };
	int p;
	int count = 0;
	int countarr[50] = { 0, };
	int s;
	int x = 0;
	for (p = i; p <= j; p++)			
	{
		s =p;				
		while (s * 10 >= 10)
		{
			if (s % 10 == k)
			{
				count++;
			}
			s = s / 10;		
		}
		countarr[x] = count;
		count = 0;
		x++;
	}
	int result =0;
	for (p = 0; p < j - i +1; p++)
	{
		result +=  countarr[p];
	}
	return result;
}
