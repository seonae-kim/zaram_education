#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
	char str[500];
	int result;
	int i;

	fgets(str, sizeof(str), stdin);
	int len = strlen(str);	
	for (int i = 0; i < len; i++)
		if (str[i] > 47 && str[i] < 58)			//0은 아스키코드값 48, 9는 아스키코드값 57
			printf("%c", str[i]);
}
