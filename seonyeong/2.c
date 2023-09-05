#include <stdio.h>

int main()
{
 
 int hour, minute;
 int nexthour, nextminute;
 printf("input : ");
 scanf("%d %d", &hour, &minute);

 int now  = hour*60+minute;
 int next = now + 35;

 if (next >= 1440){
	next -=1440;}

 nexthour = next/60;
 nextminute = next%60; 

 printf("output: %02d %02d\n ", nexthour, nextminute);
 return 0;
}
