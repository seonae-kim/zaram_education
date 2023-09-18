#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	int n = 4000;
	if((fp = fopen("basic.txt", "wb")) == NULL)		//when open binaryfile + "w"
	{
		printf("cannot open file\n");
		exit(1);
	}

	fwrite(&n, sizeof(int), 1, fp);		//fwrite, fread = when use binaryfile

	fclose(fp);
	return 0;



}

