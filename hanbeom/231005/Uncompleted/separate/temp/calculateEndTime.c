#include "calculateEndTime.h"

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
