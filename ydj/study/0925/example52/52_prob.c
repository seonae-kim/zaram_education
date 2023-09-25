#include<stdio.h>

int main()
{
	int hp = 0;
	int num_5 = 0, num_3 = 0, num_1 = 0;
	int total_num = 0;

	printf("Please enter the hp : ");
	scanf("%d", &hp);

	num_5 = hp / 5;
	num_3 = (hp % 5) / 3;
	num_1 = ((hp % 5) % 3) / 1;

	total_num = num_5 + num_3 + num_1;

	printf("%d\n", total_num);
	return 0;
}
