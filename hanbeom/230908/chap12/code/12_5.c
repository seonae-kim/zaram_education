#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()			//SEEK_SET : initial in file, SEEK_CUR: : current location in file, SEEK_END : end in file 
{
	FILE *fp;
	char str[10];

	if((fp=fopen("data.txt", "wb")) ==NULL)
	{
		printf("cannot open file.\n");
		exit(1);
	}

	fprintf(fp, "abcdefghij");			//write abcdefghij to file
	fclose(fp);

	if((fp = fopen("data.txt", "rb")) == NULL)	
	{
		printf("cannot open file.\n");
		exit(1);
	}

	fgets(str, 11, fp);	// get str in file 
	printf("str output : %s\n\n", str);		//output str to dos					//print ef

	fseek(fp, 4L, SEEK_SET);	// file pointer move from initial to forth		
	fgets(str, 3, fp);			// get 3 words in file
	printf("at forth, print 2 words : %s\n", str);	//print to dos				//print de

	fseek(fp, -3L, SEEK_CUR);	// file pointer move from initial to forth
	fgets(str, 5, fp);			
	printf("from current location, print 2 words: %s\n", str);					//print bcde
	fclose(fp);

	return 0;
}

//fgets include '\0'
