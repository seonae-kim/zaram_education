#include <stdio.h>
#include <stdint.h>
#define MAX_NUMS 7 
int nums[MAX_NUMS];
uint32_t max_count = 0;

void functionA(uint32_t index, int number)
{
	uint32_t i;
	for(i = max_count; i>index;i--)
	{
		nums[i] = nums[i-1];
	}

	nums[index] = number;
	++max_count;
}

uint32_t max_count = 0;
void functionB(uint32_t index)
{
	uint32_t i ;
	for(i=index; i<max_count; i++)
	{
		nums[i] = nums[i+1];
	} 
	--max_count;		
}

int main(void)
{
	functionA(0,1);
	functionA(0,2);
	functionB(0);
	uint32_t i;
	for (i = 0; i < MAX_NUMS; i++)
	{
		printf("%d\n", nums[i]);
	}
	printf("maxcount: %d",max_count); 
	return 0;	
}

