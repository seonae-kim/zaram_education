#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>

int main() 
{
    time_t currentTime;
    struct tm* timeInfo;

    time(&currentTime);

    timeInfo = localtime(&currentTime);

    printf("currenttime: %dy %dm %dd %dh %dm %ds\n",
        timeInfo->tm_year + 1900,  
        timeInfo->tm_mon + 1,      
        timeInfo->tm_mday,         
        timeInfo->tm_hour,         
        timeInfo->tm_min,          
        timeInfo->tm_sec);         

    return 0;
}
