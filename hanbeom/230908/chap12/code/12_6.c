#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	fpos_t pos;		// pos = identifier
	char str[20];

	if((fp = fopen("example.cpp", "rb")) ==NULL)
	{
		printf("cannot open file.\n");
		exit(1);
	}

	fgetpos(fp, &pos);			//	//get identifier
	printf("pos = %ld\n", (long)pos);			//print pos

	fread(str, sizeof(char), 20, fp);		// store 20bytes to str
	
	printf("pos = %ld, str = %s\n", (long)pos, str);		//print pos

	pos = 300;

	if(fsetpos(fp, &pos) != 0)
		printf("fsetpos error\n");

	fread(str, sizeof(char), 20, fp);
	fgetpos(fp, &pos);				// get identifier

	printf("pos = %ld, str = %.30s\n", (long)pos, str);		//print pos
	fclose(fp);
	return 0;
}
