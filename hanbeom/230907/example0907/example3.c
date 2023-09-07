#include <stdio.h>

int main() {

int i;
int num[10];
int result=1;
int max= -50;
int min= 10000;

for(i=0;i<3;i++) {
	scanf("%d", &num[i]);
	}

for(i=0;i<3;i++) {
	if(max<=num[i]) {
		max = num[i];
	}
	else
	{
		max= max;
	}

	if(min>=num[i]) {
		min = num[i];
	}
	else
	{
		min = min;
	}
}

for(i=1;i<max;i++) {
	if( (min < i) && (i < max) && (i % 2 == 0) ) {

	result = result * i;
	}
}
printf("%d", result);
}
