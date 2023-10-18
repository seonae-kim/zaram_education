#include<stdio.h>
#include<string.h>

int main()
{

	char myString[20] = {0};
	char pat[5] = {0};
	// length of result string
	int result_len = 0; 
	// for loop
	int i = 0;

	printf("Please enter the pat : ");
	scanf("%s", pat);

	printf("Please enter the myString : ");
	scanf("%s", myString);

	// in myString, to point the position of pat 
	char *ptr = strstr(myString, pat);
	char last_pat[20];

	// find the position of last 'pat' in myString 
	while (ptr != NULL)
	{
		strcpy(last_pat, ptr);
		ptr = strstr(ptr + 1, pat);
	}

	result_len = strlen(myString) - strlen(last_pat) + strlen(pat); 
	
	for (i = 0; i < result_len; i++)
	{
		printf("%c", myString[i]);
	}
	printf("\n");

	return 0;
}
