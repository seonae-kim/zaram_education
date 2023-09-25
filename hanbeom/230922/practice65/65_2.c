#include <stdio.h>
#include <string.h>
int main()
{
	char mystring[100] = {0,};
	char pat[100] = {0,};
	char* startPtr = mystring;
	char* temp= startPtr;

	printf("input mystring:\n");
	fgets(mystring,sizeof(mystring),stdin);
	
	printf("input pat:\n");
	fgets(pat,sizeof(pat),stdin);

	size_t len1 = strlen(mystring) - 1;
	size_t len2 = strlen(pat) - 1;

	pat[len2] = '\0';
	char* ptr = strstr(mystring, pat);

	while(ptr != NULL)
	{
		temp = ptr;
		ptr = strstr(ptr+1, pat);
	}
	char* endPtr = temp +len2 -1;

	while (startPtr <= endPtr)
	{
		printf("%c", *startPtr);
		startPtr++;
	}
}
