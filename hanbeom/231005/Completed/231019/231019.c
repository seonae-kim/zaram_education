#include "client_manager.h"

int calculateRemainingDays(struct Client* client, int k, int isUpdate)  //plus
{
    struct tm endTime;
    time_t endTimestamp;

    endTime.tm_year = client[k].end_year - 1900;
    endTime.tm_mon = client[k].end_month - 1;
    endTime.tm_mday = client[k].end_day;
    endTime.tm_hour = client[k].end_hour;
    endTime.tm_min = client[k].end_min;
    endTime.tm_sec = 0;
    endTime.tm_isdst = -1;

    time_t currentTime;
    time(&currentTime);
    struct tm* timeInfo;
    timeInfo = localtime(&currentTime);

    struct tm startTime;
    time_t startTimestamp;

    if (isUpdate) {
        // Use the current time for the start time in case of an update
        startTime = *timeInfo;
    } else {
        startTime.tm_year = client[k].start_year - 1900;
        startTime.tm_mon = client[k].start_month - 1;
        startTime.tm_mday = client[k].start_day;
        startTime.tm_hour = client[k].start_hour;
        startTime.tm_min = client[k].start_min;
        startTime.tm_sec = 0;
        startTime.tm_isdst = -1;
    }

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