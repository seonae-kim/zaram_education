#include <stdio.h>
#include <string.h>

int main()
{
	char my_string[50] = {0,};
	char is_prefix[50] = {0,};
	int result = 0;
	int count = 0;
	int i;
	fgets(my_string,sizeof(my_string),stdin);
	fgets(is_prefix,sizeof(is_prefix),stdin);
	
	size_t len = strlen(is_prefix);

	for(i =0; i < len -1; i++)
	{
		if(my_string[i] == is_prefix[i])
		{
			count++;
		}
	}
	if(count == i)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
}
