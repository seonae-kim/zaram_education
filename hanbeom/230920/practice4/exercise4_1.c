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
	
	size_t len1 = strlen(my_string) -1;
	size_t len2 = strlen(is_prefix) -1;

	if(len1 >= len2 && strncmp(my_string, is_prefix, len2) == 0)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
}
