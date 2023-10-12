#include<stdio.h>

int main()
{
	FILE *fp;
	char str[20] = {0};
	fp = fopen("time.txt", "r");
	while (fgets(str, 100, fp) != NULL)
	{	
		printf("%s", str);
	}
	fclose(fp);

//	printf("%s\n", str);
	return 0;
}
