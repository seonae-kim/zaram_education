#include <stdio.h>
#include <string.h>

void CapitalLetters(char* str1);

int main()
{
	char str[30];

	fgets(str, sizeof(str), stdin);
	CapitalLetters(str);

	printf("%s", str);

}

void CapitalLetters(char* str1)
{
	int size;
	int i;
	size = strlen(str1) -1;			//abcd >> size = 4
	
	for (i = 0; i < size; i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			str1[i] -= 32;
		}
		else if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			str1[i] += 32;
		}
	}
}
