#include<stdio.h>

int main()
{	
	int bin1 = 0, bin2 = 0;
	int sum = 0;
	int temp = 0;
	int digit = 1;
	int i = 0;

	printf("Please enter the binary num, bin1 : ");
	scanf("%d", &bin1);
	printf("Please enter the binary num, bin2 : ");
	scanf("%d", &bin2);

	sum = bin1 + bin2;

	while (sum / 10 != 0)
	{
		sum = sum / 10;
		digit++;
	}
	int arr[digit + 1];

	sum = bin1 + bin2;
	temp = sum;

	for (i = 0; i < digit + 1; i++)
	{
		if (temp % 10 == 2)
		{
			arr[digit - i] = 0;
			temp = temp - 2;
			temp = temp + 10 ;
		}

		else if (temp % 10 == 0 || temp % 10 == 1)
		{
			arr[digit - i] = (temp % 10);
		}

		else if (temp % 10 == 3)
		{
			arr[digit - i] = 1;	
			temp = temp - 2;
			temp = temp + 10;
		}
		temp = temp / 10;
	}

	if (arr[0] == 1)
	{
		printf("%d", arr[0]);
	}

	for (i = 1; i < digit + 1; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	return 0;
}




/*

	while (bin1 / 10 != 0)
	{
		arr_bin1[i] = bin1 % 10;
		bin1 = bin1 / 10;
		cnt1++;
		i++
	}
	cnt1++;
	printf("%d", cnt1);

	i = 0;
	while (bin2 / 10 != 0)
	{
		arr_bin2[i] = bin % 10;
		bin2 = bin2 / 10;
		cnt2++;
		i++
	}
	cnt2++;

	for (i = 0; i < cnt1; i++)
	{
		
	}

	deci_sum = bin1 + bin2;

	

	return 0;
}
*/
