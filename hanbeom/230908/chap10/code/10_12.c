#include <stdio.h>
#include <ctype.h>	//추가

int main()
{
	char* pC = "c language";
	
	while (*pC)
	{
		printf("%c", toupper(*pC++));
	}
	printf("\n");
}