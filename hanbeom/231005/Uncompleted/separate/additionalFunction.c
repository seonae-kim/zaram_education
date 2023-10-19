#include "additionalFunction.h"

void calculateEndTime(struct Client* client, int k, struct tm* timeInfo)
{
	client[k].end_year = timeInfo->tm_year + 1900;
	client[k].end_month = timeInfo->tm_mon + 1 + (client[k].months);

	if (client[k].end_month > 12)
	{
		client[k].end_year += 1;
		client[k].end_month -= 12;
	}

	client[k].end_day = timeInfo->tm_mday;
	client[k].end_hour = timeInfo->tm_hour;
	client[k].end_min = timeInfo->tm_min;
}

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

int updateRemaingDays(struct Client* client, int k)
{
	 // get current time (timeInfo)
    time_t currentTime;			//currentTime's type is "time_t"
    time(&currentTime);			//use time function
    struct tm* timeInfo;		// tm= struct, timeInfo= struct pointer	
    timeInfo = localtime(&currentTime); // current time

	struct tm startTime, endTime;
	time_t startTimestamp, endTimestamp;

	//get startTime
	startTime.tm_year = timeInfo->tm_year - 1900;
	startTime.tm_mon = timeInfo->tm_mon - 1;
	startTime.tm_mday = timeInfo->tm_mday;
	startTime.tm_hour = timeInfo->tm_hour;
	startTime.tm_min = timeInfo->tm_min;
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

	return diffInDays;	//it is okay to same with CalculateRemainingDays?
}
