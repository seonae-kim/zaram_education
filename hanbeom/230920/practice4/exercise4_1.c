#include <stdio.h>
#include <string.h>

int main()
{
	char my_string[50] = {0,};
	char is_prefix[50] = {0,};

	//const char* my_string;
	//const char* is_prefix;

	int result = 0;
	int count = 0;
	int i;
	fgets(my_string,sizeof(my_string),stdin);	//banana\n
	fgets(is_prefix,sizeof(is_prefix),stdin);	//ban\n
	
	printf("strncmp show %d", strncmp(my_string,is_prefix, 3));

	size_t len1 = strlen(my_string) -1;
	size_t len2 = strlen(is_prefix) -1;

	for(i =0; i < len1 ; i++)
	{
		printf("%c", my_string[i]); // b a n a n a
	}

}
