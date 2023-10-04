#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>

int main() 
{
    FILE* file;
    time_t currentTime;
    struct tm* timeInfo;
    char timeString[80]; 

    
    time(&currentTime);

    timeInfo = localtime(&currentTime);

    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeInfo);
    file = fopen("current_time.txt", "a");

    if (file == NULL)
    {
        printf("can't open file.\n");
        return 1;
    }
    
    fprintf(file, "current time: %s\n", timeString);
    fclose(file);

    printf("Success\n");

    return 0;
}
