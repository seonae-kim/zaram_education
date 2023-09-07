#include <stdio.h>
#include <string.h>

int main() {

char input[3];

scanf("%s", input);

if (strcmp(input, "yes") == 0) {
	printf("yes");
}

else {
	printf("fail");
}

}

