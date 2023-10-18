#include<stdio.h>
#include<string.h>

int main()
{
	char input_str[20] = {0};
	char prefix[10] = {0};
	// for loop
	int i = 0;

	int prefix_len = 0;
	// compare in series & matching
	int match = 0;

	printf("Please enter the input string : ");
	scanf("%s", input_str);

	printf("Please enter the prefix : ");
	scanf("%s", prefix);

	match = strncmp(input_str, prefix, strlen(prefix));

	if (match == 0)
	{
		printf("1\n");	
	}

	else if (match != 0)
	{
		printf("0\n");
	}

	return 0;
}
