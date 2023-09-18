#include <stdio.h>
#include <stdlib.h>

struct students
{
	char name[40];
	char address[40];
	int age;
};

typedef struct students student;

int main(void)
{
	FILE* fp1;

	student st1 = {"hong", "seoul", 30}, st2;			//object st1, st2

	if((fp1= fopen("basic.txt", "w")) == NULL)		//write mode
	{
		printf("cannot open file.\n");
		exit(1);
	}

	fprintf(fp1, "%s %s %d\n", st1.name, st1.address, st1.age);	//write to file
	fclose(fp1);

	if((fp1 = fopen("basic.txt", "r")) == NULL)		//read mode
	{
		printf("cannot open file(2).\n");
		exit(1);
	}

	fscanf(fp1, "%s %s %d\n", st2.name, st2.address, &st2.age);	//get content in file
	printf("name : %s, address : %s, age : %d\n\n", st2.name, st2.address, st2.age);	//print to dos

	fclose(fp1);
	return 0;
}
