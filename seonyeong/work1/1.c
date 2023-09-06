#include <stdio.h>

int main()
{

 int number[10];
 int i,min,max;

 printf("input: ");
 
 for (i=0; i<10; i++){
 scanf("%d",&number[i]);
}
 
min=max=number[0];

for (i=1; i<10; i++){
	if (number[i] < min){
	min = number[i]; }

	if (number[i] > max){
	 max =  number[i];
 }
}

 printf("Max:%d\n", max);
 printf("Min:%d\n", min);
 
	return 0;
 
}


