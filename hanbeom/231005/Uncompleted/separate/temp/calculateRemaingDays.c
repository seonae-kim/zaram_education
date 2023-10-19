#include "calculateRemainingDays.h"

int calculateRemaingDays(struct Client* client, int k)
{
	struct tm startTime, endTime;
	time_t startTimestamp, endTimestamp;

	//get startTime
	startTime.tm_year = client[k].start_year - 1900;
	startTime.tm_mon = client[k].start_month - 1;
	startTime.tm_mday = client[k].start_day;
	startTime.tm_hour = client[k].start_hour;
	startTime.tm_min = client[k].start_min;
	startTime.tm_sec = 0;
	startTime.tm_isdst = -1;

	//get endTime
	endTime.tm_year = client[k].end_year - 1900;
	endTime.tm_mon = client[k].end_month - 1;
	endTime.tm_mday = client[k].end_day;
	endTime.tm_hour = client[k].end_hour;
	endTime.tm_min = client[k].end_min;
	endTime.tm_sec = 0;
	endTime.tm_isdst = -1;

	// change startTime, endTime to time type
	startTimestamp = mktime(&startTime);
	endTimestamp = mktime(&endTime);

	if (startTimestamp == -1 || endTimestamp == -1)
	{
		printf("it is error");
		return -1;
	}
	
	double diffInSeconds = difftime(endTimestamp, startTimestamp);
	int diffInDays = (int)(diffInSeconds / (60 * 60 * 24));

	return diffInDays;
}
