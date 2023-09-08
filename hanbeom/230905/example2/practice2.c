#include <stdio.h>

int main(void)
{
	int hour, minute;

	scanf("%d %d", &hour, &minute);

	int after_hour;
	int after_minute = minute + 35;

	if (after_minute >= 60) {
		after_hour = hour + 1;
		after_minute = after_minute - 60;
	}

	if (after_hour >= 24) {
		after_hour = after_hour - 24;
	}

	
	printf("%d %d", after_hour, after_minute); 

}
